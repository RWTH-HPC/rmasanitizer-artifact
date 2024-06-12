/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file I_RMASanitize.h
 *       @see I_RMASanitize
 *
 *  @date 15.12.2023
 *  @author Simon Schwitanski
 */

#include "GtiEnums.h"
#include "I_Module.h"

#include "MustEnums.h"
#include "BaseIds.h"
#include "MustTypes.h"
#include "I_OriginRMAOp.h"
#include "I_TargetRMAOp.h"
#include "RMASanitizeTypes.h"

#include <vector>

#ifndef I_RMASanitize_H
#define I_RMASanitize_H

/**
 * Interface for an RMA operation tracking module.
 *
 * Dependencies (in listed order):
 * - ParallelIdAnalysis
 * - LocationAnalysis
 */
class I_RMASanitize : public gti::I_Module
{
  public:
    virtual gti::GTI_ANALYSIS_RETURN init(MustParallelId pId) = 0;

    virtual RMASegmentId allocSegment(MustAddressType baseAddress, void* ann) = 0;

    virtual void freeSegment(RMASegmentId segment) = 0;

    virtual MustRMAId nextRMAId() = 0;

    virtual void addLocalAccess(
        MustParallelId pId,
        MustLocationId lId,
        unsigned long target,
        MustRMAId rmaId,
        RMASegmentId segment,
        RMAContextId context,
        RMAMemIntervals& localAddrs,
        RMAHandleId handle,
        bool isStore,
        void* ann) = 0;

    virtual void addRemoteAccess(
        MustParallelId pId,
        MustLocationId lId,
        unsigned long target,
        MustRMAId rmaId,
        RMASegmentId segment,
        RMAContextId context,
        RMAMemIntervals& remoteAddrs,
        MustDatatypeType remoteDataType,
        size_t remoteDataTypeSize,
        RMAHandleId handle,
        bool isAtomic,
        bool isStore,
        void* ann) = 0;

    /**
     * Receives an RMA operation from another place in the same layer.
     */
    virtual gti::GTI_ANALYSIS_RETURN receiveRemoteAccess(
        int origin,
        MustRMAId rmaId,
        MustParallelId pId,
        MustLocationId lId,
        MustAddressType* memAddresses,
        size_t* memSizes,
        size_t memIntervalsSize,
        bool isStore,
        bool isAtomic,
        int target,
        RMASegmentId segment,
        RMAContextId context,
        RMADataTypeId datatype,
        size_t datatypeSize,
        int epoch,
        unsigned long long clockValue,
        unsigned long long* vectorClock,
        size_t vectorClockSize) = 0;

    virtual void localBulkComplete(
        MustParallelId pId,
        MustLocationId lId,
        RMAContextId context,
        bool isLocalOnly,
        const std::vector<int>& groupRanks) = 0;

    virtual void localComplete(MustParallelId pId, MustLocationId lId, MustRMAId rmaId) = 0;

    virtual void bulkCollectiveRemoteComplete(
        MustParallelId pId,
        MustLocationId lId,
        RMAContextId context,
        const std::vector<int>& groupRanks) = 0;

    virtual void epochMarker(RMAContextId context) = 0;

    virtual void originRemoteBulkComplete(
        MustParallelId pId,
        MustLocationId lId,
        RMAContextId context,
        const std::vector<int>& groupRanks) = 0;

    virtual void targetRemoteComplete(
        MustParallelId pId,
        MustLocationId lId,
        RMAContextId context,
        const std::vector<int>& originRanks) = 0;

    virtual void targetNotify(
        MustParallelId pId,
        MustLocationId lId,
        RMAContextId context,
        uint64_t sigaddr,
        MustRMAId rmaId,
        int target) = 0;

    virtual void
    targetWait(MustParallelId pId, MustLocationId lId, RMAContextId context, uint64_t sigaddr) = 0;

    virtual gti::GTI_ANALYSIS_RETURN receiveNotification(
        MustParallelId pId,
        MustLocationId lId,
        RMAContextId context,
        uint64_t sigaddr,
        MustRMAId rmaId) = 0;

    virtual gti::GTI_ANALYSIS_RETURN
    receiveNotificationAck(RMAContextId context, uint64_t sigaddr, int target) = 0;

    virtual gti::GTI_ANALYSIS_RETURN receiveRemoteBulkComplete(
        MustParallelId pId,
        MustLocationId lId,
        int origin,
        int target,
        RMAContextId context,
        int epoch,
        int isLocalOnly,
        unsigned long long* vectorClock,
        size_t vectorClockSize) = 0;

    virtual gti::GTI_ANALYSIS_RETURN receiveRemoteComplete(
        MustParallelId pId,
        MustLocationId lId,
        int origin,
        MustRMAId rmaId,
        int isLocalOnly,
        unsigned long long* vectorClock,
        size_t vectorClockSize) = 0;

    /**
     * Receives a synchronization event with the given rank.
     *
     * @remoteRank application rank the synchronization occurred with
     * @ownRank application rank calling this notification
     */
    virtual gti::GTI_ANALYSIS_RETURN receiveSync(int remoteRank, int ownRank) = 0;

    virtual must::I_OriginRMAOp* getOriginRMAOp(MustRMAId rmaId) = 0;
    virtual must::I_TargetRMAOp* getTargetRMAOp(MustRMAId rmaId) = 0;
    virtual must::I_OriginRMAOpPersistent* getPersistentOriginRMAOp(MustRMAId rmaId) = 0;
    virtual must::I_TargetRMAOpPersistent* getPersistentTargetRMAOp(MustRMAId rmaId) = 0;
    virtual void* getSegmentAnn(RMASegmentId segmentId) = 0;

}; /*class I_RMASanitize */

#endif /*I_RMASanitize_H*/
