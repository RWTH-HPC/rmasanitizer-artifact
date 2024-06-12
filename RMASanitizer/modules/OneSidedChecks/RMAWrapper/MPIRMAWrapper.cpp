/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file MPIRMAWrapper.cpp
 *       @see must::MPIRMAWrapper.
 *
 *  @date 15.12.2023
 *  @author Simon Schwitanski
 */

#include "GtiMacros.h"
#include "MPIRMAWrapper.h"
#include "MustEnums.h"
#include "MustDefines.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <system_error>
#include <unistd.h>
#include <PrefixedOstream.hpp>

#include <sstream>
#include <fstream>

using namespace must;

mGET_INSTANCE_FUNCTION(MPIRMAWrapper)
mFREE_INSTANCE_FUNCTION(MPIRMAWrapper)
mPNMPI_REGISTRATIONPOINT_FUNCTION(MPIRMAWrapper)

//=============================
// Constructor.
//=============================
MPIRMAWrapper::MPIRMAWrapper(const char* instanceName)
    : ModuleBase<MPIRMAWrapper, I_MPIRMAWrapper>(instanceName)
{
    // create sub modules
    std::vector<I_Module*> subModInstances;
    subModInstances = createSubModuleInstances();

    // handle sub modules
#define NUM_SUBMODULES 8
    if (subModInstances.size() < NUM_SUBMODULES) {
        std::cerr << "Module has not enough sub modules, check its analysis specification! ("
                  << __FILE__ << "@" << __LINE__ << ")" << std::endl;
        assert(0);
    }
    if (subModInstances.size() > NUM_SUBMODULES) {
        for (std::vector<I_Module*>::size_type i = NUM_SUBMODULES; i < subModInstances.size(); i++)
            destroySubModuleInstance(subModInstances[i]);
    }

    myPIdMod = (I_ParallelIdAnalysis*)subModInstances[0];
    myRMASan = (I_RMASanitize*)subModInstances[1];
    myConsts = (I_BaseConstants*)subModInstances[2];
    myDatMod = (I_DatatypeTrack*)subModInstances[3];
    myReqMod = (I_RequestTrack*)subModInstances[4];
    myGrpMod = (I_GroupTrack*)subModInstances[5];
    myOpMod = (I_OpTrack*)subModInstances[6];
    myWinMod = (I_WinTrack*)subModInstances[7];
}

GTI_ANALYSIS_RETURN MPIRMAWrapper::init(void) { return GTI_ANALYSIS_SUCCESS; }

//=============================
// Get
//=============================
GTI_ANALYSIS_RETURN MPIRMAWrapper::Get(
    MustParallelId pId,
    MustLocationId lId,
    MustAddressType originaddr,
    int origincount,
    MustDatatypeType origintype,
    int target,
    int targetdisp,
    int targetcount,
    MustDatatypeType targettype,
    MustWinType win,
    MustRequestType requesttype,
    void* ann)
{
#ifdef MUST_DEBUG
    cout << "[MPIRMAWrapper] MPIRMAWrapper - Get" << std::endl;
#endif
    addRMAAccess(
        pId,
        lId,
        originaddr,
        origincount,
        origintype,
        target,
        targetdisp,
        targetcount,
        targettype,
        win,
        requesttype,
        ann,
        false, // isStore
        false  // isAtomic
    );

    return GTI_ANALYSIS_SUCCESS;
}

//=============================
// Put
//=============================
GTI_ANALYSIS_RETURN MPIRMAWrapper::Put(
    MustParallelId pId,
    MustLocationId lId,
    MustAddressType originaddr,
    int origincount,
    MustDatatypeType origintype,
    int target,
    int targetdisp,
    int targetcount,
    MustDatatypeType targettype,
    MustWinType win,
    MustRequestType requesttype,
    void* ann)

{
#ifdef MUST_DEBUG
    cout << "[MPIRMAWrapper] MPIRMAWrapper - Put" << std::endl;
#endif
    addRMAAccess(
        pId,
        lId,
        originaddr,
        origincount,
        origintype,
        target,
        targetdisp,
        targetcount,
        targettype,
        win,
        requesttype,
        ann,
        true, // isStore
        false // isAtomic
    );
    return GTI_ANALYSIS_SUCCESS;
}

//=============================
// calcIntervalList
//=============================
RMAMemIntervals MPIRMAWrapper::calcIntervalList(
    MustDatatypeType datatype,
    MustParallelId pId,
    MustAddressType buffer,
    int count)
{
    I_Datatype* typeinfo = myDatMod->getDatatype(pId, datatype);
    assert(typeInfo != NULL);

    BlockInfo& blockInfo = typeinfo->getBlockInfo();
    MustAddressType extent = typeinfo->getExtent();
    MustAddressType size = typeinfo->getSize();
    MustMemIntervalListType memIntervals = buildMemIntervallist(
        blockInfo,
        extent,
        size,
        buffer,
        (MustRequestType)0,
        true,
        typeinfo,
        count,
        buffer);

    std::vector<std::pair<MustAddressType, size_t>> remoteAddrs;

    // return empty list if nothing to calculate
    if (count == 0) {
        return remoteAddrs;
    }

    for (MustMemIntervalListType::iterator it = memIntervals.begin(); it != memIntervals.end();
         ++it) {
        for (int i = 0; i < it->count; ++i) {
            MustAddressType start = it->baseAddress + (it->stride * i);
#ifdef MUST_DEBUG
            std::stringstream msg;
            msg << "[" << start << "," << start + it->blocksize << "]" << std::endl;
            msg << "[" << (void*)start << "," << (void*)(start + it->blocksize) << "]" << std::endl;
            cout << msg.str();
#endif
            remoteAddrs.emplace_back(std::make_pair(start, it->blocksize));
        }
    }

    return remoteAddrs;
}

//=============================
// Accumulate
//=============================
GTI_ANALYSIS_RETURN MPIRMAWrapper::Accumulate(
    MustParallelId pId,
    MustLocationId lId,
    MustAddressType originaddr,
    int origincount,
    MustDatatypeType origintype,
    int target,
    int targetdisp,
    int targetcount,
    MustDatatypeType targettype,
    MustOpType op,
    MustWinType win,
    MustRequestType requesttype,
    void* ann)
{
#ifdef MUST_DEBUG
    cout << "[MPIRMAWrapper] Accumulate" << std::endl;
#endif

    addRMAAccess(
        pId,
        lId,
        originaddr,
        origincount,
        origintype,
        target,
        targetdisp,
        targetcount,
        targettype,
        win,
        requesttype,
        ann,
        true, // isStore
        true  // isAtomic
    );

    return GTI_ANALYSIS_SUCCESS;
}

//=============================
// GetAccumulate
//=============================
GTI_ANALYSIS_RETURN MPIRMAWrapper::GetAccumulate(
    MustParallelId pId,
    MustLocationId lId,
    MustAddressType originaddr,
    int origincount,
    MustDatatypeType origintype,
    MustAddressType resultaddr,
    int resultcount,
    MustDatatypeType resulttype,
    int target,
    int targetdisp,
    int targetcount,
    MustDatatypeType targettype,
    MustOpType op,
    MustWinType win,
    MustRequestType requesttype,
    void* ann)
{
#ifdef MUST_DEBUG
    cout << "[MPIRMAWrapper] GetAccumulate" << std::endl;
#endif
    // Note: We have two RMA operations here: MPI_Get and MPI_Accumulate, both are atomic on the
    // basic elements. For simplicity in handling, we split them in two separate RMA operations.
    addRMAAccess(
        pId,
        lId,
        resultaddr,
        resultcount,
        resulttype,
        target,
        targetdisp,
        targetcount,
        targettype,
        win,
        requesttype,
        ann,
        false, // isStore
        true   // isAtomic
    );

    // if the atomic operation uses MPI_NO_OP, then we just read the target location,
    // otherwise we write something to the target location
    I_Op* op_info = myOpMod->getOp(pId, op);
    bool isStore = !op_info->isPredefined() || op_info->getPredefinedInfo() != MUST_MPI_OP_NO_OP;

    addRMAAccess(
        pId,
        lId,
        originaddr,
        origincount,
        origintype,
        target,
        targetdisp,
        targetcount,
        targettype,
        win,
        requesttype,
        ann,
        isStore, // isStore
        true     // isAtomic
    );

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN MPIRMAWrapper::addRMAAccess(
    MustParallelId pId,
    MustLocationId lId,
    MustAddressType originaddr,
    int origincount,
    MustDatatypeType origintype,
    int target,
    int targetdisp,
    int targetcount,
    MustDatatypeType targettype,
    MustWinType win,
    MustRequestType requesttype,
    void* ann,
    bool isStore,
    bool isAtomic)
{
    // no elements to work on, no operation required
    if (targetcount == 0) {
        return GTI_ANALYSIS_SUCCESS;
    }

    // check for MPI_PROC_NULL
    if (myConsts->isProcNull(target))
        return GTI_ANALYSIS_SUCCESS;

    // translate target rank to world comm
    int realTarget = translateRank(myWinMod->getWin(pId, win)->getComm(), target);

    MustRMAId rmaId = myRMASan->nextRMAId();

    // only add access to origin if there is an actual local buffer access
    if (origincount > 0) {
        RMAMemIntervals localAddrs = calcIntervalList(origintype, pId, originaddr, origincount);

        // local buffer read
        myRMASan->addLocalAccess(
            pId,
            lId,
            target,
            rmaId,
            winToSegment[win],
            winToSegment[win], // in MPI RMA, windows are also contexts
            localAddrs,
            requesttype,
            !isStore, // negate "isStore": remote store means local read / remote read means local
                      // store
            ann);
    }

    // base address is targetdisp * sizeof(datatype), we calculate offsets as memory intervals
    RMAMemIntervals remoteAddrs = calcIntervalList(
        targettype,
        pId,
        targetdisp * myWinMod->getWin(pId, win)->getDispUnit(),
        targetcount);

    // We currently only resolve to the first predefined data type for simplicity,
    // in the long term, we should pass the data type map and compare for equality.
    MustMpiDatatypePredefined realTargetType =
        myDatMod->getDatatype(pId, targettype)->getTypesig().front().second;

    // remote write
    myRMASan->addRemoteAccess(
        pId,
        lId,
        realTarget,
        rmaId,
        winToSegment[win],
        winToSegment[win], // in MPI RMA, windows are also contexts
        remoteAddrs,
        realTargetType, // TODO: Support for derived datatypes
        myDatMod->getDatatype(pId, targettype)->getSize(),
        requesttype,
        isAtomic, // atomic
        isStore,  // store
        ann);

    if (requesttype != 0) { // request-based operation
        reqToOps[requesttype].push_back(rmaId);
    }

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
MPIRMAWrapper::winLock(
    MustParallelId pId,
    MustLocationId lId,
    int lock_type,
    int rank,
    MustWinType win)
{
#ifdef MUST_DEBUG
    cout << "[MPIRMAWrapper] winLock" << std::endl;
#endif
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
MPIRMAWrapper::winUnlock(MustParallelId pId, MustLocationId lId, int rank, MustWinType win)
{
#ifdef MUST_DEBUG
    cout << "[MPIRMAWrapper] winUnlock" << std::endl;
#endif
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN MPIRMAWrapper::originCompletionAll(
    MustParallelId pId,
    MustLocationId lId,
    MustWinType win,
    int isLocalOnly,
    void* ann)
{
    const std::vector<int>& groupRanks =
        myWinMod->getWin(pId, win)->getComm()->getGroup()->getMapping();
    myRMASan->localBulkComplete(pId, lId, winToSegment[win], isLocalOnly, groupRanks);
#ifdef MUST_DEBUG
    cout << "[MPIRMAWrapper] originCompletionAll" << std::endl;
#endif
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN MPIRMAWrapper::originCompletionRank(
    MustParallelId pId,
    MustLocationId lId,
    int targetRank,
    MustWinType win,
    int isLocalOnly)
{
#ifdef MUST_DEBUG
    cout << "[MPIRMAWrapper] originCompletionRank" << std::endl;
#endif
    int realTarget = translateRank(myWinMod->getWin(pId, win)->getComm(), targetRank);
    const std::vector<int> groupRanks = {realTarget};
    myRMASan->localBulkComplete(pId, lId, winToSegment[win], isLocalOnly, groupRanks);

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
MPIRMAWrapper::activeTargetCompletionAll(
    MustParallelId pId,
    MustLocationId lId,
    MustWinType win,
    void* ann)
{
#ifdef MUST_DEBUG
    cout << "[MPIRMAWrapper] activeTargetCompletionAll" << std::endl;
#endif
    const std::vector<int>& groupRanks =
        myWinMod->getWin(pId, win)->getComm()->getGroup()->getMapping();
    myRMASan->bulkCollectiveRemoteComplete(pId, lId, winToSegment[win], groupRanks);
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN MPIRMAWrapper::winStart(
    MustParallelId pId,
    MustLocationId lId,
    MustGroupType group,
    MustWinType win,
    void* ann)
{
#ifdef MUST_DEBUG
    cout << "[MPIRMAWrapper] winStart" << std::endl;
#endif
    myWinCompleteGroupMap.insert(std::make_pair(win, group));

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
MPIRMAWrapper::winComplete(MustParallelId pId, MustLocationId lId, MustWinType win, void* ann)
{
#ifdef MUST_DEBUG
    cout << "[MPIRMAWrapper] winComplete" << std::endl;
#endif
    MustGroupType group = myWinCompleteGroupMap[win];
    I_GroupTable* groupTable = myGrpMod->getGroup(pId, group)->getGroup();
    myWinCompleteGroupMap.erase(win);
    int origin = myPIdMod->getInfoForId(pId).rank;

    for (auto const& rank : groupTable->getMapping()) {
        originCompletionRank(pId, lId, rank, win, false);
    }

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN MPIRMAWrapper::winPost(
    MustParallelId pId,
    MustLocationId lId,
    MustGroupType group,
    MustWinType win,
    void* ann)
{
#ifdef MUST_DEBUG
    cout << "[MPIRMAWrapper] winPost" << std::endl;
#endif
    myWinWaitGroupMap.insert(std::make_pair(win, group));

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
MPIRMAWrapper::winWait(MustParallelId pId, MustLocationId lId, MustWinType win, void* ann)
{
#ifdef MUST_DEBUG
    cout << "[MPIRMAWrapper] winWait" << std::endl;
#endif
    MustGroupType group = myWinWaitGroupMap[win];
    auto groupTable = myGrpMod->getGroup(pId, group)->getGroup()->getMapping();
    myWinWaitGroupMap.erase(win);
    int ownRank = myPIdMod->getInfoForId(pId).rank;

    myRMASan->targetRemoteComplete(pId, lId, winToSegment[win], groupTable);

    // Note: We wait for the synchronization with the VectorClock *before* we do the completion
    // analysis. However, then we would only annotate the received RMA operations with the *next*
    // synchronization and not with *this* MPI_Win_wait. We therefore have to manually annotate the
    // synchronization again.
    for (auto groupRank : groupTable) {
        myRMASan->receiveSync(groupRank, myPIdMod->getInfoForId(pId).rank);
    }

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
MPIRMAWrapper::passiveTargetCompletionAll(
    MustParallelId pId,
    MustLocationId lId,
    MustWinType win,
    void* ann)
{
#ifdef MUST_DEBUG
    cout << "[MPIRMAWrapper] passiveTargetCompletionAll" << std::endl;
#endif
    const std::vector<int>& groupRanks =
        myWinMod->getWin(pId, win)->getComm()->getGroup()->getMapping();
    myRMASan->originRemoteBulkComplete(pId, lId, winToSegment[win], groupRanks);
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN MPIRMAWrapper::passiveTargetCompletionRank(
    MustParallelId pId,
    MustLocationId lId,
    int targetRank,
    MustWinType win)
{
#ifdef MUST_DEBUG
    cout << "[MPIRMAWrapper] passiveTargetCompletionRank" << std::endl;
#endif
    int realTarget = translateRank(myWinMod->getWin(pId, win)->getComm(), targetRank);
    const std::vector<int> groupRanks = {realTarget};
    myRMASan->originRemoteBulkComplete(pId, lId, winToSegment[win], groupRanks);
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
MPIRMAWrapper::completedRequest(MustParallelId pId, MustLocationId lId, MustRequestType request)
{
    auto it = reqToOps.find(request);
    if (it != reqToOps.end()) {
        for (const auto& rmaId : it->second) {
            myRMASan->localComplete(pId, lId, rmaId);
        }
        reqToOps.erase(it);
    }
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
MPIRMAWrapper::completedRequests(
    MustParallelId pId,
    MustLocationId lId,
    MustRequestType* requests,
    int count)
{
    for (int i = 0; i < count; i++) {
        GTI_ANALYSIS_RETURN ret = completedRequest(pId, lId, requests[i]);
        if (ret != GTI_ANALYSIS_SUCCESS)
            return ret;
    }

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
MPIRMAWrapper::winCreate(MustWinType win, void* base, void* ann)
{
    winToSegment[win] = myRMASan->allocSegment((MustAddressType)base, ann);
    myRMASan->epochMarker(winToSegment[win]);
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
MPIRMAWrapper::winFree(MustWinType win)
{
    myRMASan->freeSegment(winToSegment[win]);
    winToSegment.erase(win);
    return GTI_ANALYSIS_SUCCESS;
}

//=============================
// translateRank
//=============================
int MPIRMAWrapper::translateRank(I_Comm* comm, int rank)
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
// Destructor.
//=============================
MPIRMAWrapper::~MPIRMAWrapper(void)
{
    if (myPIdMod)
        destroySubModuleInstance((I_Module*)myPIdMod);
    myPIdMod = NULL;

    if (myConsts)
        destroySubModuleInstance((I_Module*)myConsts);
    myConsts = NULL;

    if (myDatMod)
        destroySubModuleInstance((I_Module*)myDatMod);
    myDatMod = NULL;

    if (myReqMod)
        destroySubModuleInstance((I_Module*)myReqMod);
    myReqMod = NULL;

    if (myGrpMod)
        destroySubModuleInstance((I_Module*)myGrpMod);
    myGrpMod = NULL;

    if (myOpMod)
        destroySubModuleInstance((I_Module*)myOpMod);
    myOpMod = NULL;

    if (myWinMod)
        destroySubModuleInstance((I_Module*)myWinMod);
    myWinMod = NULL;

    if (myRMASan)
        destroySubModuleInstance((I_Module*)myRMASan);
    myRMASan = NULL;
}
