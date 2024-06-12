/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file MPIRMAWrapper.h
 *       @see must::MPIRMAWrapper.
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
#include "I_GroupTrack.h"
#include "I_OpTrack.h"
#include "I_WinTrack.h"
#include "I_TSan.h"
#include "I_LocationAnalysis.h"
#include "I_MPIRMAWrapper.h"
#include "I_RMASanitize.h"

#include <map>
#include <vector>

#ifndef MPIRMAWRAPPER_H
#define MPIRMAWRAPPER_H

using namespace gti;

namespace must
{
/**
 * Wraps MPI RMA communication and consistency calls to abstract RMA race detection model
 */
class MPIRMAWrapper : public gti::ModuleBase<MPIRMAWrapper, I_MPIRMAWrapper>
{
  public:
    /**
     * Constructor.
     * @param instanceName name of this module instance.
     */
    MPIRMAWrapper(const char* instanceName);
    /**
     * Destructor.
     */
    virtual ~MPIRMAWrapper(void);

    /**
     * @see I_MPIRMAWrapper::Get
     */
    GTI_ANALYSIS_RETURN
    Get(MustParallelId pId,
        MustLocationId lId,
        MustAddressType originaddr,
        int origincount,
        MustDatatypeType origintype,
        int target,
        int targetdisp,
        int targetcount,
        MustDatatypeType targettype,
        MustWinType win,
        MustRequestType requesttype,
        void* ann);

    /**
     * @see I_MPIRMAWrapper::Put
     */
    GTI_ANALYSIS_RETURN
    Put(MustParallelId pId,
        MustLocationId lId,
        MustAddressType originaddr,
        int origincount,
        MustDatatypeType origintype,
        int target,
        int targetdisp,
        int targetcount,
        MustDatatypeType targettype,
        MustWinType win,
        MustRequestType requesttype,
        void* ann);

    /**
     * @see I_MPIRMAWrapper::Accumulate
     */
    GTI_ANALYSIS_RETURN Accumulate(
        MustParallelId pId,
        MustLocationId lId,
        MustAddressType originaddr,
        int origincount,
        MustDatatypeType origintype,
        int target,
        int targetdisp,
        int targetcount,
        MustDatatypeType targettype,
        MustOpType op,
        MustWinType win,
        MustRequestType requesttype,
        void* ann);

    /**
     * @see I_MPIRMAWrapper::GetAccumulate
     */
    GTI_ANALYSIS_RETURN GetAccumulate(
        MustParallelId pId,
        MustLocationId lId,
        MustAddressType originaddr,
        int origincount,
        MustDatatypeType origintype,
        MustAddressType resultaddr,
        int resultcount,
        MustDatatypeType resulttype,
        int target,
        int targetdisp,
        int targetcount,
        MustDatatypeType targettype,
        MustOpType op,
        MustWinType win,
        MustRequestType requesttype,
        void* ann);

    /**
     * @see I_MPIRMAWrapper::winLock
     */
    GTI_ANALYSIS_RETURN
    winLock(MustParallelId pId, MustLocationId lId, int lock_type, int rank, MustWinType win);

    /**
     * @see I_MPIRMAWrapper::winUnlock
     */
    GTI_ANALYSIS_RETURN
    winUnlock(MustParallelId pId, MustLocationId lId, int rank, MustWinType win);

    /**
     * @see I_MPIRMAWrapper::originCompletionAll
     */
    GTI_ANALYSIS_RETURN originCompletionAll(
        MustParallelId pId,
        MustLocationId lId,
        MustWinType win,
        int isLocalOnly,
        void* ann);

    /**
     * @see I_MPIRMAWrapper::originCompletionAll
     */
    GTI_ANALYSIS_RETURN originCompletionRank(
        MustParallelId pId,
        MustLocationId lId,
        int targetRank,
        MustWinType win,
        int isLocalOnly);

    /**
     * @see I_MPIRMAWrapper::activeTargetCompletionAll
     */
    GTI_ANALYSIS_RETURN
    activeTargetCompletionAll(MustParallelId pId, MustLocationId lId, MustWinType win, void* ann);

    GTI_ANALYSIS_RETURN
    winCreate(MustWinType win, void* base, void* ann);

    GTI_ANALYSIS_RETURN
    winFree(MustWinType win);

    /**
     * @see I_MPIRMAWrapper:winStart
     */
    GTI_ANALYSIS_RETURN winStart(
        MustParallelId pId,
        MustLocationId lId,
        MustGroupType group,
        MustWinType win,
        void* ann);

    /**
     * @see I_MPIRMAWrapper:winComplete
     */
    GTI_ANALYSIS_RETURN
    winComplete(MustParallelId pId, MustLocationId lId, MustWinType win, void* ann);

    /**
     * @see I_MPIRMAWrapper:winPost
     */
    GTI_ANALYSIS_RETURN winPost(
        MustParallelId pId,
        MustLocationId lId,
        MustGroupType group,
        MustWinType win,
        void* ann);

    /**
     * @see I_MPIRMAWrapper:winWait
     */
    GTI_ANALYSIS_RETURN winWait(MustParallelId pId, MustLocationId lId, MustWinType win, void* ann);

    /**
     * @see I_MPIRMAWrapper::passiveTargetCompletionAll
     */
    GTI_ANALYSIS_RETURN
    passiveTargetCompletionAll(MustParallelId pId, MustLocationId lId, MustWinType win, void* ann);

    /**
     * @see I_MPIRMAWrapper::passiveTargetCompletionRank
     */
    GTI_ANALYSIS_RETURN passiveTargetCompletionRank(
        MustParallelId pId,
        MustLocationId lId,
        int targetRank,
        MustWinType win);

    /**
     * @see I_MPIRMAWrapper::completedRequest
     */
    GTI_ANALYSIS_RETURN
    completedRequest(MustParallelId pId, MustLocationId lId, MustRequestType request);

    /**
     * @see I_MPIRMAWrapper::completedRequests
     */
    GTI_ANALYSIS_RETURN
    completedRequests(MustParallelId pId, MustLocationId lId, MustRequestType* requests, int count);

    GTI_ANALYSIS_RETURN init();

  protected:
    I_ParallelIdAnalysis* myPIdMod;
    I_RMASanitize* myRMASan;
    I_BaseConstants* myConsts;
    I_DatatypeTrack* myDatMod;
    I_RequestTrack* myReqMod;
    I_GroupTrack* myGrpMod;
    I_OpTrack* myOpMod;
    I_WinTrack* myWinMod;
    I_Place* myPlaceMod;

  private:
    std::unordered_map<MustWinType, RMASegmentId> winToSegment;
    std::unordered_map<MustWinType, int> epochCounter;
    std::unordered_map<MustRequestType, std::list<MustRMAId>> reqToOps;

    // for general active target synchronization
    std::map<MustWinType, MustGroupType> myWinCompleteGroupMap;
    std::map<MustWinType, MustGroupType> myWinWaitGroupMap;

    RMAMemIntervals calcIntervalList(
        MustDatatypeType datatype,
        MustParallelId pId,
        MustAddressType buffer,
        int count);

    GTI_ANALYSIS_RETURN addRMAAccess(
        MustParallelId pId,
        MustLocationId lId,
        MustAddressType originaddr,
        int origincount,
        MustDatatypeType origintype,
        int target,
        int targetdisp,
        int targetcount,
        MustDatatypeType targettype,
        MustWinType win,
        MustRequestType requesttype,
        void* ann,
        bool isStore,
        bool isAtomic);

    int translateRank(I_Comm* comm, int rank);
}; /*class MPIRMAWrapper*/
} /*namespace must*/

#endif /*MPIRMAWrapper_H*/
