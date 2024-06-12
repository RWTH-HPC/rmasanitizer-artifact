/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file I_ShmemSegmentPredefs.h
 *       @see I_ShmemSegmentPredefs.
 *
 *  @date 16.02.2023
 *  @author Simon Schwitanski
 */

#include "I_Module.h"
#include "GtiEnums.h"
#include "BaseIds.h"

#ifndef I_ShmemSegmentPREDEFS_H
#define I_ShmemSegmentPREDEFS_H

/**
 * Helper module to extract predefineds for shmem teams
 * and pass them to a wrap-everywhere function on which
 * a reduction runs to reduce this information.
 * This information includes an interval of processes reachable
 * by this place (reachable in the GTI communication system).
 *
 *
 * Dependencies (order as listed):
 * X
 *
 */
class I_ShmemSegmentPredefs : public gti::I_Module
{
  public:
    /**
     * Triggers the extraction of information and the call
     * of the wrapp-everywhere call used to forward this
     * information.
     *
     * @return see gti::GTI_ANALYSIS_RETURN.
     */
    virtual gti::GTI_ANALYSIS_RETURN propagate(MustParallelId pId) = 0;
}; /*class I_ShmemSegmentPredefs*/

#endif /*I_ShmemSegmentPREDEFS_H*/
