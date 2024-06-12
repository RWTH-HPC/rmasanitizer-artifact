/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file GASPIRMAWrapper.cpp
 *       @see must::GASPIRMAWrapper.
 *
 *  @date 15.12.2023
 *  @author Simon Schwitanski
 */

#include "GtiMacros.h"
#include "GASPIRMAWrapper.h"
#include "MustEnums.h"
#include "MustDefines.h"
#include "PrefixedOstream.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <system_error>
#include <unistd.h>
#include <GASPI.h>
#include <PGASPI.h>

#include <sstream>
#include <fstream>

using namespace must;

mGET_INSTANCE_FUNCTION(GASPIRMAWrapper)
mFREE_INSTANCE_FUNCTION(GASPIRMAWrapper)
mPNMPI_REGISTRATIONPOINT_FUNCTION(GASPIRMAWrapper)

GASPIRMAWrapper::GASPIRMAWrapper(const char* instanceName)
    : ModuleBase<GASPIRMAWrapper, I_GASPIRMAWrapper>(instanceName)
{
    // create sub modules
    std::vector<I_Module*> subModInstances;
    subModInstances = createSubModuleInstances();

    // handle sub modules
#define NUM_SUBMODULES 2
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

    getWrapAcrossFunction(
        "passGASPINotificationAcross",
        (GTI_Fct_t*)&myPassGASPINotificationAcrossFunc);
}

GTI_ANALYSIS_RETURN GASPIRMAWrapper::init(MustParallelId pId)
{
    myRank = myPIdMod->getInfoForId(pId).rank;
    // Get number of processes
    gaspi_rank_t numRanks;
    pgaspi_proc_num(&numRanks);

    // Fill vector with all ranks
    myNumRanks = numRanks;
    for (int i = 0; i < numRanks; ++i) {
        myAllRanks.push_back(i);
    }

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN GASPIRMAWrapper::SegmentAlloc(
    MustGASPISegmentIDType segmentId,
    MustGASPISizeType size,
    MustGASPIPointerType ptr)
{
    gaspiSegToSegment[segmentId] = {
        myRMASan->allocSegment((MustAddressType)ptr, NULL),
        (MustAddressType)ptr};
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
GASPIRMAWrapper::SegmentRegister(MustGASPISegmentIDType segmentId, MustGASPIRankType rank)
{
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN GASPIRMAWrapper::SegmentCreate(
    MustGASPISegmentIDType segmentId,
    MustGASPISizeType size,
    MustGASPIGroupType group,
    MustGASPIPointerType ptr)
{
    gaspiSegToSegment[segmentId] = {
        myRMASan->allocSegment((MustAddressType)ptr, NULL),
        (MustAddressType)ptr};
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN GASPIRMAWrapper::SegmentDelete(MustGASPISegmentIDType segmentId)
{
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN GASPIRMAWrapper::Access(
    MustParallelId pId,
    MustLocationId lId,
    MustGASPISegmentIDType segmentIdLocal,
    MustGASPIOffsetType offsetLocal,
    MustGASPIRankType rank,
    MustGASPISegmentIDType segmentIdRemote,
    MustGASPIOffsetType offsetRemote,
    MustGASPISizeType size,
    MustGASPIQueueIDType queue,
    int isStore,
    void* ann)
{
    MustRMAId rmaId = myRMASan->nextRMAId();

    RMAMemIntervals localAddrs;
    localAddrs.emplace_back(std::make_pair(
        (MustAddressType)gaspiSegToSegment[segmentIdLocal].second + offsetLocal,
        size));

    myRMASan->addLocalAccess(
        pId,
        lId,
        rank,
        rmaId,
        gaspiSegToSegment[segmentIdLocal].first,
        0,
        localAddrs,
        rmaId,
        !isStore,
        ann);

    RMAMemIntervals remoteAddrs;
    remoteAddrs.emplace_back(std::make_pair(0 + offsetRemote, size));

    myRMASan->addRemoteAccess(
        pId,
        lId,
        rank,
        rmaId,
        gaspiSegToSegment[segmentIdRemote].first,
        0,
        remoteAddrs,
        0,
        size,
        rmaId,
        false,
        isStore,
        ann);

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN GASPIRMAWrapper::AccessList(
    MustParallelId pId,
    MustLocationId lId,
    MustGASPINumberType num,
    MustGASPISegmentIDType* segmentIdLocal,
    MustGASPIOffsetType* offsetLocal,
    MustGASPIRankType rank,
    MustGASPISegmentIDType* segmentIdRemote,
    MustGASPIOffsetType* offsetRemote,
    MustGASPISizeType* size,
    MustGASPIQueueIDType queue,
    int isStore,
    void* ann)
{
    for (int i = 0; i < num; i++) {
        Access(
            pId,
            lId,
            segmentIdLocal[i],
            offsetLocal[i],
            rank,
            segmentIdRemote[i],
            offsetRemote[i],
            size[i],
            queue,
            isStore,
            ann);
    }

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN GASPIRMAWrapper::AtomicAccess(
    MustParallelId pId,
    MustLocationId lId,
    MustGASPISegmentIDType segmentId,
    MustGASPIOffsetType offset,
    MustGASPIRankType rank,
    size_t size)
{
    // atomic accesses in GASPI only perform remote accesses
    MustRMAId rmaId = myRMASan->nextRMAId();

    RMAMemIntervals remoteAddrs;
    remoteAddrs.emplace_back(std::make_pair(0 + offset, size));

    myRMASan->addRemoteAccess(
        pId,
        lId,
        rank,
        rmaId,
        gaspiSegToSegment[segmentId].first,
        0,
        remoteAddrs,
        0,
        size,
        rmaId,
        true, // isAtomic
        true, // isStore
        nullptr);

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
GASPIRMAWrapper::Wait(MustParallelId pId, MustLocationId lId, MustGASPIQueueIDType queue)
{
    myRMASan->localBulkComplete(pId, lId, 0, true, myAllRanks);
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
GASPIRMAWrapper::Barrier(MustParallelId pId, MustLocationId lId, MustGASPIGroupType group)
{
    // barrier does not provide any consistency
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
GASPIRMAWrapper::Notify(
    MustParallelId pId,
    MustLocationId lId,
    MustGASPIRankType rank,
    MustGASPINotificationIDType notification)
{
#ifdef MUST_DEBUG
    cout << "[GASPIRMAWrapper] Send notification " << notification << " to rank " << rank
         << std::endl;
#endif
    if (myPassGASPINotificationAcrossFunc)
        myPassGASPINotificationAcrossFunc(pId, lId, notification, myRank, rank);

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
GASPIRMAWrapper::NotifyWait(
    MustParallelId pId,
    MustGASPINotificationIDType notification,
    MustGASPINotificationIDType firstId)
{
    I_Place* placeMod;
    getPlaceMod(&placeMod);
#ifdef MUST_DEBUG
    cout << "[GASPIRMAWrapper] Wait for notification firstId=" << firstId << std::endl;
#endif
    // Check queue for notification of ranks
    while (myNotificationToRank[firstId].empty()) {
#ifdef MUST_DEBUG
        cout << "[GASPIRMAWrapper] Waiting for notification " << firstId << "..." << std::endl;
        sleep(1);
#endif
        // wait for notification to arrive
        placeMod->testIntralayer();
    }

    int remoteRank = myNotificationToRank[firstId].front();
    myNotificationToRank[firstId].pop();

#ifdef MUST_DEBUG
    cout << "[GASPIRMAWrapper] Notification " << firstId << " from " << remoteRank << std::endl;
#endif
    std::vector<int> remoteRanks = {remoteRank};
    myRMASan->targetRemoteComplete(pId, 0, 0, remoteRanks);
    myRMASan->receiveSync(remoteRank, myRank);

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN GASPIRMAWrapper::ReceiveNotification(
    MustParallelId pId,
    MustLocationId lId,
    MustGASPINotificationIDType notification,
    int origin)
{
#ifdef MUST_DEBUG
    cout << "[GASPIRMAWrapper] Receive notification " << notification << " from rank " << origin
         << std::endl;
#endif
    myNotificationToRank[notification].push(origin);
    return GTI_ANALYSIS_SUCCESS;
}

GASPIRMAWrapper::~GASPIRMAWrapper(void)
{
    if (myPIdMod)
        destroySubModuleInstance((I_Module*)myPIdMod);
    myPIdMod = NULL;

    if (myRMASan)
        destroySubModuleInstance((I_Module*)myRMASan);
    myRMASan = NULL;
}
