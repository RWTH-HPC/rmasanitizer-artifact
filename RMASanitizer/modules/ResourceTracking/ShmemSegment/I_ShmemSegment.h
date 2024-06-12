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

#include "MustTypes.h"
#include "MustEnums.h"
#include "BaseIds.h"

#include "I_GroupTable.h"
#include "I_Destructable.h"

#include <sstream>
#include <list>

#ifndef I_SHMEM_SEGMENT_H
#define I_SHMEM_SEGMENT_H

namespace must
{
/**
 * Interface for storage and accessing information on SHMEM segments.
 */
class I_ShmemSegment
{
  public:
    /*
     * History information.
     */
    virtual MustParallelId
    getCreationPId(void) = 0; /**< For persistent segments information for call
                                 that created the segment, otherwise not set.*/
    virtual MustLocationId
    getCreationLId(void) = 0; /**< For persistent segmentms information for call
                                 that created the segment, otherwise not set.*/
    virtual MustAddressType getBaseAddress(void) = 0; // get base address of SHMEM segment
    virtual size_t getSize(void) = 0;                 // get size of allocated SHMEM segment
    virtual bool isPredefined(void) const = 0; /**< True if this type is the default segment */

    // To have a unique identifier of segments across ranks
    // This is required have a unique idenfier (identical across ranks)
    virtual unsigned long long getUniqueId(void) = 0;

    /**
     * Returns true if this segment is equal to the given one.
     * (Refer to the same communication group with equal context id.)
     * Returns false otherwise.
     *
     * @param other segment to compare to.
     */
    virtual bool compareSegments(I_ShmemSegment* other) = 0;

    /**
     * Returns true if this segment is equal to the given one.
     * (Refer to the same communication group with equal context id.)
     * Returns false otherwise. This is the 'operator version' of
     * compareSegments().
     *
     * @param other segment to compare to.
     */
    virtual bool operator==(I_ShmemSegment& other) = 0;

    /**
     * Returns false if this segment is equal to the given one.
     * (Refer to the same communication group with equal context id.)
     * Returns true otherwise. This is the 'operator version' of
     * the opposite of compareSegments().
     *
     * @param other segment to compare to.
     */
    virtual bool operator!=(I_ShmemSegment& other) = 0;
}; /*class I_ShmemSegment*/

/**
 * Interface for storage and accessing Information
 * on a segment as defined in SHMEM. This is the persistent
 * version of the interface. The user needs to call I_ShmemSegmentPersistent::erase
 * when he is finished with it.
 */
class I_ShmemSegmentPersistent : public I_ShmemSegment, public virtual I_Destructable
{
}; /*class I_ShmemSegmentPersistent*/

} /*namespace must*/

#endif /*I_SHMEM_TEAM_H*/
