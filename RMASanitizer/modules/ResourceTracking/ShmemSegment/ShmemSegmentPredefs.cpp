/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file ShmemSegmentPredefs.cpp
 *       @see MUST::ShmemSegmentPredefs
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
#include "ShmemSegmentPredefs.h"

#include <pshmem.h>
#include <dlfcn.h>

using namespace must;

mGET_INSTANCE_FUNCTION(ShmemSegmentPredefs)
mFREE_INSTANCE_FUNCTION(ShmemSegmentPredefs)
mPNMPI_REGISTRATIONPOINT_FUNCTION(ShmemSegmentPredefs)

//=============================
// Constructor
//=============================
ShmemSegmentPredefs::ShmemSegmentPredefs(const char* instanceName)
    : gti::ModuleBase<ShmemSegmentPredefs, I_ShmemSegmentPredefs>(instanceName)
{
    // create sub modules
    std::vector<I_Module*> subModInstances;
    subModInstances = createSubModuleInstances();

    // handle sub modules
    if (subModInstances.size() > 0) {
        for (std::vector<I_Module*>::size_type i = 0; i < subModInstances.size(); i++)
            destroySubModuleInstance(subModInstances[i]);
    }

    // No sub modules needed

    // Initialize module data
    // Nothing to do

    // get the base address for the default segment, this has to be done in the constructor to get
    // the right address
    void* codeptr;
    PNMPI_Service_GetReturnAddress(&codeptr);
    Dl_info info;
    dladdr(codeptr, &info);
    myBaseAddr = (MustShmemTeamType)info.dli_fbase;
}

//=============================
// Destructor
//=============================
ShmemSegmentPredefs::~ShmemSegmentPredefs()
{
    // nothing to do
}

//=============================
// propagate
//=============================
GTI_ANALYSIS_RETURN ShmemSegmentPredefs::propagate(MustParallelId pId)
{
    //==Call the API call to propagate the segment information to I_ShmemSegmentTrack
    propagateShmemSegmentsP fP;
    if (getWrapperFunction("propagateShmemSegments", (GTI_Fct_t*)&fP) == GTI_SUCCESS) {
        // We rely here on the fact that the split communicator module is used.
        int size = pshmem_team_n_pes(SHMEM_TEAM_WORLD);
        int rank = pshmem_team_my_pe(SHMEM_TEAM_WORLD);

        // propagate the base address of the default segment
        (*fP)(pId, rank, rank, size, (MustShmemTeamType)myBaseAddr, &myBaseAddr, 1);
    }

    return GTI_ANALYSIS_SUCCESS;
}

/*EOF*/
