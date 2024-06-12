/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file GASPIVectorClockWrapper.cpp
 *       @see I_GASPIVectorClockWrapper.h.
 *
 *  @date 29.06.2021
 *  @author Felix Tomski
 */

#include "GASPIVectorClockWrapper.h"
#include "GtiMacros.h"
#include "PrefixedOstream.hpp"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <GASPI.h>
#include <PGASPI.h>

using namespace must;

mGET_INSTANCE_FUNCTION(GASPIVectorClockWrapper)
mFREE_INSTANCE_FUNCTION(GASPIVectorClockWrapper)
mPNMPI_REGISTRATIONPOINT_FUNCTION(GASPIVectorClockWrapper)

// Debug func
std::ostream& operator<<(std::ostream& s, const AbstractClock& c)
{
    s << "(";
    for (int i = 0; i < c.size(); i++)
        s << c.data()[i] << (i < c.size() - 1 ? ", " : "");
    s << ")";
    return s;
}

// Returns a sorted vector of all rank ids that participate in the given group
std::vector<int> getGroupRanks(MustGASPIGroupType const& group)
{
    gaspi_number_t group_size = 0;
    pgaspi_group_size(group, &group_size);
    gaspi_rank_t* group_ranks = (gaspi_rank_t*)std::malloc(sizeof(gaspi_rank_t) * group_size);
    pgaspi_group_ranks(group, group_ranks);
    std::vector<int> group_rank_vec;
    for (int i = 0; i < group_size; i++) {
        group_rank_vec.push_back(group_ranks[i]);
    }
    std::free(group_ranks);
    std::sort(group_rank_vec.begin(), group_rank_vec.end());
    return group_rank_vec;
}

// Returns an integer identifiert for group
inline uint64_t groupIdent(std::vector<int> groupRanks, int numProcs)
{
    uint64_t res = 0;
    for (int x : groupRanks) {
        res += x + 1; // Make sure zero is not a noop
        res *= std::log10(numProcs);
    }
    return res;
}

//=============================
// Constructor
//=============================
GASPIVectorClockWrapper::GASPIVectorClockWrapper(const char* instanceName)
    : gti::ModuleBase<GASPIVectorClockWrapper, I_GASPIVectorClockWrapper>(instanceName)
{
    // create sub modules
    std::vector<I_Module*> subModInstances;
    subModInstances = createSubModuleInstances();

    // handle sub modules
#define NUM_SUBMODULES 1
    if (subModInstances.size() < NUM_SUBMODULES) {
        cout << "Module has not enough sub modules, check its analysis "
                "specification! ("
             << __FILE__ << "@" << __LINE__ << ")" << std::endl;
        assert(0);
    }
    if (subModInstances.size() > NUM_SUBMODULES) {
        for (std::vector<I_Module*>::size_type i = NUM_SUBMODULES; i < subModInstances.size(); i++)
            destroySubModuleInstance(subModInstances[i]);
    }

    myVectorClockMod = (I_VectorClock*)subModInstances[0];
}

//=============================
// Destructor
//=============================
GASPIVectorClockWrapper::~GASPIVectorClockWrapper()
{
    if (myVectorClockMod)
        destroySubModuleInstance((I_Module*)myVectorClockMod);
    myVectorClockMod = NULL;
}

//=============================
// tick
//=============================
GTI_ANALYSIS_RETURN GASPIVectorClockWrapper::tick()
{
    GTI_ANALYSIS_RETURN retval = myVectorClockMod->tick();
#ifdef MUST_DEBUG
    if (retval == GTI_ANALYSIS_SUCCESS) {
        cout << "[GASPI_VC_Wrapper|" << myProcRank << "] tick" << myVectorClockMod->getClock()
             << "\n";
    }
#endif
    return retval;
}

//=============================
// init | gaspi_proc_init
//=============================
GTI_ANALYSIS_RETURN GASPIVectorClockWrapper::init()
{
    // Get number of processes, and current rank
    // TODO: GASPI supports adding more processes, invalidating current count
    pgaspi_proc_num(&numProcs);
    pgaspi_proc_rank(&myProcRank);
#ifdef MUST_DEBUG
    cout << "[GASPI_VC_Wrapper|" << myProcRank << "]"
         << " Initialized of total " << numProcs << "\n";
#endif
    return GTI_ANALYSIS_SUCCESS;
}

//=============================
// allToAll | gaspi_barrier, gaspi_group_commit
//=============================
GTI_ANALYSIS_RETURN GASPIVectorClockWrapper::allToAll(MustParallelId pId, MustGASPIGroupType group)
{
    std::vector<int> groupRanks = getGroupRanks(group);
    // Can't use actual values due to deadlock if rank 0 does not participate. Need to create manual
    // map
    auto itr = std::find(groupRanks.begin(), groupRanks.end(), myProcRank);
    if (itr == groupRanks.end()) {
        // allToAll could be barrier or group commit. On barrier, behavior is weird. On commit,
        // noop. Assume latter here
        // TODO: Handle procs outside group for barrier
        return GTI_ANALYSIS_SUCCESS;
    }
    int rank_index = (int)(itr - groupRanks.begin());
    GTI_ANALYSIS_RETURN retval =
        myVectorClockMod
            ->allToAll(groupRanks, groupIdent(groupRanks, numProcs), rank_index, 0, groupRanks[0]);
#ifdef MUST_DEBUG
    if (retval == GTI_ANALYSIS_SUCCESS) {
        cout << "[GASPI_VC_Wrapper|" << myProcRank << "] allToAll" << myVectorClockMod->getClock()
             << "\n";
    }
#endif
    return retval;
}

//=============================
// signalResource | gaspi_notify, gaspi_write_notify, gaspi_write_list_notify
//=============================
GTI_ANALYSIS_RETURN GASPIVectorClockWrapper::signalResource(
    MustParallelId pId,
    MustGASPIRankType target_rank,
    MustGASPINotificationIDType notify_id)
{
    GTI_ANALYSIS_RETURN retval = myVectorClockMod->unlock(notify_id, target_rank);
#ifdef MUST_DEBUG
    if (retval == GTI_ANALYSIS_SUCCESS) {
        cout << "[GASPI_VC_Wrapper|" << myProcRank << "] signalResource"
             << myVectorClockMod->getClock() << "\n";
    }
#endif
    return retval;
}

//=============================
// signalResourceLocal | gaspi_read_notify, gaspi_read_list_notify
//=============================
GTI_ANALYSIS_RETURN GASPIVectorClockWrapper::signalResourceLocal(
    MustParallelId pId,
    MustGASPINotificationIDType notify_id)
{
    GTI_ANALYSIS_RETURN retval = myVectorClockMod->unlock(notify_id, myProcRank);
#ifdef MUST_DEBUG
    if (retval == GTI_ANALYSIS_SUCCESS) {
        cout << "[GASPI_VC_Wrapper|" << myProcRank << "] signalResourceLocal"
             << myVectorClockMod->getClock() << "\n";
    }
#endif
    return retval;
}

//=============================
// waitResource | gaspi_notify_waitsome
//=============================
GTI_ANALYSIS_RETURN GASPIVectorClockWrapper::waitResource(
    MustParallelId pId,
    MustGASPINotificationIDType firstId,
    MustGASPINumberType notify_num)
{
    // Only the notification of firstId is guaranteed to be completed
    GTI_ANALYSIS_RETURN retval = myVectorClockMod->lock(firstId, myProcRank);
#ifdef MUST_DEBUG
    cout << "[GASPI_VC_Wrapper|" << myProcRank << "] waitResource" << myVectorClockMod->getClock()
         << "\n";
#endif
    return retval;
}

//=============================
// signal | gaspi_passive_send
//=============================
GTI_ANALYSIS_RETURN
GASPIVectorClockWrapper::signal(MustParallelId pId, MustGASPIRankType target_rank)
{
    GTI_ANALYSIS_RETURN retval = myVectorClockMod->signal(true, target_rank, GASPI_GROUP_ALL);
#ifdef MUST_DEBUG
    if (retval == GTI_ANALYSIS_SUCCESS)
        cout << "[GASPI_VC_Wrapper|" << myProcRank << "] signal" << myVectorClockMod->getClock()
             << "\n";
#endif
    return retval;
}

//=============================
// wait | gaspi_passive_receive
//=============================
GTI_ANALYSIS_RETURN GASPIVectorClockWrapper::wait(MustParallelId pId, MustGASPIRankType orig_rank)
{
    GTI_ANALYSIS_RETURN retval = myVectorClockMod->waitForSignal(orig_rank, GASPI_GROUP_ALL);
#ifdef MUST_DEBUG
    if (retval == GTI_ANALYSIS_SUCCESS)
        cout << "[GASPI_VC_Wrapper|" << myProcRank << "] wait" << myVectorClockMod->getClock()
             << "\n";
#endif
    return retval;
}
