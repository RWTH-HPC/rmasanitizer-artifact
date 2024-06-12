/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file ShmemSegmentPredefs.h
 *       @see MUST::ShmemSegmentPredefs.
 *
 *  @date 16.02.2023
 *  @author Simon Schwitanski
 */

#include "ModuleBase.h"

#include "I_ShmemSegmentPredefs.h"

#ifndef ShmemSegmentPREDEFS_H
#define ShmemSegmentPREDEFS_H

using namespace gti;

namespace must
{
/**
 * Implementation of I_ShmemSegmentPredefs.
 */
class ShmemSegmentPredefs : public gti::ModuleBase<ShmemSegmentPredefs, I_ShmemSegmentPredefs>
{
  public:
    /**
     * Constructor.
     * @param instanceName name of this module instance.
     */
    ShmemSegmentPredefs(const char* instanceName);

    /**
     * Destructor.
     */
    virtual ~ShmemSegmentPredefs(void);

    /**
     * @see I_ShmemSegmentPredefs::propagate.
     */
    GTI_ANALYSIS_RETURN propagate(MustParallelId pId);

  protected:
  private:
    MustShmemTeamType myBaseAddr;
};
} // namespace must

#endif /*ShmemSegmentPREDEFS_H*/
