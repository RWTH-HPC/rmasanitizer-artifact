/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file ShmemTeamPredefs.h
 *       @see MUST::ShmemTeamPredefs.
 *
 *  @date 16.02.2023
 *  @author Simon Schwitanski
 */

#include "ModuleBase.h"

#include "I_ShmemTeamPredefs.h"

#ifndef SHMEMTEAMPREDEFS_H
#define SHMEMTEAMPREDEFS_H

using namespace gti;

namespace must
{
	/**
     * Implementation of I_ShmemTeamPredefs.
     */
    class ShmemTeamPredefs : public gti::ModuleBase<ShmemTeamPredefs, I_ShmemTeamPredefs>
    {
    public:
        /**
         * Constructor.
         * @param instanceName name of this module instance.
         */
    		ShmemTeamPredefs (const char* instanceName);

    		/**
    		 * Destructor.
    		 */
    		virtual ~ShmemTeamPredefs (void);

    		/**
    		 * @see I_ShmemTeamPredefs::propagate.
    		 */
    		GTI_ANALYSIS_RETURN propagate (
                MustParallelId pId
            );

    protected:

    };
} /*namespace MUST*/

#endif /*SHMEMTEAMPREDEFS_H*/
