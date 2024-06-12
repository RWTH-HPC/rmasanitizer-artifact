/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file I_ShmemSegment.h
 *       @see I_ShmemSegment.
 *
 *  @date 14.02.2023
 *  @author Simon Schwitanski
 */

#include "I_ShmemSegment.h"
#include "I_ShmemSegmentTrack.h"
#include "HandleInfoBase.h"

#ifndef SHMEM_TEAM_H
#define SHMEM_TEAM_H

namespace must
{
/**
 * Implementation of I_ShmemSegment (and I_ShmemSegmentPersistent).
 */
class ShmemSegment : public I_ShmemSegmentPersistent, public HandleInfoBase
{
  public:
    /**
     * Constructor.
     * Initializes as a MUST_SHMEM_TEAM_UNKNOWN info.
     */
    ShmemSegment();

    /**
     * Constructor.
     */
    ShmemSegment(I_ShmemSegmentTrack* segmentTrack);

    /**
     * Destructor.
     */
    ~ShmemSegment();

    bool isPredefined(void) const;               /**< @see I_ShmemSegment::isPredefined.*/
    MustParallelId getCreationPId(void);         /**< @see I_ShmemSegment::creationPId.*/
    MustLocationId getCreationLId(void);         /**< @see I_ShmemSegment::creationLId.*/
    bool compareSegments(I_ShmemSegment* other); /**< @see I_ShmemSegment::compareSegments.*/
    bool operator==(I_ShmemSegment& other);      /**< @see I_ShmemSegment::operator==.*/
    bool operator!=(I_ShmemSegment& other);      /**< @see I_ShmemSegment::operator!=.*/
    MustAddressType getBaseAddress(void);        // get base address of SHMEM segment
    size_t getSize(void);                        // get size of allocated SHMEM segment
    std::string getResourceName(void);
    bool printInfo(
        std::stringstream& out,
        std::list<std::pair<MustParallelId, MustLocationId>>* pReferences);
    unsigned long long getUniqueId(void);

  public:
    bool myIsPredefined;
    std::string myPredefinedName;

    // Only for user defined segments
    MustParallelId myCreationPId;
    MustLocationId myCreationLId;

    unsigned long long myUniqueId;

    MustAddressType myBaseAddr;
    size_t mySize;

    // Backreference to creating segmentTrack
    I_ShmemSegmentTrack* mySegmentTrack;

    MustShmemSegmentPredefined myPredefined;

}; /*class ShmemSegment*/
} /*namespace must*/

#endif /*SHMEM_TEAM_H*/
