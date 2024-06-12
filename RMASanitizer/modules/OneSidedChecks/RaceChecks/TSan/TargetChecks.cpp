/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file TargetChecks.cpp
 *       @see must::TargetChecks.
 *
 *  @date 15.12.2023
 *  @author Simon Schwitanski
 */

#include "GtiMacros.h"
#include "TargetChecks.h"
#include "MustEnums.h"
#include "MustDefines.h"
#include "pnmpi/service.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "PrefixedOstream.hpp"

#include <sstream>
#include <fstream>

using namespace must;

mGET_INSTANCE_FUNCTION(TargetChecks)
mFREE_INSTANCE_FUNCTION(TargetChecks)
mPNMPI_REGISTRATIONPOINT_FUNCTION(TargetChecks)

//=============================
// Constructor.
//=============================
TargetChecks::TargetChecks(const char* instanceName)
    : ModuleBase<TargetChecks, I_TargetChecks>(instanceName)
{
    // create sub modules
    std::vector<I_Module*> subModInstances;
    subModInstances = createSubModuleInstances();

    // handle sub modules
#define NUM_SUBMODULES 11
    if (subModInstances.size() < NUM_SUBMODULES) {
        std::cerr << "Module has not enough sub modules, check its analysis specification! ("
                  << __FILE__ << "@" << __LINE__ << ")" << std::endl;
        assert(0);
    }
    if (subModInstances.size() > NUM_SUBMODULES) {
        for (std::vector<I_Module*>::size_type i = NUM_SUBMODULES; i < subModInstances.size(); i++)
            destroySubModuleInstance(subModInstances[i]);
    }

    PNMPI_modHandle_t handle_dummy;
    if (PNMPI_Service_GetModuleByName("libTSanMessages", &handle_dummy) == PNMPI_SUCCESS)
        myHasTSanMessages = true;
    else
        myHasTSanMessages = false;

    myPIdMod = (I_ParallelIdAnalysis*)subModInstances[0];
    myLogger = (I_CreateMessage*)subModInstances[1];
    myConsts = (I_BaseConstants*)subModInstances[2];
    myDatMod = (I_DatatypeTrack*)subModInstances[3];
    myReqMod = (I_RequestTrack*)subModInstances[4];
    myLIdMod = (I_LocationAnalysis*)subModInstances[5];
    myWinMod = (I_WinTrack*)subModInstances[6];
    myTSanMod = (I_TSan*)subModInstances[7];
    myRMASan = (I_RMASanitize*)subModInstances[8];
    myTSanSyncClockRecorder = (I_TSanSyncClockRecorder*)subModInstances[9];
    myVCMod = (I_VectorClock*)subModInstances[10];
}

GTI_ANALYSIS_RETURN TargetChecks::winCreate(MustWinType win, void* ann)
{

    myWinLockAddrs[win] = ann;
    myWinCreateAddrs[win] = ann;

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN TargetChecks::winLock(
    MustParallelId pId,
    MustLocationId lId,
    int lock_type,
    int rank,
    MustWinType win,
    void* ann)
{
    int realRank = translateRank(myWinMod->getWin(pId, win)->getComm(), rank);

    if (lock_type == MPI_LOCK_EXCLUSIVE) {
        // if this is a local win lock, store TSan annotation address
        if (realRank == myPIdMod->getInfoForId(pId).rank) {
            cout << "insert (win " << win << "): " << ann << std::endl;
            myWinLockAddrs[win] = ann;
        }
    }

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN TargetChecks::targetOpStart(MustRMAId rmaId)
{
    I_TargetRMAOpPersistent* op = myRMASan->getPersistentTargetRMAOp(rmaId);

    // resolve clock value to TSan sync clock
    if (op->getOrigin() == op->getTarget()) {
        // Special case 1: Local call, the call itself is the earliest point in terms of
        // synchronization, so get its sync clock.
        op->setFiber(myRMASan->getOriginRMAOp(rmaId)->getFiber());
    } else if (op->getClock() == 0) {
        // Special case 2: If origin clock is 0, both processes never synchronized, so we take the
        // segment creation function as start of the concurrent region.
        op->setFiber(myRMASan->getSegmentAnn(op->getSegmentId()));
        // op->setFiber(myWinCreateAddrs[op->getSegmentId()]);
    } else {
        // Usual case: Get TSan sync clock from clock value
        op->setFiber(myTSanSyncClockRecorder->getTSanSyncClock(op->getClock()));
    }

#ifdef MUST_DEBUG
    std::stringstream msg;
    msg << "[TargetChecks] TargetRMAOp STARTED: ";
    op->print(msg);
    msg << std::endl;
    cout << msg.str();
#endif

    return GTI_ANALYSIS_SUCCESS;
}

/**
 * @see I_TargetChecks::targetOpComplete
 */
GTI_ANALYSIS_RETURN TargetChecks::targetOpComplete(
    MustParallelId pId,
    MustLocationId lId,
    MustRMAId* rmaId,
    int rmaIdLen)
{
#ifdef MUST_DEBUG
    cout << "[TargetChecks] " << rmaIdLen << " TARGET OPS COMPLETED" << std::endl;
#endif
    // get current fiber to switch back at the end
    myTSanMod->annotateHappensBefore(pId, lId, rmaId);
    void* curFiber = myTSanMod->getCurrentFiber();

    for (int i = 0; i < rmaIdLen; ++i) {
        I_TargetRMAOp* op = myRMASan->getTargetRMAOp(rmaId[i]);

        // Get location ID that represents the start of the concurrent region
        // If the target operation is from another process, we get the start
        // of the concurrent region. If the target operation is from the process
        // itself, then the concurrent region starts at the operation itself, so
        // we get that location ID.
        MustLocationId opLId;
        if (op->getOrigin() != op->getTarget()) {
            opLId = myTSanSyncClockRecorder->getLId(op->getClock());
        } else {
            opLId = op->getLId();
        }

        // save annotated RMA op in annotation history
        RMAOpHistoryData history = {
            rmaId[i],
            op->isAtomic(),
            op->getRMAEpoch(),
            op->getTargetDatatype(),
            op->getTargetDatatypeSize(),
            op->getMemIntervals()[0].first,
            opLId,
            lId,
            op->getStartVectorClock(),
            op->getEndVectorClock()};
        myRMAAnnotationHistory[op->getOrigin()].add(history);

#ifdef MUST_DEBUG
        std::stringstream msg;
        msg << "[TargetChecks] TargetRMAOp COMPLETED: ";
        op->print(msg);
        msg << std::endl;
        cout << msg.str();
#endif
        // select fiber
        void* tempFiber;

        // if (op->getFiber() == nullptr) {
        //     cerr << "Skip TargetRMAOp from rank " << op->getOrigin() << " with unknown start
        //     point."
        //          << std::endl;
        //     return GTI_ANALYSIS_SUCCESS;
        // }

        if (myFiberPool.find(op->getOrigin()) != myFiberPool.end()) {
            // fiber already created for origin rank
            tempFiber = myFiberPool[op->getOrigin()];
        } else {
            // create new fiber for origin rank
            myTSanMod->annotateIgnoreSyncBegin();
            tempFiber = myTSanMod->createFiber(0);

            char procName[32];
            snprintf(procName, 32, "rank %d", op->getOrigin());
            myTSanMod->setFiberName(tempFiber, procName);

            myFiberPool.insert(std::make_pair(op->getOrigin(), tempFiber));
            myTSanMod->annotateIgnoreSyncEnd();
        }

        // switch to fiber of operation without synchronization (flag: 1)
        myTSanMod->switchToFiber(tempFiber, 1);

        // load corresponding vector clock
        myTSanMod->annotateHappensAfter(pId, lId, op->getFiber());

        // ignore any synchronization implied while annotating mem access (otherwise we might run
        // into false negatives due to usage of safeptr etc.)
        myTSanMod->annotateIgnoreSyncBegin();

        this->annotateMetadataEnter(op->getPId(), op->getLId(), rmaId[i]);

        // annotate atomic accesses separately
        annotateMemAccess(
            op->getPId(),
            op->getLId(),
            op->getMemIntervals(),
            op->isStore(),
            op->getReturnAddr(),
            op->getFunctionAddr());

        this->annotateMetadataExit();

        myTSanMod->annotateIgnoreSyncEnd();
    }

    // switch to current thread *with* synchronization
    // (memory accesses afterwards do *not* conflict with *this* RMA call)
    myTSanMod->annotateHappensBefore(pId, lId, rmaId);
    myTSanMod->switchToFiber(curFiber, 0);
    myTSanMod->annotateHappensAfter(pId, lId, rmaId);

    return GTI_ANALYSIS_SUCCESS;
}

//=============================
// annotateMemAccess
//=============================
void TargetChecks::annotateMemAccess(
    MustParallelId pId,
    MustLocationId lId,
    const RMAMemIntervals& memIntervals,
    bool isStore,
    const void* returnAddr,
    const void* funcAddr)
{
    for (const auto& elem : memIntervals) {
        auto start = elem.first;
        auto size = elem.second;

#ifdef MUST_DEBUG
        std::stringstream msg;
        msg << "[" << start << "," << start + size - 1 << "]" << std::endl;
        msg << "[" << (void*)start << "," << (void*)(start + size - 1) << "]" << std::endl;
        cout << msg.str();
#endif
        // Increment function address by one here, because TSan expects a return address and
        // decrements the pointer by one.
        if (isStore)
            myTSanMod->annotateMemoryWritePC(
                pId,
                lId,
                start,
                size,
                (char*)(myTSanMod->translateCallPtr(funcAddr)) + 1);
        else
            myTSanMod->annotateMemoryReadPC(
                pId,
                lId,
                start,
                size,
                (char*)(myTSanMod->translateCallPtr(funcAddr)) + 1);
    }
}

//=============================
// extractBasetype
//=============================
MustMpiDatatypePredefined TargetChecks::extractBasetype(I_Datatype* datatype)
{
    MustTypesigType typesig = datatype->getTypesig();

    // set type to first basetype in entry
    MustMpiDatatypePredefined type = typesig.front().second;

    for (MustTypesigType::iterator it = typesig.begin(); it != typesig.end(); ++it) {
        // check that all basetypes are the same
        if (type != it->second && type != MUST_MPI_LB && type != MUST_MPI_UB)
            return MUST_MPI_DATATYPE_UNKNOWN;
    }

    return type;
}

//=============================
// annotateFuncEntry
//=============================
void TargetChecks::annotateMetadataEnter(MustParallelId pId, MustLocationId lId, MustRMAId rmaId)
{
    myTSanMod->annotateFuncEntry(pId, lId);
    if (myHasTSanMessages) {
        // Encode RMA id, pId and lId in TSan stacktrace reports by marking them with a special
        // delimiter 0x0FFFFFFFFFFFFFFF such that we can detect that a race with an annotated call
        // has been detected. This allows us to extract the RMA id, pId and lId later on when
        // interpreting the TSan report.
        myTSanMod->annotateFuncEntry((void*)lId);
        myTSanMod->annotateFuncEntry((void*)pId);
        myTSanMod->annotateFuncEntry((void*)rmaId);
        myTSanMod->annotateFuncEntry((void*)0x0FFFFFFFFFFFFFFF);
    }
}

//=============================
// annotateFuncExit
//=============================
void TargetChecks::annotateMetadataExit()
{
    myTSanMod->annotateFuncExit();
    if (myHasTSanMessages) {
        myTSanMod->annotateFuncExit();
        myTSanMod->annotateFuncExit();
        myTSanMod->annotateFuncExit();
        myTSanMod->annotateFuncExit();
    }
}

//=============================
// translateRank
//=============================
int TargetChecks::translateRank(I_Comm* comm, int rank)
{
    int ret;
    if (rank != myConsts->getAnySource()) {
        if (!comm->isIntercomm())
            comm->getGroup()->translate(rank, &ret);
        else
            comm->getRemoteGroup()->translate(rank, &ret);
    } else {
        ret = rank;
    }

    return ret;
}

//=============================
// isRace
//=============================
bool TargetChecks::isRace(
    MustParallelId pId1,
    MustRMAId rmaId1,
    MustParallelId pId2,
    MustRMAId rmaId2)
{
    auto rank1 = myPIdMod->getInfoForId(pId1).rank;
    auto rank2 = myPIdMod->getInfoForId(pId2).rank;

    RMAOpHistoryData op1;
    RMAOpHistoryData op2;
    if (!myRMAAnnotationHistory[rank1].find(rmaId1, op1)) {
        cout << "Error: Could not find RMA access history for operation " << rmaId1 << " from rank "
             << rank1 << std::endl;
    }
    if (!myRMAAnnotationHistory[rank2].find(rmaId2, op2)) {
        cout << "Error: Could not find RMA access history for operation " << rmaId2 << " from rank "
             << rank2 << std::endl;
    }

    // In order to be a safe pair of atomic accesses, the types should be
    // 1) both atomic
    // 2) have the same datatype
    // 3) the startAddress difference should be a multiple of the type size, otherwise we have
    // overlaping accesses because the types would overlap)
    if (op1.isAtomic && op2.isAtomic && op1.type == op2.type &&
        (op1.startAddr - op2.startAddr) % op1.typeSize == 0) {
        // atomic access, same atomic datatypes

        return false;
    }

    // If access windows of operations are disjoint, this access is safe
    if (op1.startClock.size() > 0 && op2.endClock.size() > 0 && op1.endClock < op2.startClock ||
        op2.endClock < op1.startClock) {
        return false;
    }

    return true;
}

bool TargetChecks::getHistoryData(MustParallelId pId, MustRMAId rmaId, RMAOpHistoryData& op)
{
    auto rank = myPIdMod->getInfoForId(pId).rank;
    return myRMAAnnotationHistory[rank].find(rmaId, op);
}

//=============================
// Destructor.
//=============================
TargetChecks::~TargetChecks(void)
{
    if (myPIdMod)
        destroySubModuleInstance((I_Module*)myPIdMod);
    myPIdMod = NULL;

    if (myLogger)
        destroySubModuleInstance((I_Module*)myLogger);
    myLogger = NULL;

    if (myConsts)
        destroySubModuleInstance((I_Module*)myConsts);
    myConsts = NULL;

    if (myDatMod)
        destroySubModuleInstance((I_Module*)myDatMod);
    myDatMod = NULL;

    if (myReqMod)
        destroySubModuleInstance((I_Module*)myReqMod);
    myReqMod = NULL;

    if (myWinMod)
        destroySubModuleInstance((I_Module*)myWinMod);
    myWinMod = NULL;

    if (myTSanMod)
        destroySubModuleInstance((I_Module*)myTSanMod);
    myTSanMod = NULL;

    if (myRMASan)
        destroySubModuleInstance((I_Module*)myRMASan);
    myRMASan = NULL;

    if (myTSanSyncClockRecorder)
        destroySubModuleInstance((I_Module*)myTSanSyncClockRecorder);
    myTSanSyncClockRecorder = NULL;
}
