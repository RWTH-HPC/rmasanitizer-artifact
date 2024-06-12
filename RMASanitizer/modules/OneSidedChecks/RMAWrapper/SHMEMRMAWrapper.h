/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file SHMEMRMAWrapper.h
 *       @see must::SHMEMRMAWrapper.
 *
 *  @date 15.12.2023
 *  @author Simon Schwitanski
 */

#include "ModuleBase.h"
#include "I_ParallelIdAnalysis.h"
#include "I_BaseConstants.h"
#include "I_CreateMessage.h"
#include "I_DatatypeTrack.h"
#include "I_RequestTrack.h"
#include "I_WinTrack.h"
#include "I_TSan.h"
#include "I_LocationAnalysis.h"
#include "I_SHMEMRMAWrapper.h"
#include "I_RMASanitize.h"
#include "I_ShmemTeamTrack.h"
#include "I_ShmemSegmentTrack.h"
#include "OneSidedChecksApi.h"

#include <map>
#include <vector>

#ifndef SHMEMRMAWrapper_H
#define SHMEMRMAWrapper_H

using namespace gti;

typedef uint64_t MustShmemAllocId;

namespace must
{
/**
 * Wraps MPI RMA communication and consistency calls to abstract RMA race detection model
 */
class SHMEMRMAWrapper : public gti::ModuleBase<SHMEMRMAWrapper, I_SHMEMRMAWrapper>
{
  public:
    /**
     * Constructor.
     * @param instanceName name of this module instance.
     */
    SHMEMRMAWrapper(const char* instanceName);
    /**
     * Destructor.
     */
    virtual ~SHMEMRMAWrapper(void);

    gti::GTI_ANALYSIS_RETURN init(MustParallelId pId);

    /**
     * @see I_SHMEMRMAWrapper::shmemAlloc
     */
    gti::GTI_ANALYSIS_RETURN Alloc(void* allocPtr, std::size_t size);

    /**
     * @see I_SHMEMRMAWrapper::shmemRealloc
     */
    gti::GTI_ANALYSIS_RETURN Realloc(void* newPtr, void* oldPtr, std::size_t size);

    /**
     * @see I_SHMEMRMAWrapper::shmemRealloc
     */
    gti::GTI_ANALYSIS_RETURN Calloc(void* allocPtr, std::size_t count, std::size_t size);

    /**
     * @see I_SHMEMRMAWrapper::shmemFree
     */
    gti::GTI_ANALYSIS_RETURN Free(void* freePtr);

    /**
     * @see I_SHMEMRMAWrapper::Get
     */
    GTI_ANALYSIS_RETURN
    Get(MustParallelId pId,
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
        MustShmemCtxType ctx);

    /**
     * @see I_SHMEMRMAWrapper::Put
     */
    GTI_ANALYSIS_RETURN
    Put(MustParallelId pId,
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
        MustShmemCtxType ctx);

    GTI_ANALYSIS_RETURN WriteTeam(
        MustParallelId pId,
        MustLocationId lId,
        void* dest,
        void* source,
        size_t numElem,
        size_t sizeElem,
        int type,
        MustShmemTeamType team,
        void* ann);

    /**
     * @see I_SHMEMRMAWrapper::AtomicFetch
     */
    GTI_ANALYSIS_RETURN AtomicFetch(
        MustParallelId pId,
        MustLocationId lId,
        void* dest,
        void* source,
        std::size_t sizeElem,
        int type,
        int target,
        bool isBlocking,
        void* ann,
        MustShmemCtxType ctx);

    /**
     * @see I_SHMEMRMAWrapper::AtomicSet
     */
    GTI_ANALYSIS_RETURN AtomicSet(
        MustParallelId pId,
        MustLocationId lId,
        void* dest,
        std::size_t sizeElem,
        int type,
        int target,
        void* ann,
        MustShmemCtxType ctx);

    /**
     * @see I_SHMEMRMAWrapper::waitUntil
     */
    GTI_ANALYSIS_RETURN
    waitUntil(MustParallelId pId, MustLocationId lId, MustAddressType addr, uint64_t value);

    /**
     * @see I_SHMEMRMAWrapper::fence
     */
    GTI_ANALYSIS_RETURN
    fence(MustParallelId pId, MustLocationId lId, MustShmemCtxType ctx);

    /**
     * @see I_SHMEMRMAWrapper::originCompletion
     */
    GTI_ANALYSIS_RETURN originCompletion(MustParallelId pId, MustLocationId lId);

    /**
     * @see I_SHMEMRMAWrapper::targetCompletion
     */
    GTI_ANALYSIS_RETURN targetCompletion(MustParallelId pId, MustLocationId lId);

    /**
     * @see I_SHMEMRMAWrapper::originCompletionTeam
     */
    GTI_ANALYSIS_RETURN
    originCompletionTeam(
        MustParallelId pId,
        MustLocationId lId,
        MustShmemTeamType team,
        MustShmemCtxType ctx);

    /**
     * @see I_SHMEMRMAWrapper::targetCompletionTeam
     */
    GTI_ANALYSIS_RETURN
    targetCompletionTeam(
        MustParallelId pId,
        MustLocationId lId,
        MustShmemTeamType team,
        MustShmemCtxType ctx);

    /**
     * @see I_SHMEMRMAWrapper::bulkTargetCompletionAll
     */
    GTI_ANALYSIS_RETURN
    bulkTargetCompletionAll(
        MustParallelId pId,
        MustLocationId lId,
        MustShmemTeamType team,
        MustShmemCtxType ctx);

    /**
     * @see I_SHMEMRMAWrapper::receiveAtomicSet
     */
    GTI_ANALYSIS_RETURN receiveAtomicSet(
        MustParallelId pId,
        MustLocationId lId,
        MustShmemSegmentType segmentId,
        uint64_t contextId,
        uint64_t offset,
        int target);

  protected:
    I_ParallelIdAnalysis* myPIdMod;
    I_LocationAnalysis* myLIdMod;
    I_RMASanitize* myRMASan;
    I_ShmemTeamTrack* myTeamMod;
    I_ShmemSegmentTrack* mySegmentMod;

  private:
    MustShmemCtxType myDefaultContext;
    // Maps SHMEM context IDs to unique RMA Context IDs (the IDs local to a PE can be different
    // to the IDs on other PEs), this uniquely resolves them.
    // TODO: Add support for contexts from different teams
    std::unordered_map<MustShmemCtxType, RMAContextId> myContextMap;
    passAtomicSetAcrossP myPassAtomicSetAcrossFunc;
    typedef std::pair<std::uintptr_t, std::size_t> ShmemTrackAlloc;
    std::atomic<MustShmemAllocId> myShmemAllocId{1};
    std::map<MustShmemAllocId, ShmemTrackAlloc> myShmemAllocMap;
    std::unordered_map<MustAddressType, std::pair<int, MustAddressType>> myAtomicAccessPEMap;

    MustShmemAllocId shmemNextAllocId() { return myShmemAllocId.fetch_add(1); };

    GTI_ANALYSIS_RETURN addDefaultContext(MustShmemCtxType ctx);
    GTI_ANALYSIS_RETURN addContext(MustShmemCtxType ctx);

    /**
     * @brief Returns the id for the OpenSHMEM allocation
     *        which contains ptr.
     *
     * @param basePtr The base pointer of the accessed memory region.
     * @return must::MustShmemAllocId Id of associated allocation or 0.
     */
    MustShmemAllocId shmemGetAllocId(const std::uintptr_t basePtr);

    /**
     * @brief Returns the id for the OpenSHMEM allocation
     *        which contains ptr.
     *
     * @param id The base id of an OpenSHMEM allocation.
     * @return ShmemTrack::ShmemTrackAlloc Base pointerand size of the allocation.
     */
    const ShmemTrackAlloc& shmemGetAlloc(const MustShmemAllocId id);

    MustRMAId addRMAAccess(
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
        MustShmemCtxType ctx);

    RMAMemIntervals calcIntervalList(void* addr, size_t numElem, size_t sizeElem, ptrdiff_t stride);

    RMASegmentId defaultSegment{0}; // static and global variables implicitly form a segment

}; /*class SHMEMRMAWrapper*/

} /*namespace must*/

#endif /*SHMEMRMAWrapper_H*/
