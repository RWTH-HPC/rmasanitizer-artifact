/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file RMASanitize.h
 *       @see must::RMASanitize.
 *
 *  @date 15.12.2023
 *  @author Simon Schwitanski
 */

#include "ModuleBase.h"
#include "I_ParallelIdAnalysis.h"
#include "I_LocationAnalysis.h"
#include "I_RMASanitize.h"
#include "I_VectorClock.h"
#include "I_CreateMessage.h"

#include "OriginRMAMap.h"
#include "TargetRMAMap.h"

#include <map>
#include <vector>
#include <unordered_set>

#include "OneSidedChecksApi.h"

#ifndef RMASanitize_H
#define RMASanitize_H

using namespace gti;

namespace must
{

struct RMASegment {
    MustAddressType baseAddress;
};

// Used for tracking target op states
enum TargetOpState {
    TARGET_OP_STATE_INIT = 0,
    TARGET_OP_STATE_CONSISTENT,
    TARGET_OP_STATE_CONSISTENT_HB,
    TARGET_OP_STATE_COUNT,
    TARGET_OP_STATE_NONE
};

enum RMAAnalysisMode {
    RMA_ANALYSIS_MODE_SHADOW = 0,
    RMA_ANALYSIS_MODE_ISL,
    RMA_ANALYSIS_MODE_COUNT
};

enum RMAModel { RMA_MODEL_MPIRMA = 0, RMA_MODEL_SHMEM, RMA_MODEL_GASPI, RMA_MODEL_COUNT };

/**
 * Tracks completion status of RMA operations.
 */
class RMASanitize : public gti::ModuleBase<RMASanitize, I_RMASanitize>
{
  public:
    /**
     * Constructor.
     * @param instanceName name of this module instance.
     */
    RMASanitize(const char* instanceName);

    /**
     * Destructor.
     */
    virtual ~RMASanitize(void);

    GTI_ANALYSIS_RETURN init(MustParallelId pId);

    MustRMAId nextRMAId() { return ++myRMAId; };
    RMASegmentId allocSegment(MustAddressType baseAddress, void* ann);
    void freeSegment(RMASegmentId segment);

    void addLocalAccess(
        MustParallelId pId,
        MustLocationId lId,
        unsigned long target,
        MustRMAId rmaId,
        RMASegmentId segment,
        RMAContextId context,
        RMAMemIntervals& localAddrs,
        RMAHandleId handle,
        bool isStore,
        void* ann);

    void addRemoteAccess(
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
        void* ann);

    void localComplete(MustParallelId pId, MustLocationId lId, MustRMAId rmaId);

    void localBulkComplete(
        MustParallelId pId,
        MustLocationId lId,
        RMAContextId context,
        bool isLocalOnly,
        const std::vector<int>& groupRanks);

    void bulkCollectiveRemoteComplete(
        MustParallelId pId,
        MustLocationId lId,
        RMAContextId context,
        const std::vector<int>& groupRanks);

    void originRemoteBulkComplete(
        MustParallelId pId,
        MustLocationId lId,
        RMAContextId context,
        const std::vector<int>& groupRanks);

    void targetRemoteComplete(
        MustParallelId pId,
        MustLocationId lId,
        RMAContextId context,
        const std::vector<int>& originRanks);

    void targetNotify(
        MustParallelId pId,
        MustLocationId lId,
        RMAContextId context,
        uint64_t sigaddr,
        MustRMAId rmaId,
        int target);

    void targetWait(MustParallelId pId, MustLocationId lId, RMAContextId context, uint64_t sigaddr);

    GTI_ANALYSIS_RETURN receiveNotification(
        MustParallelId pId,
        MustLocationId lId,
        RMAContextId context,
        uint64_t sigaddr,
        MustRMAId rmaId);

    GTI_ANALYSIS_RETURN receiveNotificationAck(RMAContextId context, uint64_t sigaddr, int target);

    GTI_ANALYSIS_RETURN receiveRemoteAccess(
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
        size_t vectorClockSize);

    GTI_ANALYSIS_RETURN receiveRemoteBulkComplete(
        MustParallelId pId,
        MustLocationId lId,
        int origin,
        int target,
        RMAContextId context,
        int epoch,
        int isLocalOnly,
        unsigned long long* vectorClock,
        size_t vectorClockSize);

    GTI_ANALYSIS_RETURN
    receiveRemoteComplete(
        MustParallelId pId,
        MustLocationId lId,
        int origin,
        MustRMAId rmaId,
        int isLocalOnly,
        unsigned long long* vectorClock,
        size_t vectorClockSize);

    GTI_ANALYSIS_RETURN receiveSync(int remoteRank, int ownRank);

    void epochMarker(RMAContextId context);

    I_OriginRMAOp* getOriginRMAOp(MustRMAId rmaId);
    I_TargetRMAOp* getTargetRMAOp(MustRMAId rmaId);
    I_OriginRMAOpPersistent* getPersistentOriginRMAOp(MustRMAId rmaId);
    I_TargetRMAOpPersistent* getPersistentTargetRMAOp(MustRMAId rmaId);

    void* getSegmentAnn(RMASegmentId segmentId);

    ClockEntry* getCurrentVC();
    size_t getCurrentVCSize();

  protected:
    I_ParallelIdAnalysis* myPIdMod;
    I_LocationAnalysis* myLIdMod;
    I_VectorClock* myVectorClock;
    I_CreateMessage* myLogger;

  private:
    MustRMAId nextSegmentId() { return ++mySegmentId; };

    // unique ID for each RMA segment
    RMASegmentId mySegmentId;

    // unique ID for each RMA operation
    MustRMAId myRMAId;

    // RMA analysis mode (either ISL or SHADOW), default is SHADOW
    RMAAnalysisMode myRMAAnalysisMode;

    // Pass full VC (required for maximum accuracy)
    bool passFullVC;

    // contains all allocated RMA segments
    std::unordered_map<RMASegmentId, RMASegment> mySegmentMap;

    // contains TSan addresses that mark the location where the segment was allocated
    std::unordered_map<RMASegmentId, void*> mySegmentAnn;

    // contains all RMA accesses at the origin
    OriginRMAMap myOrigRMAMap;

    // contains all RMA accesses at the target
    TargetRMAMap myTgtRMAMap;

    // track status of remote accesses (at target)
    std::map<RMAContextId, std::map<int, std::vector<std::list<MustRMAId>>>> myTgtStateMap;

    // track epoch status
    std::unordered_map<RMAContextId, int> myEpochCounter;

    I_Place* myPlaceMod;

    std::set<std::pair<uint64_t, MustRMAId>> myWaitNotificationAcks;

    std::map<uint64_t, std::vector<std::pair<int, int>>> myPendingNotifications;

    size_t myLocalAccessCounter;
    size_t myRemoteAccessCounter;

    // Function pointers for passing target RMA op across
    passTargetRMAOpAcrossP myPassTargetRMAOpAcrossFunc;
    passRemoteBulkCompleteAcrossP myPassRemoteBulkCompleteAcross;
    passRemoteCompleteAcrossP myPassRemoteCompleteAcross;
    notifyOriginOpStartP myNotifyOriginOpStartFunc;
    notifyOriginOpCompleteP myNotifyOriginOpCompleteFunc;
    notifyTargetOpStartP myNotifyTargetOpStartFunc;
    notifyTargetOpCompleteP myNotifyTargetOpCompleteFunc;
    passNotificationAcrossP myPassNotificationAcrossFunc;
    passNotificationAckAcrossP myPassNotificationAckAcrossFunc;

    void passTargetRMAOpAcross(
        int origin,
        int target,
        MustRMAId rmaId,
        MustParallelId pId,
        MustLocationId lId,
        bool isStore,
        bool isAtomic,
        RMAMemIntervals& memIntervals,
        RMASegmentId segment,
        RMAContextId context,
        int epoch,
        RMADataTypeId datatype,
        size_t datatypeSize,
        int toPlaceId);

    void passRemoteCompletionAcross(
        int rank,
        MustParallelId pId,
        MustLocationId lId,
        int origin,
        bool isLocalOnly,
        MustRMAId rmaId);

    void passRemoteBulkCompleteAcross(
        int rank,
        MustParallelId pId,
        MustLocationId lId,
        int origin,
        RMAContextId context,
        bool isLocalOnly,
        int epoch);

    void notifyOriginOpComplete(
        MustParallelId pId,
        MustLocationId lId,
        const std::list<MustRMAId>& completedOps);

    void notifyTargetOpComplete(
        MustParallelId pId,
        MustLocationId lId,
        const std::list<MustRMAId>& completedOps);

    RMAEpoch getCurrentEpoch(RMAContextId context);

}; /*class RMASanitize*/
} /*namespace must*/

#endif /*RMASanitize_H*/
