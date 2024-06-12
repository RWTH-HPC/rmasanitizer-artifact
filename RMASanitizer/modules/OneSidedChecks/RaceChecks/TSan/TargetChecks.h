/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file TargetChecks.h
 *       @see must::TargetChecks.
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
#include "I_TSanSyncClockRecorder.h"
#include "I_LocationAnalysis.h"
#include "I_RMASanitize.h"
#include "I_VectorClock.h"

#include "I_TargetRMAOp.h"
#include "I_TargetChecks.h"

#include <map>

#ifndef TARGETCHECKS_H
#define TARGETCHECKS_H

using namespace gti;

#define CIRCULAR_BUFFER_SIZE 100

// Circular buffer to store the most recent N = 100 remote RMA accesses from a rank
class CircularBuffer
{
  public:
    CircularBuffer() : size(CIRCULAR_BUFFER_SIZE), start(0), end(0), data() {}
    void add(RMAOpHistoryData item)
    {
        data[end] = item;
        end = (end + 1) % size;
        if (start == end) { // if buffer is full, also move start
            start = (start + 1) % size;
        }
    };

    bool find(MustRMAId callId, RMAOpHistoryData& result)
    {
        size_t cur = start;
        while (cur != end) {
            if (data[cur].callId == callId) {
                result = data[cur];
                return true;
            }
            cur = (cur + 1) % size;
        }
        return false;
    };

  private:
    std::array<RMAOpHistoryData, CIRCULAR_BUFFER_SIZE> data;
    size_t start;
    size_t end;
    size_t size;
};

namespace must
{
/**
 * Correctness checks for memory operations at the target.
 */
class TargetChecks : public gti::ModuleBase<TargetChecks, I_TargetChecks>
{
  public:
    /**
     * Constructor.
     * @param instanceName name of this module instance.
     */
    TargetChecks(const char* instanceName);

    /**
     * @see I_TargetChecks::targetOpStart
     */
    GTI_ANALYSIS_RETURN targetOpStart(MustRMAId rmaId);

    /**
     * @see I_TargetChecks::targetOpComplete
     */
    GTI_ANALYSIS_RETURN
    targetOpComplete(MustParallelId pId, MustLocationId lId, MustRMAId* rmaId, int rmaIdLen);

    /**
     * @see I_TargetChecks::winCreate
     */
    GTI_ANALYSIS_RETURN
    winCreate(MustWinType win, void* ann);

    /**
     * @see I_TargetChecks::winLock
     */
    GTI_ANALYSIS_RETURN winLock(
        MustParallelId pId,
        MustLocationId lId,
        int lock_type,
        int rank,
        MustWinType win,
        void* ann);

    /**
     * Destructor.
     */
    virtual ~TargetChecks(void);

    bool getHistoryData(MustParallelId pId, MustRMAId rmaId, RMAOpHistoryData& op);

  protected:
    I_ParallelIdAnalysis* myPIdMod;
    I_CreateMessage* myLogger;
    I_BaseConstants* myConsts;
    I_DatatypeTrack* myDatMod;
    I_RequestTrack* myReqMod;
    I_LocationAnalysis* myLIdMod;
    I_WinTrack* myWinMod;
    I_TSan* myTSanMod;
    I_RMASanitize* myRMASan;
    I_TSanSyncClockRecorder* myTSanSyncClockRecorder;
    I_VectorClock* myVCMod;

  private:
    // store history of annotated RMA calls for race verification
    std::unordered_map<int, CircularBuffer> myRMAAnnotationHistory;

    void annotateMemAccess(
        MustParallelId pId,
        MustLocationId lId,
        const RMAMemIntervals& memIntervals,
        bool isStore,
        const void* returnAddr,
        const void* funcAddr);

    void annotateMetadataEnter(MustParallelId pId, MustParallelId lId, MustRMAId rmaId);

    void annotateMetadataExit();

    bool isRace(MustParallelId pId1, MustRMAId rmaId1, MustParallelId pId2, MustRMAId rmaId2);

    MustMpiDatatypePredefined extractBasetype(I_Datatype* datatype);

    std::map<int, void*> myFiberPool;

    // store TSan sync clocks for *local* window lock calls in Tsan,
    // because it could be the begin of the concurrent region
    std::map<MustWinType, const void*> myWinLockAddrs;

    // store TSan sync clocks for window creation calls,
    // because it could be the begin of the concurrent region
    // if taget and origin did not synchronize no far
    std::map<MustWinType, void*> myWinCreateAddrs;

    /**
     * Translates a rank in a given communicator to the
     * corresponding rank in MPI_COMM_WORLD.
     *
     * @param comm communicator the rank belongs to
     * @param rank rank to convert
     * @return corresponding rank in MPI_COMM_WORLD
     */
    int translateRank(I_Comm* comm, int rank);

    // Stores whether TSanMessages module has been loaded.
    // If so, we add further meta information to TSan annotations
    // to parse them in the TSanMessages module.
    bool myHasTSanMessages;

}; /*class TargetChecks.h*/
} /*namespace must*/

#endif /*TARGETCHECKS.H_H*/
