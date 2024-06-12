/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file OriginChecks.cpp
 *       @see must::OriginChecks.
 *
 *  @date 15.12.2023
 *  @author Simon Schwitanski
 */

#include "GtiMacros.h"
#include "OriginChecks.h"
#include "MustEnums.h"
#include "MustDefines.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <PrefixedOstream.hpp>

#include <sstream>
#include <fstream>

using namespace must;

mGET_INSTANCE_FUNCTION(OriginChecks)
mFREE_INSTANCE_FUNCTION(OriginChecks)
mPNMPI_REGISTRATIONPOINT_FUNCTION(OriginChecks)

//=============================
// Constructor.
//=============================
OriginChecks::OriginChecks(const char* instanceName)
    : ModuleBase<OriginChecks, I_OriginChecks>(instanceName)
{
    // create sub modules
    std::vector<I_Module*> subModInstances;
    subModInstances = createSubModuleInstances();

    // handle sub modules
#define NUM_SUBMODULES 9
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

    // Initialize module data

    // Create fiber pool
    myTSanMod->annotateIgnoreSyncBegin();
    for (int i = 0; i < FIBER_POOL_SIZE; ++i) {
        myFiberPool.push_back(myTSanMod->createFiber(0));
    }
    myTSanMod->annotateIgnoreSyncEnd();

    int fiberPoolCounter = 0;
}

/**
 * @see I_OriginChecks::originOpStart
 */
GTI_ANALYSIS_RETURN OriginChecks::originOpStart(MustRMAId rmaId)
{
    I_OriginRMAOp* op = myRMASan->getOriginRMAOp(rmaId);

#ifdef MUST_DEBUG
    cout << "[OriginChecks] ORIGIN OPS STARTED" << std::endl;
    op->print(cout);
#endif

    return GTI_ANALYSIS_SUCCESS;
}

/**
 * @see I_OriginChecks::originOpComplete
 */
GTI_ANALYSIS_RETURN OriginChecks::originOpComplete(
    MustParallelId pId,
    MustLocationId lId,
    MustRMAId* rmaId,
    int rmaIdLen)
{
#ifdef MUST_DEBUG
    cout << "[OriginChecks] " << rmaIdLen << " ORIGIN OPS COMPLETED" << std::endl;
#endif

    // get current fiber to switch back at the end
    void* curFiber = myTSanMod->getCurrentFiber();

    for (int i = 0; i < rmaIdLen; ++i) {
        I_OriginRMAOp* op = myRMASan->getOriginRMAOp(rmaId[i]);

#ifdef MUST_DEBUG
        cout << "[OriginChecks] ";
        op->print(cout);
        cout << std::endl;
#endif

        // select fiber from fiber pool (depending on origin rank)
        // TODO: reusing fibers might lead to false negatives.
        void* tempFiber = myFiberPool.at(fiberPoolCounter++ % FIBER_POOL_SIZE);

        // Switch to fiber of operation without synchronization (flag: 1)
        myTSanMod->switchToFiber(tempFiber, 1);
        // Load corresponding vector clock
        myTSanMod->annotateHappensAfter(pId, lId, op->getFiber());

        // Ignore any synchronization implied while annotating mem access (otherwise we might run
        // into false negatives due to usage of safeptr etc.)
        myTSanMod->annotateIgnoreSyncBegin();

        annotateMemAccess(
            op->getPId(),
            op->getLId(),
            op->getMemIntervals(),
            op->isStore(),
            op->getReturnAddr(),
            op->getFunctionAddr());

        myTSanMod->annotateIgnoreSyncEnd();

        // Switch to current thread *with* synchronization
        // (memory accesses afterwards do *not* conflict with *this* RMA call)
        // Note: This has to be done for every annotation of an RMA origin operation.
        void* myaddr = &pId;
        myTSanMod->annotateHappensBefore(pId, lId, myaddr);
        myTSanMod->switchToFiber(curFiber, 0);
        myTSanMod->annotateHappensAfter(pId, lId, myaddr);
    }

    return GTI_ANALYSIS_SUCCESS;
}

//=============================
// annotateMemAccess
//=============================
void OriginChecks::annotateMemAccess(
    MustParallelId pId,
    MustLocationId lId,
    const RMAMemIntervals& memIntervals,
    bool isStore,
    const void* returnAddr,
    const void* funcAddr)
{
    this->annotateFuncEntry(pId, lId);
    for (const auto& elem : memIntervals) {
        auto start = elem.first;
        auto size = elem.second;

#ifdef MUST_DEBUG
        std::stringstream msg;
        msg << "[OriginChecks] Memory access ";
        msg << "[" << start << "," << start + size << "], ";
        msg << "[" << (void*)start << "," << (void*)(start + size) << "]" << std::endl;
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
    this->annotateFuncExit();
}

//=============================
// annotateFuncEntry
//=============================
void OriginChecks::annotateFuncEntry(MustParallelId pId, MustLocationId lId)
{
    myTSanMod->annotateFuncEntry(pId, lId);
    if (myHasTSanMessages) {
        // Encode pId and lId in TSan stacktrace reports by marking them with a special delimiter
        // 0x0FFFFFFFFFFFFFFF such that we can detect that a race with an annotated call has been
        // detected. This allows us to extract the pId and lId later on when interpreting the TSan
        // report.
        myTSanMod->annotateFuncEntry((void*)lId);
        myTSanMod->annotateFuncEntry((void*)pId);
        myTSanMod->annotateFuncEntry((void*)0x000000000FFFFFFF); // empty delimiter for OriginChecks
        myTSanMod->annotateFuncEntry((void*)0x0FFFFFFFFFFFFFFF);
    }
}

//=============================
// annotateFuncExit
//=============================
void OriginChecks::annotateFuncExit()
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
// Destructor.
//=============================
OriginChecks::~OriginChecks(void)
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
}
