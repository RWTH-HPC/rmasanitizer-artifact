/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file SHMEMRMAWrapper.cpp
 *       @see must::SHMEMRMAWrapper.
 *
 *  @date 15.12.2023
 *  @author Simon Schwitanski
 */

#include "GtiMacros.h"
#include "SHMEMRMAWrapper.h"
#include "MustEnums.h"
#include "MustDefines.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <system_error>
#include <unistd.h>
#include "PrefixedOstream.hpp"

#include <sstream>
#include <fstream>

using namespace must;

mGET_INSTANCE_FUNCTION(SHMEMRMAWrapper)
mFREE_INSTANCE_FUNCTION(SHMEMRMAWrapper)
mPNMPI_REGISTRATIONPOINT_FUNCTION(SHMEMRMAWrapper)

SHMEMRMAWrapper::SHMEMRMAWrapper(const char* instanceName)
    : ModuleBase<SHMEMRMAWrapper, I_SHMEMRMAWrapper>(instanceName)
{
    // create sub modules
    std::vector<I_Module*> subModInstances;
    subModInstances = createSubModuleInstances();

    // handle sub modules
#define NUM_SUBMODULES 5
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
    myLIdMod = (I_LocationAnalysis*)subModInstances[1];
    myRMASan = (I_RMASanitize*)subModInstances[2];
    myTeamMod = (I_ShmemTeamTrack*)subModInstances[3];
    mySegmentMod = (I_ShmemSegmentTrack*)subModInstances[4];

    getWrapAcrossFunction("passAtomicSetAcross", (GTI_Fct_t*)&myPassAtomicSetAcrossFunc);
}

GTI_ANALYSIS_RETURN SHMEMRMAWrapper::init(MustParallelId pId)
{
    defaultSegment =
        myRMASan->allocSegment(mySegmentMod->getDefaultSegment(pId)->getBaseAddress(), 0);

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN SHMEMRMAWrapper::addDefaultContext(MustShmemCtxType ctx)
{
    // TODO: Add team support
    myDefaultContext = ctx;
    myContextMap[ctx] = myContextMap.size() + 1;
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN SHMEMRMAWrapper::addContext(MustShmemCtxType ctx)
{
    // TODO: Add team support
    myContextMap[ctx] = myContextMap.size() + 1;
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
SHMEMRMAWrapper::Alloc(void* allocPtr, std::size_t size)
{
#ifdef MUST_DEBUG
    cout << "[SHMEMRMAWrapper] shmemAlloc( allocPtr = " << allocPtr << ",\n"
         << "            size     = " << size << " )" << std::endl;
#endif

    if (allocPtr == nullptr)
        return GTI_ANALYSIS_FAILURE;

    MustShmemAllocId id = shmemNextAllocId();

    myShmemAllocMap.insert(
        std::make_pair(id, std::make_pair(reinterpret_cast<uintptr_t>(allocPtr), size)));

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
SHMEMRMAWrapper::Realloc(void* newPtr, void* oldPtr, std::size_t size)
{
#ifdef MUST_DEBUG
    cout << "[SHMEMRMAWrapper] shmemRealloc( newPtr = " << newPtr << ",\n"
         << "              oldPtr = " << oldPtr << ",\n"
         << "              size   = " << size << " )" << std::endl;
#endif

    if (newPtr == nullptr)
        return GTI_ANALYSIS_FAILURE;

    if (oldPtr != nullptr)
        Free(oldPtr);

    return Alloc(newPtr, size);
}

GTI_ANALYSIS_RETURN
SHMEMRMAWrapper::Calloc(void* allocPtr, size_t count, size_t size)
{
#ifdef MUST_DEBUG
    cout << "[SHMEMRMAWrapper] shmemCalloc( allocPtr = " << allocPtr << ",\n"
         << "             count    = " << count << ",\n"
         << "             size     = " << size << " )" << std::endl;
#endif

    return Alloc(allocPtr, count * size);
}

GTI_ANALYSIS_RETURN
SHMEMRMAWrapper::Free(void* freePtr)
{
#ifdef MUST_DEBUG
    cout << "[SHMEMRMAWrapper] shmemFree( freePtr = " << freePtr << " )" << std::endl;
#endif

    for (auto it = myShmemAllocMap.begin(); it != myShmemAllocMap.end(); ++it) {
        if (it->second.first == reinterpret_cast<uintptr_t>(freePtr)) {
            myShmemAllocMap.erase(it);
            return GTI_ANALYSIS_SUCCESS;
        }
    }

    return GTI_ANALYSIS_FAILURE;
}

MustShmemAllocId SHMEMRMAWrapper::shmemGetAllocId(const uintptr_t basePtr)
{
    for (auto ptrSizePair : myShmemAllocMap) {
        const uintptr_t allocPtr = ptrSizePair.second.first;
        const size_t allocSize = ptrSizePair.second.second;
        if (allocPtr >= basePtr && basePtr <= (allocPtr + allocSize))
            return ptrSizePair.first;
    }

    return 0;
}

const SHMEMRMAWrapper::ShmemTrackAlloc& SHMEMRMAWrapper::shmemGetAlloc(const MustShmemAllocId id)
{
#ifdef MUST_DEBUG
    cout << "[SHMEMRMAWrapper] getAlloc( id = " << id << " )" << std::endl;
#endif

    return myShmemAllocMap.at(id);
}

GTI_ANALYSIS_RETURN SHMEMRMAWrapper::Get(
    MustParallelId pId,
    MustLocationId lId,
    void* dest,
    void* source,
    ptrdiff_t destStride,
    ptrdiff_t sourceStride,
    size_t numElem,
    size_t sizeElem,
    int type,
    int target,
    void* ann,
    bool isBlocking,
    MustShmemCtxType ctx)
{
#ifdef MUST_DEBUG
    cout << "[SHMEMRMAWrapper] Get" << std::endl;
#endif
    addRMAAccess(
        pId,
        lId,
        source,
        dest,
        sourceStride,
        destStride,
        numElem,
        sizeElem,
        type,
        target,
        ann,
        isBlocking,
        false,
        false,
        ctx);

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN SHMEMRMAWrapper::Put(
    MustParallelId pId,
    MustLocationId lId,
    void* dest,
    void* source,
    ptrdiff_t destStride,
    ptrdiff_t sourceStride,
    size_t numElem,
    size_t sizeElem,
    int type,
    int target,
    void* ann,
    bool isBlocking,
    MustShmemCtxType ctx)
{
#ifdef MUST_DEBUG
    cout << "[SHMEMRMAWrapper] Put" << std::endl;
#endif
    addRMAAccess(
        pId,
        lId,
        dest,
        source,
        destStride,
        sourceStride,
        numElem,
        sizeElem,
        type,
        target,
        ann,
        isBlocking,
        true,
        false,
        ctx);

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN SHMEMRMAWrapper::WriteTeam(
    MustParallelId pId,
    MustLocationId lId,
    void* dest,
    void* source,
    size_t numElem,
    size_t sizeElem,
    int type,
    MustShmemTeamType team,
    void* ann)
{
    I_ShmemTeam* teamInfo = myTeamMod->getTeam(pId, team);

    assert(teamInfo != NULL);

    auto mapping = teamInfo->getGroup()->getMapping();

    // In a shmem collective routine, *all* processes write to the dest memory location of *all*
    // PEs. Sending from each PE a remote accesss to each other PE will lead to races between those
    // accesses. Therefore, we only send a remote access from the current PE P to P+1.
    int nextRank = (myPIdMod->getInfoForId(pId).rank + 1) % mapping.size();
    addRMAAccess(
        pId,
        lId,
        dest,
        source,
        1,
        1,
        numElem,
        sizeElem,
        type,
        mapping[nextRank],
        ann,
        true,
        true,
        false,
        myDefaultContext);

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN SHMEMRMAWrapper::AtomicFetch(
    MustParallelId pId,
    MustLocationId lId,
    void* dest,
    void* source,
    std::size_t sizeElem,
    int type,
    int target,
    bool isBlocking,
    void* ann,
    MustShmemCtxType ctx)
{
    // pass atomic access information across

#ifdef MUST_DEBUG
    cout << "[SHMEMRMAWrapper] AtomicFetch" << std::endl;
#endif
    addRMAAccess(
        pId,
        lId,
        source,
        dest,
        0,
        0,
        1,
        sizeElem,
        type,
        target,
        ann,
        isBlocking,
        false,
        true,
        ctx);

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN SHMEMRMAWrapper::AtomicSet(
    MustParallelId pId,
    MustLocationId lId,
    void* dest,
    std::size_t sizeElem,
    int type,
    int target,
    void* ann,
    MustShmemCtxType ctx)
{
#ifdef MUST_DEBUG
    cout << "[SHMEMRMAWrapper] AtomicSet" << std::endl;
#endif
    MustRMAId rmaId = addRMAAccess(
        pId,
        lId,
        dest,
        nullptr,
        0,
        0,
        1,
        sizeElem,
        type,
        target,
        ann,
        true,
        true,
        true,
        ctx);

    I_ShmemSegment* segment = mySegmentMod->getSegment(pId, mySegmentMod->findSegment(pId, dest));
    myRMASan->targetNotify(
        pId,
        lId,
        myContextMap[ctx],
        (MustAddressType)dest - segment->getBaseAddress(),
        rmaId,
        target);

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
SHMEMRMAWrapper::waitUntil(
    MustParallelId pId,
    MustLocationId lId,
    MustAddressType addr,
    uint64_t value)
{
#ifdef MUST_DEBUG
    cout << "[SHMEMRMAWrapper] WaitUntil" << std::endl;
#endif

    I_ShmemSegment* segment =
        mySegmentMod->getSegment(pId, mySegmentMod->findSegment(pId, (void*)addr));
    myRMASan->targetWait(
        pId,
        lId,
        myContextMap[myDefaultContext],
        (MustAddressType)addr - segment->getBaseAddress());

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
SHMEMRMAWrapper::fence(MustParallelId pId, MustLocationId lId, MustShmemCtxType ctx)
{
    myRMASan->epochMarker(myContextMap[ctx]);
    return GTI_ANALYSIS_SUCCESS;
}

MustRMAId SHMEMRMAWrapper::addRMAAccess(
    MustParallelId pId,
    MustLocationId lId,
    void* dest,
    void* source,
    ptrdiff_t destStride,
    ptrdiff_t sourceStride,
    size_t numElem,
    size_t sizeElem,
    int type,
    int target,
    void* ann,
    bool isBlocking,
    bool isStore,
    bool isAtomic,
    MustShmemCtxType ctx)
{
    MustRMAId rmaId = myRMASan->nextRMAId();

    RMAMemIntervals localAddrs = calcIntervalList(source, numElem, sizeElem, sourceStride);
    myRMASan->addLocalAccess(
        pId,
        lId,
        target,
        rmaId,
        defaultSegment,
        myContextMap[ctx],
        localAddrs,
        rmaId,
        !isStore,
        ann);

    // TODO: fix to work with arbitrary segments
    RMAMemIntervals remoteAddrs = calcIntervalList(
        (void*)((MustAddressType)dest - mySegmentMod->getDefaultSegment(pId)->getBaseAddress()),
        numElem,
        sizeElem,
        destStride);
    myRMASan->addRemoteAccess(
        pId,
        lId,
        target,
        rmaId,
        defaultSegment,
        myContextMap[ctx],
        remoteAddrs,
        type,
        sizeElem,
        rmaId,
        isAtomic,
        isStore,
        ann);

    if (isBlocking) {
        // blocking operations immediatley complete locally
        myRMASan->localComplete(pId, lId, rmaId);
    }

    return rmaId;
}

GTI_ANALYSIS_RETURN SHMEMRMAWrapper::originCompletion(MustParallelId pId, MustLocationId lId)
{
#ifdef MUST_DEBUG
    cout << "[SHMEMRMAWrapper] originCompletion" << std::endl;
#endif
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN SHMEMRMAWrapper::targetCompletion(MustParallelId pId, MustLocationId lId)
{
#ifdef MUST_DEBUG
    cout << "[SHMEMRMAWrapper] targetCompletion" << std::endl;
#endif
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
SHMEMRMAWrapper::originCompletionTeam(
    MustParallelId pId,
    MustLocationId lId,
    MustShmemTeamType team,
    MustShmemCtxType ctx)
{
#ifdef MUST_DEBUG
    cout << "[SHMEMRMAWrapper] originCompletionTeam" << std::endl;
#endif
    I_ShmemTeam* teamInfo = myTeamMod->getTeam(pId, team);

    assert(teamInfo != NULL);

    myRMASan
        ->localBulkComplete(pId, lId, myContextMap[ctx], false, teamInfo->getGroup()->getMapping());

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
SHMEMRMAWrapper::targetCompletionTeam(
    MustParallelId pId,
    MustLocationId lId,
    MustShmemTeamType team,
    MustShmemCtxType ctx)
{
#ifdef MUST_DEBUG
    cout << "[SHMEMRMAWrapper] targetCompletionTeam" << std::endl;
#endif

    I_ShmemTeam* teamInfo = myTeamMod->getTeam(pId, team);

    assert(teamInfo != NULL);

    myRMASan
        ->originRemoteBulkComplete(pId, lId, myContextMap[ctx], teamInfo->getGroup()->getMapping());
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
SHMEMRMAWrapper::bulkTargetCompletionAll(
    MustParallelId pId,
    MustLocationId lId,
    MustShmemTeamType team,
    MustShmemCtxType ctx)
{
#ifdef MUST_DEBUG
    cout << "[SHMEMRMAWrapper] bulkTargetCompletionAll" << std::endl;
#endif

    I_ShmemTeam* teamInfo = myTeamMod->getTeam(pId, team);

    assert(teamInfo != NULL);

    myRMASan->bulkCollectiveRemoteComplete(
        pId,
        lId,
        myContextMap[ctx],
        teamInfo->getGroup()->getMapping());

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN SHMEMRMAWrapper::receiveAtomicSet(
    MustParallelId pId,
    MustLocationId lId,
    MustShmemSegmentType segmentId,
    uint64_t contextId,
    uint64_t offset,
    int target)
{
    I_ShmemSegment* seg = mySegmentMod->getSegment(target, segmentId);
    // store target address and corresponding origin as potential synchronizing access
    MustAddressType targetAddr = (MustAddressType)seg->getBaseAddress() + (MustAddressType)offset;

    // TODO: clean up map at a certain point
    myAtomicAccessPEMap[targetAddr] = {myPIdMod->getInfoForId(pId).rank, contextId};

    return GTI_ANALYSIS_SUCCESS;
}

//=============================
// calcIntervalList
//=============================
RMAMemIntervals
SHMEMRMAWrapper::calcIntervalList(void* addr, size_t numElem, size_t sizeElem, ptrdiff_t stride)
{
    std::vector<std::pair<MustAddressType, size_t>> remoteAddrs;
    remoteAddrs.emplace_back(std::make_pair((MustAddressType)addr, numElem * sizeElem));
    return remoteAddrs;
}

SHMEMRMAWrapper::~SHMEMRMAWrapper(void)
{
    if (myRMASan)
        destroySubModuleInstance((I_Module*)myRMASan);
    myRMASan = NULL;
}
