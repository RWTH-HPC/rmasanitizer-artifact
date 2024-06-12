/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
 * @file I_GASPIVectorClockWrapper.h
 *       Vector clock analysis module.
 *
 *  @date 29.06.2021
 *  @author Felix Tomski
 */

#include "MustTypes.h"
#include "BaseIds.h"
#include "GtiEnums.h"
#include "I_Module.h"
#include <GASPI.h>

#pragma once

/**
 * Wrapper for the GTI VectorClock module.
 *
 * Dependencies (order as listed):
 * - X
 *
 */
class I_GASPIVectorClockWrapper : public gti::I_Module {
  public:
    virtual gti::GTI_ANALYSIS_RETURN init() = 0;
    virtual gti::GTI_ANALYSIS_RETURN tick() = 0;

    virtual gti::GTI_ANALYSIS_RETURN allToAll(MustParallelId pId, const MustGASPIGroupType group) = 0;

    virtual gti::GTI_ANALYSIS_RETURN signalResource(MustParallelId pId, MustGASPIRankType target_rank, MustGASPINotificationIDType notify_id) = 0;
    virtual gti::GTI_ANALYSIS_RETURN signalResourceLocal(MustParallelId pId, MustGASPINotificationIDType notify_id) = 0;
    virtual gti::GTI_ANALYSIS_RETURN waitResource(MustParallelId pId, MustGASPINotificationIDType notify_id, MustGASPINumberType notify_num) = 0;

    virtual gti::GTI_ANALYSIS_RETURN signal(MustParallelId pId, MustGASPIRankType target_rank) = 0;
    virtual gti::GTI_ANALYSIS_RETURN wait(MustParallelId pId, MustGASPIRankType orig_rank) = 0;
}; /*class I_GASPIVectorClockWrapper*/
