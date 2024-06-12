/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file I_GASPIRMAWrapper.h
 *       @see I_GASPIRMAWrapper
 *
 *  @date 15.12.2023
 *  @author Simon Schwitanski
 */

#include "GtiEnums.h"
#include "I_Module.h"

#include "MustEnums.h"
#include "BaseIds.h"
#include "MustTypes.h"

#ifndef I_GASPIRMAWrapper_H
#define I_GASPIRMAWrapper_H

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
class I_GASPIRMAWrapper : public gti::I_Module
{
  public:
    virtual gti::GTI_ANALYSIS_RETURN init(MustParallelId pId) = 0;

    virtual gti::GTI_ANALYSIS_RETURN SegmentAlloc(
        MustGASPISegmentIDType segmentId,
        MustGASPISizeType size,
        MustGASPIPointerType ptr) = 0;

    virtual gti::GTI_ANALYSIS_RETURN
    SegmentRegister(MustGASPISegmentIDType segmentId, MustGASPIRankType rank) = 0;

    virtual gti::GTI_ANALYSIS_RETURN SegmentCreate(
        MustGASPISegmentIDType segmentId,
        MustGASPISizeType size,
        MustGASPIGroupType group,
        MustGASPIPointerType ptr) = 0;

    virtual gti::GTI_ANALYSIS_RETURN SegmentDelete(MustGASPISegmentIDType segmentId) = 0;

    virtual gti::GTI_ANALYSIS_RETURN Access(
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
        void* ann) = 0;

    virtual gti::GTI_ANALYSIS_RETURN AccessList(
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
        void* ann) = 0;

    virtual gti::GTI_ANALYSIS_RETURN AtomicAccess(
        MustParallelId pId,
        MustLocationId lId,
        MustGASPISegmentIDType segmentId,
        MustGASPIOffsetType offsetLocal,
        MustGASPIRankType rank,
        size_t size) = 0;

    virtual gti::GTI_ANALYSIS_RETURN
    Wait(MustParallelId pId, MustLocationId lId, MustGASPIQueueIDType queue) = 0;

    virtual gti::GTI_ANALYSIS_RETURN
    Barrier(MustParallelId pId, MustLocationId lId, MustGASPIGroupType group) = 0;

    virtual gti::GTI_ANALYSIS_RETURN Notify(
        MustParallelId pId,
        MustLocationId lId,
        MustGASPIRankType rank,
        MustGASPINotificationIDType notification) = 0;

    virtual gti::GTI_ANALYSIS_RETURN NotifyWait(
        MustParallelId pId,
        MustGASPINotificationIDType notification,
        MustGASPINotificationIDType firstId) = 0;

    virtual gti::GTI_ANALYSIS_RETURN ReceiveNotification(
        MustParallelId pId,
        MustLocationId lId,
        MustGASPINotificationIDType notification,
        int origin) = 0;

}; /*class I_GASPIRMAWrapper */

#endif /*I_GASPIRMAWrapper_H*/
