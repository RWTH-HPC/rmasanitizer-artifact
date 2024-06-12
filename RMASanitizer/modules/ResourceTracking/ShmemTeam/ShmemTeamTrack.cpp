/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file ShmemTeamTrack.cpp
 *       @see MUST::ShmemTeamTrack.
 *
 *  @date 16.02.2023
 *  @author Simon Schwitanski
 */

#include "GtiEnums.h"
#include "GtiMacros.h"
#include "MustEnums.h"
#include "PrefixedOstream.hpp"

#include "ShmemTeamTrack.h"
#include "I_Group.h"

#include <sstream>
#include <utility>
#include <tuple>
#include <pnmpimod.h>
#include <assert.h>

using namespace must;

mGET_INSTANCE_FUNCTION(ShmemTeamTrack)
mFREE_INSTANCE_FUNCTION(ShmemTeamTrack)
mPNMPI_REGISTRATIONPOINT_FUNCTION(ShmemTeamTrack)

#define CONTEXTID_MULTIPLIER 128

//=============================
// Constructor
//=============================
ShmemTeamTrack::ShmemTeamTrack (const char* instanceName)
	: TrackBase<ShmemTeam, I_ShmemTeam, MustShmemTeamType, MustShmemTeamPredefined, ShmemTeamTrack, I_ShmemTeamTrack> (instanceName),
	  mySharedTeamInfos (),
	  myWorldTeamInfos (),
	  myReachableAvailable (false),
	  myReachableBegin (-1),
	  myReachableEnd (-1),
	  myTeamSharedHandles (),
	  myTeamWorldHandles (),
	  myTeamInvalid(nullptr)
{
    //Get the GroupTrack module
	if (myFurtherMods.size () < 1)
	{
		must::cerr << "Error: the ShmemTrack module needs the GroupTrack module as a child, but it was not specified." << std::endl;
		assert (0);
	}

	myGroupMod = (I_GroupTrack*) myFurtherMods[0];
}

//=============================
// Destructor
//=============================
ShmemTeamTrack::~ShmemTeamTrack ()
{
    //Notify HandleInfoBase of ongoing shutdown
    HandleInfoBase::disableFreeForwardingAcross();
    myGroupMod->notifyOfShutdown();

	//User handles and predefineds are freed by TrackBase, modules too.
    myGroupMod = NULL;

	// TODO: Clean up is currently not working as intended

// 	//Free data
// 	for (std::vector<I_Module*>::size_type i = 0; i < myWorldTeamInfos.size(); i++)
// 	{
// 	    if (!myWorldTeamInfos[i]->mpiErase())
// 	    {
// #ifdef MUST_DEBUG
//             must::cout << "Warning: A SHMEM_TEAM_WORLD handle was queried for in a persistent way and was not freed." << std::endl;
// #endif
// 	    }
// 	}

// 	for (std::vector<I_Module*>::size_type i = 0; i < mySharedTeamInfos.size(); i++)
// 	{
// 	    if (!mySharedTeamInfos[i]->mpiErase())
// 	    {
// #ifdef MUST_DEBUG
//             must::cout << "Warning: A SHMEM_TEAM_SHARED handle was queried for in a persistent way and was not freed." << std::endl;
// #endif
// 	    }
// 	}

    myWorldTeamInfos.clear();
	mySharedTeamInfos.clear();
}



//=============================
// teamDestroy
//=============================
GTI_ANALYSIS_RETURN ShmemTeamTrack::teamDestroy(
		MustParallelId pId,
		MustLocationId lId,
		MustShmemTeamType team)
{
	// Apply the free
	removeUserHandle (pId,team);

	return GTI_ANALYSIS_SUCCESS;
}

//=============================
// teamSplit
//=============================
GTI_ANALYSIS_RETURN ShmemTeamTrack::teamSplit(
		MustParallelId pId,
		MustLocationId lId,
		MustShmemTeamType parentTeam,
		MustShmemTeamType newTeam,
		int newTeamSize,
		int *newRank2WorldArray)
{
	//==1) Get information for the parent team, abort if unknown or null
    ShmemTeam *tInfo;
    tInfo = getTeamInfo (pId2Rank(pId), parentTeam);

    if (!tInfo || tInfo->isInvalid())
        return GTI_ANALYSIS_SUCCESS; //if not found or null handle, simply return (we don't do correctness checking here)

	// Increment next context of parent team now
	tInfo->myNextContextId = tInfo->myNextContextId + 1;

	//==2) Abort if new team is null or a predefined value
	{
          auto s_safe_Predefineds = slock_safe_ptr(myPredefineds);
          if (s_safe_Predefineds->find(newTeam) != s_safe_Predefineds->end() ||
              newTeam == myTeamInvalidValue)
            return GTI_ANALYSIS_SUCCESS;
	}

	//==2b) Create the set for the new group
	std::vector<int> group;
	group.resize(newTeamSize);
	for (int i = 0; i < newTeamSize; i++)
		group[i] = newRank2WorldArray[i];

	//==3) Create the full information for the new team
	ShmemTeam *newInfo = new ShmemTeam (this);

	newInfo->myGroup =  myGroupMod->getGroupTable(group);
	newInfo->myCreationPId = pId;
	newInfo->myCreationLId = lId;

	//context
	newInfo->myContextId = tInfo->myNextContextId - 1;
	newInfo->myNextContextId = CONTEXTID_MULTIPLIER * tInfo->myNextContextId;

	//==4) Register the new team
	submitUserHandle (pId, newTeam, newInfo);

	return GTI_ANALYSIS_SUCCESS;
}


//=============================
// addPredefineds
//=============================
GTI_ANALYSIS_RETURN ShmemTeamTrack::addPredefinedTeams (
					MustParallelId pId,
					int reachableBegin,
					int reachableEnd,
					int worldSize,
					MustShmemTeamType teamInvalid,
					MustShmemTeamType teamShared,
					MustShmemTeamType teamWorld,
					int numShareds,
					MustShmemTeamType* shareds,
					int numWorlds,
					MustShmemTeamType* worlds,
					gti::I_ChannelId *channId)
{
	//Adept reachable interval
	if (myReachableBegin < 0)
	{
	    getReachableRanks (&myReachableBegin, &myReachableEnd, reachableBegin);
            myReachableAvailable = true;
	}

	//Gather the different values for SHMEM_TEAM_SHARED
	for (int i = reachableBegin; i < reachableBegin+numShareds; i++)
	{
		myTeamSharedHandles.insert (std::make_pair(i, shareds[i-reachableBegin]));
	}

	//Gather the different values for SHMEM_TEAM_WORLD
	for (int i = reachableBegin; i < reachableBegin+numWorlds; i++)
	{
		myTeamWorldHandles.insert (std::make_pair(i, worlds[i-reachableBegin]));
	}

#ifdef MUST_DEBUG
	std::map<int, MustShmemTeamType>::iterator iter;

	must::cout << "ShmemTeamTrack: addPredefineds, MPI_TEAM_WORLD values: ";
	for (iter = myTeamWorldHandles.begin(); iter != myTeamWorldHandles.end(); iter++)
	{
		if (iter != myTeamWorldHandles.begin()) must::cout << ", ";
		must::cout << iter->first << "->" << iter->second;
	}
	must::cout << std::endl;

	must::cout << "ShmemTeamTrack: addPredefineds, MPI_TEAM_SHARED values: ";
	for (iter = myTeamSharedHandles.begin(); iter != myTeamSharedHandles.end(); iter++)
	{
		if (iter != myTeamSharedHandles.begin()) must::cout << ", ";
		must::cout << iter->first << "->" << iter->second;
	}
	must::cout << std::endl;
#endif

	/*
	 * We need one full info for each rank to make
	 * their context ids independent!
	 */
	if (myWorldTeamInfos.size() != worldSize)
		myWorldTeamInfos.resize(worldSize);

	if (mySharedTeamInfos.size() != worldSize)
		mySharedTeamInfos.resize(worldSize);

	for (int i = reachableBegin; i < reachableBegin+numWorlds; i++)
	{
		myWorldTeamInfos[i] = new ShmemTeam (this);
		myWorldTeamInfos[i]->myIsInvalid = false;
		myWorldTeamInfos[i]->myIsPredefined = true;
		myWorldTeamInfos[i]->myGroup = myGroupMod->getGroupTable (0, worldSize-1); //Interval group with ranks 0-(worldSize-1) were no mapping is needed;
		myWorldTeamInfos[i]->myPredefinedName = "SHMEM_TEAM_WORLD";
		myWorldTeamInfos[i]->myPredefined = MUST_SHMEM_TEAM_WORLD;
	}

	for (int i = reachableBegin; i < reachableBegin+numShareds; i++)
	{
		mySharedTeamInfos[i] = new ShmemTeam (this);
		mySharedTeamInfos[i]->myIsInvalid = false;
		mySharedTeamInfos[i]->myIsPredefined = true;
		mySharedTeamInfos[i]->myGroup = myGroupMod->getGroupTable (0, worldSize-1); //Interval group with ranks 0-(worldSize-1) were no mapping is needed;
		mySharedTeamInfos[i]->myPredefinedName = "SHMEM_TEAM_SHARED";
		mySharedTeamInfos[i]->myPredefined = MUST_SHMEM_TEAM_SHARED;
	}


	if (myTeamInvalid)
		return GTI_ANALYSIS_SUCCESS;

    myTeamInvalid = new ShmemTeam (this);
	myTeamInvalidValue = teamInvalid;
    myTeamInvalid->myIsInvalid = true;

// 	//Call addPredefineds of TrackBase
// 	int predefEnumIds[2] = {(int)MUST_MPI_ShmemTeam_SELF, (int)MUST_MPI_ShmemTeam_WORLD};
// 	MustShmemTeamType predefValues[2] = {commSelf, commWorld};
// 	TrackBase<Comm, I_ShmemTeam, MustShmemTeamType, MustMpiCommPredefined, ShmemTeamTrack, I_ShmemTeamTrack>::addPredefineds (
//             pId,
// 			commNull,
// 			2,
// 			predefEnumIds,
// 			predefValues
// 			);

    return GTI_ANALYSIS_SUCCESS;
}


//=============================
// getShmemTeam
//=============================
I_ShmemTeam* ShmemTeamTrack::getTeam (
		MustParallelId pId,
		MustShmemTeamType team)
{
	return getTeam (pId2Rank (pId), team);
}

//=============================
// getShmemTeam
//=============================
I_ShmemTeam* ShmemTeamTrack::getTeam (
		int rank,
		MustShmemTeamType team)
{
	return getTeamInfo (rank, team);
}

//=============================
// getPersistentTeam
//=============================
I_ShmemTeamPersistent* ShmemTeamTrack::getPersistentTeam (
        MustParallelId pId,
        MustShmemTeamType team)
{
    return getPersistentTeam (pId2Rank (pId), team);
}

//=============================
// getPersistentTeam
//=============================
I_ShmemTeamPersistent* ShmemTeamTrack::getPersistentTeam (
        int rank,
        MustShmemTeamType team)
{
    ShmemTeam* ret = getTeamInfo (rank, team);;
    if (ret) ret->incRefCount();
    return ret;
}

//=============================
// getShmemTeamInfo
//=============================
ShmemTeam* ShmemTeamTrack::getTeamInfo (
		MustParallelId pId,
		MustShmemTeamType team)
{
	return getTeamInfo (pId2Rank (pId), team);
}

//=============================
// getShmemTeamInfo
//=============================
ShmemTeam* ShmemTeamTrack::getTeamInfo (
		int rank,
		MustShmemTeamType team)
{
	//Is it a user defined type ?
	HandleMap::const_iterator pos = findUserHandle(rank, team);

	if (pos == slock_safe_ptr(myUserHandles)->end()) {
		// If not a user team-> it must be null or a predefined
		if (team == myNullValue)
			return myNullInfo;

		std::map<int, MustShmemTeamType>::iterator wHI =
			myTeamWorldHandles.find(rank);
		if (wHI != myTeamWorldHandles.end() &&
			(wHI->second == team)) {
			return myWorldTeamInfos[rank];
		}
		wHI = myTeamSharedHandles.find(rank);
		if (wHI != myTeamSharedHandles.end() &&
			(wHI->second == team)) {
			return mySharedTeamInfos[rank];
		}
	} else {
		return pos->second;
	}

	return NULL;
}

//=============================
// notifyOfShutdown
//=============================
void ShmemTeamTrack::notifyOfShutdown (void)
{
    TrackBase<ShmemTeam, I_ShmemTeam, MustShmemTeamType, MustShmemTeamPredefined, ShmemTeamTrack, I_ShmemTeamTrack>::notifyOfShutdown ();
    if (myGroupMod) myGroupMod->notifyOfShutdown();
}

/*EOF*/
