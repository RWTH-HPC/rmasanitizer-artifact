/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file GASPIVectorClockWrapper.h
 *       @see I_GASPIVectorClockWrapper.h.
 *
 *  @date 29.06.2021
 *  @author Felix Tomski
 */

#include "I_CommTrack.h"
#include "I_ParallelIdAnalysis.h"
#include "I_VectorClock.h"
#include "ModuleBase.h"
#include "MustTypes.h"

#include "I_GASPIVectorClockWrapper.h"
#include <vector>
#include <GASPI.h>

#pragma once

using namespace gti;

namespace must {
class GASPIVectorClockWrapper : public gti::ModuleBase<GASPIVectorClockWrapper, I_GASPIVectorClockWrapper> {
  public:
    /**
     * Constructor.
     */
    GASPIVectorClockWrapper(const char* instanceName);

    /**
     * Destructor.
     */
    virtual ~GASPIVectorClockWrapper(void);

    GTI_ANALYSIS_RETURN init();
    GTI_ANALYSIS_RETURN tick();

    // Collective Communication
    GTI_ANALYSIS_RETURN allToAll(MustParallelId pId, const MustGASPIGroupType group);

    // Notifications
    GTI_ANALYSIS_RETURN signalResource(MustParallelId pId, MustGASPIRankType target_rank, MustGASPINotificationIDType notify_id);
    GTI_ANALYSIS_RETURN signalResourceLocal(MustParallelId pId, MustGASPINotificationIDType notify_id);
    GTI_ANALYSIS_RETURN waitResource(MustParallelId pId, MustGASPINotificationIDType notify_id, MustGASPINumberType notify_num);

    // Two-sided communication
    GTI_ANALYSIS_RETURN signal(MustParallelId pId, MustGASPIRankType target_rank);
    GTI_ANALYSIS_RETURN wait(MustParallelId pId, MustGASPIRankType orig_rank);

  protected:
    I_VectorClock* myVectorClockMod;

  private:
    gaspi_rank_t myProcRank;
    gaspi_rank_t numProcs;

}; /*class GASPIVectorClockWrapper*/
} /*namespace must*/
