/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file GASPIRMAWrapper.h
 *       @see must::GASPIRMAWrapper.
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
#include "I_GASPIRMAWrapper.h"
#include "I_RMASanitize.h"
#include "OneSidedChecksApi.h"

#include <map>
#include <vector>
#include <queue>

#ifndef GASPIRMAWrapper_H
#define GASPIRMAWrapper_H

using namespace gti;

namespace must
{
/**
 * Wraps MPI RMA communication and consistency calls to abstract RMA race detection model
 */
class GASPIRMAWrapper : public gti::ModuleBase<GASPIRMAWrapper, I_GASPIRMAWrapper>
{
  public:
    /**
     * Constructor.
     * @param instanceName name of this module instance.
     */
    GASPIRMAWrapper(const char* instanceName);
    /**
     * Destructor.
     */
    virtual ~GASPIRMAWrapper(void);

    GTI_ANALYSIS_RETURN init(MustParallelId pId);

    GTI_ANALYSIS_RETURN SegmentAlloc(
        MustGASPISegmentIDType segmentId,
        MustGASPISizeType size,
        MustGASPIPointerType ptr);
    GTI_ANALYSIS_RETURN SegmentRegister(MustGASPISegmentIDType segmentId, MustGASPIRankType rank);
    GTI_ANALYSIS_RETURN SegmentCreate(
        MustGASPISegmentIDType segmentId,
        MustGASPISizeType size,
        MustGASPIGroupType group,
        MustGASPIPointerType ptr);
    GTI_ANALYSIS_RETURN SegmentDelete(MustGASPISegmentIDType segmentId);

    GTI_ANALYSIS_RETURN Access(
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
        void* ann);

    GTI_ANALYSIS_RETURN AccessList(
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
        void* ann);

    GTI_ANALYSIS_RETURN AtomicAccess(
        MustParallelId pId,
        MustLocationId lId,
        MustGASPISegmentIDType segmentId,
        MustGASPIOffsetType offsetLocal,
        MustGASPIRankType rank,
        size_t size);

    GTI_ANALYSIS_RETURN Wait(MustParallelId pId, MustLocationId lId, MustGASPIQueueIDType queue);

    GTI_ANALYSIS_RETURN
    Barrier(MustParallelId pId, MustLocationId lId, MustGASPIGroupType group);

    GTI_ANALYSIS_RETURN
    Notify(
        MustParallelId pId,
        MustLocationId lId,
        MustGASPIRankType rank,
        MustGASPINotificationIDType notification);

    GTI_ANALYSIS_RETURN NotifyWait(
        MustParallelId pId,
        MustGASPINotificationIDType notification,
        MustGASPINotificationIDType firstId);

    GTI_ANALYSIS_RETURN ReceiveNotification(
        MustParallelId pId,
        MustLocationId lId,
        MustGASPINotificationIDType notification,
        int origin);

  protected:
    I_ParallelIdAnalysis* myPIdMod;
    I_RMASanitize* myRMASan;

  private:
    std::unordered_map<MustGASPISegmentIDType, std::pair<RMASegmentId, MustAddressType>>
        gaspiSegToSegment;
    std::unordered_map<MustGASPINotificationIDType, std::queue<MustGASPIRankType>>
        myNotificationToRank;

    passGASPINotificationAcrossP myPassGASPINotificationAcrossFunc;

    int myNumRanks;
    int myRank;
    std::vector<int> myAllRanks;
}; /*class GASPIRMAWrapper*/
} /*namespace must*/

#endif /*GASPIRMAWrapper_H*/
