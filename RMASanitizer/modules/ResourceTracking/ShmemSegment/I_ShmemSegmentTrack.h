/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file I_ShmemSegmentTrack.h
 *       @see I_ShmemSegmentTrack.
 *
 *  @date 30.12.2023
 *  @author Simon Schwitanski
 */

#include "I_Module.h"
#include "GtiEnums.h"

#include "MustEnums.h"
#include "MustTypes.h"
#include "BaseIds.h"
#include "I_ChannelId.h"
#include "I_GroupTrack.h"
#include "I_GroupTable.h"
#include "I_ShmemSegment.h"
#include "I_TrackBase.h"

#include <mpi.h>
#include <list>

#ifndef I_SHMEMSEGMENTTRACK_H
#define I_SHMEMSEGMENTTRACK_H

/**
 * Interface for querying information on SHMEM segments.
 *
 * Important: This analysis module only tracks SHMEM segments,
 * it provides no correctness checking. However, it tries
 * to handle incorrect actions as good as possible.
 *
 * Dependencies (in listed order):
 * - ParallelIdAnalysis
 * - LocationAnalysis
 */
class I_ShmemSegmentTrack : public gti::I_Module,
                            public virtual must::I_TrackBase<must::I_ShmemSegment>
{
  public:
    /**
     * Destroys a segment.
     *
     * @param pId parallel id of call site.
     * @param lId location id of call site.
     * @param addr address to free
     * @return see gti::GTI_ANALYSIS_RETURN.
     */
    virtual gti::GTI_ANALYSIS_RETURN
    segmentDestroy(MustParallelId pId, MustLocationId lId, void* addr) = 0;

    /**
     * Creates a new segment
     *
     * @param pId parallel id of call site.
     * @param lId location id of call site.
     * @param address of the segment
     * @param size of the segment
     * @return see gti::GTI_ANALYSIS_RETURN.
     */
    virtual gti::GTI_ANALYSIS_RETURN
    segmentCreate(MustParallelId pId, MustLocationId lId, void* addr, size_t size) = 0;

    /**
     * Adds the predefineds and important values for them
     * like the list of processes reachable by this place.
     *
     * The extra channel id is used to track whether the reachable
     * interval is already complete, or whether some processes
     * are missing.
     *
     *
     * @param reachableBegin start of interval of processes reachable by this place.
     * @param reachableEnd end of interval of processes reachable by this place.
     * @param worldSize size of SHMEM_TEAM_WORLD
     * @param baseAddr base address for the default segment (static / global variables) in SHMEM
     * @param baseAddrs values of base address on each rank (differs due to ASLR)
     * @param numBaseAddrs number of base addresses in list.
     * @param channId channel id of this record.
     */
    virtual gti::GTI_ANALYSIS_RETURN addPredefinedSegments(
        MustParallelId pId,
        int reachableBegin,
        int reachableEnd,
        int worldSize,
        uint64_t baseAddr,
        uint64_t* baseAddrs,
        int numBaseAddrs,
        gti::I_ChannelId* channId) = 0;

    /**
     * Returns pointer to segment information.
     * Is NULL if this is an unknown handle.
     *
     * Memory must not be freed and is valid until I_ShmemSegmentTrack
     * receives the next event, if you need the information longer
     * query getPersistentSegment instead.
     *
     * @param pId of the segment context.
     * @param segment to query for.
     * @return information for the given segment.
     */
    virtual must::I_ShmemSegment* getSegment(MustParallelId pId, MustShmemSegmentType segment) = 0;

    /** As I_ShmemSegmentTrack::getSegment with rank instead of pid.*/
    virtual must::I_ShmemSegment* getSegment(int rank, MustShmemSegmentType segment) = 0;

    /**
     * Like I_ShmemSegmentTrack::getSegment, though returns a persistent information
     * that is valid until you erase it, i.e.:
     *@code
     I_SegmentPersistent * segmentInfo = mySegmentTrack->getPersistentSegment (pId, handle);
     if (segmentInfo == NULL) return;
     .... //Do something with segmentInfo
     segmentInfo->erase(); //Mark as not needed any longer
     *@endcode
     *
     * A reference count mechanism is used to implement this.
     *
     * @param pId of the segment context.
     * @param segment to query for.
     * @return information for the given segment.
     */
    virtual must::I_ShmemSegmentPersistent*
    getPersistentSegment(MustParallelId pId, MustShmemSegmentType segment) = 0;

    /** As I_ShmemSegmentTrack::getPersistentSegment with rank instead of pid.*/
    virtual must::I_ShmemSegmentPersistent*
    getPersistentSegment(int rank, MustShmemSegmentType segment) = 0;

    /**
     * Find the segment belonging to any arbitrary memory address.
     * In case the memory address belongs to an allocated segment, it returns the
     * segment's handle. Otherwise, it returns the default segment handle.
     *
     * @param pId of the rank
     * @param addr memory address for which the corresponding segment should be found
     * @return handle of the corresponding segment
     */
    virtual MustShmemSegmentType findSegment(MustParallelId pId, void* addr) = 0;

    /** As I_ShmemSegmentTrack::findSegment with rank instead of pid.*/
    virtual MustShmemSegmentType findSegment(int rank, void* addr) = 0;

    /**
     * Returns a list of all currently known user handles.
     * Usage scenarios involve logging lost handles at finalize.
     * @return a list of pairs of the form (rank, handle id).
     */
    virtual std::list<std::pair<int, MustShmemSegmentType>> getUserHandles(void) = 0;

    /**
     * Returns the default segment in SHMEM (static and global variables).
     *
     * @param pId of the rank
     */
    virtual must::I_ShmemSegment* getDefaultSegment(MustParallelId pId) = 0;

    /**
     * Allows other modules to notify this module of an ongoing shutdown.
     * This influcences the behavior of passing free calls across to other layers.
     */
    virtual void notifyOfShutdown(void) = 0;

    virtual bool isPredefined(must::I_ShmemSegment* info) { return info->isPredefined(); }

}; /*class I_ShmemSegmentTrack*/

#endif /*I_ShmemSegmentTRACK_H*/
