/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file ShmemSegmentTrack.h
 *       @see MUST::ShmemSegmentTrack
 *
 *  @date 16.02.2023
 *  @author Simon Schwitanski
 */

#include "ModuleBase.h"
#include "TrackBase.h"
#include "CompletionTree.h"

#include "I_ShmemSegmentTrack.h"
#include "ShmemSegment.h"

#include <map>

#ifndef ShmemSegmentTTRACK_H
#define ShmemSegmentTTRACK_H

using namespace gti;

namespace must
{
/**
 * Implementation for I_ShmemSegmentTrack.
 */
class ShmemSegmentTrack : public TrackBase<
                              ShmemSegment,
                              I_ShmemSegment,
                              MustShmemSegmentType,
                              MustShmemSegmentPredefined,
                              ShmemSegmentTrack,
                              I_ShmemSegmentTrack>
{
  public:
    /**
     * Constructor.
     * @param instanceName name of this module instance.
     */
    ShmemSegmentTrack(const char* instanceName);

    /**
     * Destructor.
     */
    virtual ~ShmemSegmentTrack(void);

    /**
     * @see I_ShmemSegmentTrack::segmentCreate
     */

    GTI_ANALYSIS_RETURN
    segmentCreate(MustParallelId pId, MustLocationId lId, void* addr, size_t size);

    /**
     * @see I_ShmemSegmentTrack::segmentDestroy
     */

    GTI_ANALYSIS_RETURN
    segmentDestroy(MustParallelId pId, MustLocationId lId, void* addr);

    /**
     * @see I_ShmemSegmentTrack::addPredefinedSegments.
     */
    GTI_ANALYSIS_RETURN addPredefinedSegments(
        MustParallelId pId,
        int reachableBegin,
        int reachableEnd,
        int worldSize,
        uint64_t baseAddr,
        uint64_t* baseAddrs,
        int numBaseAddrs,
        gti::I_ChannelId* channId);

    /**
     * @see I_ShmemSegmentTrack::getSegment
     */
    I_ShmemSegment* getSegment(MustParallelId pId, MustShmemSegmentType segment);

    /**
     * @see I_ShmemSegmentTrack::getSegment
     */
    I_ShmemSegment* getSegment(int rank, MustShmemSegmentType segment);

    /**
     * @see I_ShmemSegmentTrack::getPersistentSegment
     */
    I_ShmemSegmentPersistent*
    getPersistentSegment(MustParallelId pId, MustShmemSegmentType segment);

    /**
     * @see I_ShmemSegmentTrack::getPersistentSegment
     */
    I_ShmemSegmentPersistent* getPersistentSegment(int rank, MustShmemSegmentType segment);

    /**
     * @see I_ShmemSegmentTrack::getDefaultSegment
     */
    I_ShmemSegment* getDefaultSegment(MustParallelId pId);

    /**
     * @see I_ShmemSegmentTrack::findSegment
     */
    MustShmemSegmentType findSegment(MustParallelId pId, void* addr);

    /**
     * @see I_ShmemSegmentTrack::findSegment
     */
    MustShmemSegmentType findSegment(int rank, void* addr);

    /**
     * @see I_ShmemSegmentTrack::notifyOfShutdown
     * @see TrackBase::notifyOfShutdown
     */
    void notifyOfShutdown(void);

  protected:
    I_GroupTrack* myGroupMod; /**< The group tracking module.*/

    std::vector<ShmemSegment*>
        myDefaultSegments; /**< Information for base addrs of default segment of each rank */

    bool myReachableAvailable; /**< Set to true once all information on reachable processes
                                  arrived.*/
    int myReachableBegin;      /**< Beginning SHMEM_TEAM_WORLD rank of reachable processes.*/
    int myReachableEnd;        /**< Last SHMEM_TEAM_WORLD rank of reachable processes.*/

    std::map<int, MustShmemSegmentType>
        myDefaultSegmentHandles; // maps a rank to its default segment handle

    /**
     * Returns the full segment information for the given memory address.
     *
     * Returns an info for user, predefined and null segments.
     *
     * We can't use TrackBase::getHandleInfo here as we have a specialized handling of
     * the default segment!
     *
     * @param pId context for segment.
     * @param segment to query for.
     * @return the segment in question or NULL if not found.
     */
    ShmemSegment* getSegmentInfo(MustParallelId pId, MustShmemSegmentType segment);

    /**
     * @see other getSegmentInfo, difference is pid.
     */
    ShmemSegment* getSegmentInfo(int rank, MustShmemSegmentType segment);

  private:
    unsigned long long myUniqueIdCounter;
    /**
     * Returns for a given address the segment that belongs to this address.
     * If it does not find a matching *allocated* segment, it will return the default segment.
     */
    MustShmemSegmentType findSegment(MustAddressType addrs);

}; /*class ShmemSegmentTrack */
} // namespace must

#endif /*ShmemSegmentTTRACK_H*/
