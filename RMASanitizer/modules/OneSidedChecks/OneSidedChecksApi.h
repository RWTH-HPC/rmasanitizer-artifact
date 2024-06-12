/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file OneSidedChecksApi.h
 * 		P call definition for MUST OneSidedChecks API calls.
 *
 * @author Simon Schwitanski
 * @date 13.06.2017
 */

#ifndef ONESIDEDCHECKS_API_H
#define ONESIDEDCHECKS_API_H

#include "BaseIds.h"

inline int PpassTargetRMAOpAcross(
    int origin,
    MustRMAId rmaId,
    MustParallelId pId,
    MustLocationId lId,
    int64_t* memAddresses,
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
    size_t vectorClockSize)
{
    return 0;
}

typedef int (*passTargetRMAOpAcrossP)(
    int origin,
    MustRMAId rmaId,
    MustParallelId pId,
    MustLocationId lId,
    int64_t* memAddresses,
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
    size_t vectorClockSize,
    int toPlaceId);

inline int PpassRemoteBulkCompleteAcross(
    MustParallelId pId,
    MustLocationId lId,
    int origin,
    int target,
    RMAContextId context,
    int epoch,
    int isLocalOnly,
    unsigned long long* vectorClock,
    size_t vectorClockSize)
{
    return 0;
}
typedef int (*passRemoteBulkCompleteAcrossP)(
    MustParallelId pId,
    MustLocationId lId,
    int origin,
    int target,
    RMAContextId context,
    int epoch,
    int isLocalOnly,
    unsigned long long* vectorClock,
    size_t vectorClockSize,
    int toPlaceId);

inline int PpassRemoteCompleteAcross(
    MustParallelId pId,
    MustLocationId lId,
    int origin,
    RMAHandleId handle,
    int isLocalOnly,
    unsigned long long* vectorClock,
    size_t vectorClockSize)
{
    return 0;
}
typedef int (*passRemoteCompleteAcrossP)(
    MustParallelId pId,
    MustLocationId lId,
    int origin,
    RMAHandleId handle,
    int isLocalOnly,
    unsigned long long* vectorClock,
    size_t vectorClockSize,
    int toPlaceId);

#ifdef ENABLE_OPENSHMEM
typedef int (*passAtomicSetAcrossP)(
    MustParallelId pId,
    MustLocationId lId,
    MustShmemSegmentType segmentId,
    uint64_t contextId,
    uint64_t offset,
    int target,
    int toPlaceId);

inline int PpassAtomicSetAcross(
    MustParallelId pId,
    MustLocationId lId,
    MustShmemSegmentType segmentId,
    uint64_t contextId,
    int target,
    uint64_t offset)
{
    return 0;
}
#endif

#ifdef ENABLE_GASPI
typedef int (*passGASPINotificationAcrossP)(
    MustParallelId pId,
    MustLocationId lId,
    MustGASPINotificationIDType notification,
    int origin,
    int toPlaceId);

inline int PpassGASPINotificationAcross(
    MustParallelId pId,
    MustLocationId lId,
    MustGASPINotificationIDType notification,
    int origin)
{
    return 0;
}
#endif

typedef int (*passNotificationAcrossP)(
    MustParallelId pId,
    MustLocationId lId,
    uint64_t sigaddr,
    RMAContextId context,
    MustRMAId rmaId,
    int toPlaceId);

inline int PpassNotificationAcross(
    MustParallelId pId,
    MustLocationId lId,
    uint64_t sigaddr,
    RMAContextId context,
    MustRMAId rmaId)
{
    return 0;
}

typedef int (
    *passNotificationAckAcrossP)(uint64_t sigaddr, RMAContextId context, int target, int toPlaceId);

inline int PpassNotificationAckAcross(uint64_t sigaddr, RMAContextId context, int target)
{
    return 0;
}

inline void PnotifySync(int remoteRank, int ownRank) {}

typedef void (*notifySyncP)(int remoteRank, int ownRank);

inline void PnotifyOriginOpStart(MustRMAId rmaId) {}

typedef void (*notifyOriginOpStartP)(MustRMAId rmaId);

inline void
PnotifyOriginOpComplete(MustParallelId pId, MustLocationId lId, MustRMAId* rmaId, int rmaIdLen)
{
}

typedef void (*notifyOriginOpCompleteP)(
    MustParallelId pId,
    MustLocationId lId,
    MustRMAId* rmaId,
    int rmaIdLen);

inline void PnotifyTargetOpStart(MustRMAId rmaId) {}

typedef void (*notifyTargetOpStartP)(MustRMAId rmaId);

inline void
PnotifyTargetOpComplete(MustParallelId pId, MustLocationId lId, MustRMAId* rmaId, int rmaIdLen)
{
}

typedef void (*notifyTargetOpCompleteP)(
    MustParallelId pId,
    MustLocationId lId,
    MustRMAId* rmaId,
    int rmaIdLen);

inline void PpropagateWinLock(
    MustParallelId pId,
    MustLocationId lId,
    int lock_type,
    int rank,
    MustWinType win,
    void* ann)
{
}

typedef void (*propagateWinLockP)(
    MustParallelId pId,
    MustLocationId lId,
    int lock_type,
    int rank,
    MustWinType win,
    void* ann);

inline void
PpropagateWinUnlock(MustParallelId pId, MustLocationId lId, int rank, MustWinType win, void* ann)
{
}

typedef void (*propagateWinUnlockP)(
    MustParallelId pId,
    MustLocationId lId,
    int rank,
    MustWinType win,
    void* ann);

inline void PpropagateSignal(void* ann) {}

typedef void (*propagateSignalP)(void* ann);

#endif
