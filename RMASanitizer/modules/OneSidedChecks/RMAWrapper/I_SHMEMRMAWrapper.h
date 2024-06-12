/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file I_SHMEMRMAWrapper.h
 *       @see I_SHMEMRMAWrapper
 *
 *  @date 15.12.2023
 *  @author Simon Schwitanski
 */

#include "GtiEnums.h"
#include "I_Module.h"

#include "MustEnums.h"
#include "BaseIds.h"
#include "MustTypes.h"

#ifndef I_SHMEMRMAWrapper_H
#define I_SHMEMRMAWrapper_H

/**
 * Interface for an RMA operation tracking module.
 *
 * Dependencies (in listed order):
 * - ParallelIdAnalysis
 * - CreateMessage
 * - ArgumentAnalysis
 * - DatatypeTrack
 * - RequestTrack
 * - WinTrack
 */
class I_SHMEMRMAWrapper : public gti::I_Module
{
  public:
    virtual gti::GTI_ANALYSIS_RETURN init(MustParallelId pId) = 0;

    virtual gti::GTI_ANALYSIS_RETURN addDefaultContext(MustShmemCtxType ctx) = 0;

    virtual gti::GTI_ANALYSIS_RETURN addContext(MustShmemCtxType ctx) = 0;

    /**
     * @brief Tracks collective OpenSHMEM allocations.
     *
     * @param allocPtr Pointer returned by allocation.
     * @param size Size of allocation.
     * @return gti::GTI_ANALYSIS_RETURN
     */
    virtual gti::GTI_ANALYSIS_RETURN Alloc(void* allocPtr, std::size_t size) = 0;

    /**
     * @brief Tracks collective OpenSHMEM reallocations.
     *
     * @param newPtr Pointer returned by reallocation.
     * @param oldPtr Old pointer passed to shmem_realloc.
     * @param size Size of new allocation.
     * @return gti::GTI_ANALYSIS_RETURN
     */
    virtual gti::GTI_ANALYSIS_RETURN Realloc(void* newPtr, void* oldPtr, std::size_t size) = 0;

    /**
     * @brief Tracks collective OpenSHMEM reallocations.
     *
     * @param newPtr Pointer returned by reallocation.
     * @param count Number of elements.
     * @param size Size of elements.
     * @return gti::GTI_ANALYSIS_RETURN
     */
    virtual gti::GTI_ANALYSIS_RETURN
    Calloc(void* allocPtr, std::size_t count, std::size_t size) = 0;

    /**
     * @brief Tracks the collective free of an OpenSHMEM allocation.
     *
     * @param freePtr Pointer to be freed.
     * @return gti::GTI_ANALYSIS_RETURN
     */
    virtual gti::GTI_ANALYSIS_RETURN Free(void* freePtr) = 0;

    /**
     * Wrap shmem get RMA operations.
     * @param pId Parallel id for call context.
     * @param lId Location id of the given call.
     * @param dest Local address of the data object to be updated
     * @param source Symmetric address of the source data object.
     * @param destStride The stride between consecutive elements of the dest array.
     * @param sourceStride The stride between consecutive elements of the source array.
     * @param numElem Number of elements in the dest and source arrays.
     * @param sizeElem Size of the elements being accessed.
     * @param type data type of the access
     * @param target Id of the target PE.
     * @param ann TSan handle.
     * @param isBlocking Boolean to indicate whether an operation is blocking.
     * @param context SHMEM context of the call (if applicable)
     * @return see gti::GTI_ANALYSIS_RETURN.
     */
    virtual gti::GTI_ANALYSIS_RETURN
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
        MustShmemCtxType ctx) = 0;

    /**
     * Wrap shmem put RMA operations.
     * @param pId Parallel id for call context.
     * @param lId Location id of the given call.
     * @param dest Symmetric address of the data object to be updated
     * @param source Local address of the source data object.
     * @param destStride The stride between consecutive elements of the dest array.
     * @param sourceStride The stride between consecutive elements of the source array.
     * @param numElem Number of elements in the dest and source arrays.
     * @param sizeElem Size of the elements being accessed.
     * @param type data type of the access
     * @param target Id of the target PE.
     * @param ann TSan handle.
     * @param isBlocking Boolean to indicate whether an operation is blocking.
     * @param context SHMEM context of the call (if applicable)
     */
    virtual gti::GTI_ANALYSIS_RETURN
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
        MustShmemCtxType ctx) = 0;

    /**
     * Wrap shmem collective operations.
     *
     * @param pId Parallel id for call context.
     * @param lId Location id of the given call.
     * @param dest Symmetric address of the data object to be updated
     * @param source Local address of the source data object.
     * @param numElem Number of elements in the dest and source arrays.
     * @param sizeElem Size of the elements being accessed.
     * @param type data type of the access
     * @param team id of the SHMEM team
     * @param ann TSan handle.
     */
    virtual gti::GTI_ANALYSIS_RETURN WriteTeam(
        MustParallelId pId,
        MustLocationId lId,
        void* dest,
        void* source,
        size_t numElem,
        size_t sizeElem,
        int type,
        MustShmemTeamType team,
        void* ann) = 0;

    /**
     * Wrap the fetch of a blocking atomic OpenSHMEM RMA
     * operation and adds it to the tracking infrastructure
     * @param pId Parallel id for call context.
     * @param lId Location id of the given call.
     * @param dest Local address of the data object to be updated.
     * @param source Symmetric address of the source data object.
     * @param sizeElem Size of the elements being accessed.
     * @param target Id of the target PE.
     * @param isBlocking Boolean to indicate whether an operation is blocking.
     * @param ann TSan handle.
     * @param context SHMEM context of the call (if applicable)
     * @return gti::GTI_ANALYSIS_RETURN
     */
    virtual gti::GTI_ANALYSIS_RETURN AtomicFetch(
        MustParallelId pId,
        MustLocationId lId,
        void* dest,
        void* source,
        std::size_t sizeElem,
        int type,
        int target,
        bool isBlocking,
        void* ann,
        MustShmemCtxType ctx) = 0;

    /**
     * Wrap the set of a blocking atomic OpenSHMEM RMA operation
     *
     * @param pId Parallel id for call context.
     * @param lId Location id of the given call.
     * @param dest Symmetric address of the data object to be updated.
     * @param sizeElem Size of the elements being accessed.
     * @param target Id of the target PE.
     * @param ann TSan handle.
     * @param context SHMEM context of the call (if applicable)
     * @return gti::GTI_ANALYSIS_RETURN
     */
    virtual gti::GTI_ANALYSIS_RETURN AtomicSet(
        MustParallelId pId,
        MustLocationId lId,
        void* dest,
        std::size_t sizeElem,
        int type,
        int target,
        void* ann,
        MustShmemCtxType ctx) = 0;

    /**
     * Wrap shmem_wail_until.
     *
     * @param pId Parallel id for call context.
     * @param lId Location id of the given call.
     * @param addr Checked address
     * @param value Expected value
     * @return gti::GTI_ANALYSIS_RETURN
     */
    virtual gti::GTI_ANALYSIS_RETURN
    waitUntil(MustParallelId pId, MustLocationId lId, MustAddressType addr, uint64_t value) = 0;

    /**
     * Wrap shmem_fence.
     * @param pId Parallel id for call context.
     * @param lId Location id of the given call.
     * @param context Context on which fence is called
     */
    virtual gti::GTI_ANALYSIS_RETURN
    fence(MustParallelId pId, MustLocationId lId, MustShmemCtxType ctx) = 0;

    /**
     * Wraps origin completion calls on single PE.
     *
     * @param pId Parallel id for call context.
     * @param lId Location id of the given call.
     * @return gti::GTI_ANALYSIS_RETURN
     */
    virtual gti::GTI_ANALYSIS_RETURN originCompletion(MustParallelId pId, MustLocationId lId) = 0;

    /**
     * Wraps target completion calls on single PE.
     *
     * @param pId Parallel id for call context.
     * @param lId Location id of the given call.
     * @return gti::GTI_ANALYSIS_RETURN
     */
    virtual gti::GTI_ANALYSIS_RETURN targetCompletion(MustParallelId pId, MustLocationId lId) = 0;

    /**
     * Wraps origin completion call on team.
     *
     * @param pId Parallel id for call context.
     * @param lId Location id of the given call.
     * @param team Associated SHMEM team
     * @param context SHMEM context of the call (if applicable)
     * @return gti::GTI_ANALYSIS_RETURN
     */
    virtual gti::GTI_ANALYSIS_RETURN originCompletionTeam(
        MustParallelId pId,
        MustLocationId lId,
        MustShmemTeamType team,
        MustShmemCtxType ctx) = 0;

    /**
     * Wraps target completion call on team.
     *
     * @param pId Parallel id for call context.
     * @param lId Location id of the given call.
     * @param team Associated SHMEM team
     * @param context SHMEM context of the call (if applicable)
     * @return gti::GTI_ANALYSIS_RETURN
     */
    virtual gti::GTI_ANALYSIS_RETURN targetCompletionTeam(
        MustParallelId pId,
        MustLocationId lId,
        MustShmemTeamType team,
        MustShmemCtxType ctx) = 0;

    /**
     * Wraps barrier_all calls.
     *
     * @param pId Parallel id for call context.
     * @param lId Location id of the given call.
     * @param team Associated SHMEM team
     * @param context SHMEM context of the call (if applicable)
     * @return gti::GTI_ANALYSIS_RETURN
     */
    virtual gti::GTI_ANALYSIS_RETURN bulkTargetCompletionAll(
        MustParallelId pId,
        MustLocationId lId,
        MustShmemTeamType team,
        MustShmemCtxType ctx) = 0;

    /**
     * Receives an atomic set operation from another process. This may trigger target remote
     * completion.
     *
     * @param pId Parallel id for call context.
     * @param lId Location id of the given call.
     * @param segmentId SHMEM segment ID
     * @param contextId SHMEM context ID
     * @param offset Offset from base address in segment ID
     * @param target target PE
     */
    virtual gti::GTI_ANALYSIS_RETURN receiveAtomicSet(
        MustParallelId pId,
        MustLocationId lId,
        MustShmemSegmentType segmentId,
        uint64_t contextId,
        uint64_t offset,
        int target) = 0;

}; /*class I_SHMEMRMAWrapper */

#endif /*I_SHMEMRMAWrapper_H*/
