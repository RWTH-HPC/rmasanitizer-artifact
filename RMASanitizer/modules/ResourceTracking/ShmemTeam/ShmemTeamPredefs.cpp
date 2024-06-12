/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file ShmemTeamPredefs.cpp
 *       @see MUST::ShmemTeamPredefs
 *
 *  @date 16.02.2023
 *  @author Simon Schwitanski
 */

#include "GtiEnums.h"
#include "GtiMacros.h"
#include "MustEnums.h"
#include "ResourceApi.h"
#include "mustConfig.h"
#include "BaseShmemHandling.h"
#include "ShmemTeamPredefs.h"

#include <pshmem.h>

using namespace must;

mGET_INSTANCE_FUNCTION(ShmemTeamPredefs)
mFREE_INSTANCE_FUNCTION(ShmemTeamPredefs)
mPNMPI_REGISTRATIONPOINT_FUNCTION(ShmemTeamPredefs)

//=============================
// Constructor
//=============================
ShmemTeamPredefs::ShmemTeamPredefs (const char* instanceName)
    : gti::ModuleBase<ShmemTeamPredefs, I_ShmemTeamPredefs> (instanceName)
{
    //create sub modules
    std::vector<I_Module*> subModInstances;
    subModInstances = createSubModuleInstances ();

    //handle sub modules
    if (subModInstances.size() > 0)
    {
        for (std::vector<I_Module*>::size_type i = 0; i < subModInstances.size(); i++)
            destroySubModuleInstance (subModInstances[i]);
    }

    //No sub modules needed

    //Initialize module data
    //Nothing to do
}

//=============================
// Destructor
//=============================
ShmemTeamPredefs::~ShmemTeamPredefs ()
{
	//nothing to do
}

//=============================
// propagate
//=============================
GTI_ANALYSIS_RETURN ShmemTeamPredefs::propagate (
                MustParallelId pId
)
{
	//==Call the API call to propagate the team information to I_ShmemTeamTrack
	propagateShmemTeamsP fP;
	if (getWrapperFunction ("propagateShmemTeams", (GTI_Fct_t*)&fP) == GTI_SUCCESS)
	{
		// We rely here on the fact that the split communicator module is used.
		int size = pshmem_team_n_pes(SHMEM_TEAM_WORLD);
		int rank = pshmem_team_my_pe(SHMEM_TEAM_WORLD);

		MustShmemTeamType sharedF = BaseShmem_ShmemTeam2int(SHMEM_TEAM_SHARED);
		MustShmemTeamType worldF = BaseShmem_ShmemTeam2int(SHMEM_TEAM_WORLD);

		(*fP) (
            pId,
			rank,
			rank,
			size,
			BaseShmem_ShmemTeam2int(SHMEM_TEAM_INVALID),
			BaseShmem_ShmemTeam2int(SHMEM_TEAM_SHARED),
			BaseShmem_ShmemTeam2int(SHMEM_TEAM_WORLD),
			1,
			&sharedF,
			1,
			&worldF
			);
	}

	return GTI_ANALYSIS_SUCCESS;
}

/*EOF*/
