/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file ShmemTeamTrack.h
 *       @see MUST::ShmemTeamTrack
 *
 *  @date 16.02.2023
 *  @author Simon Schwitanski
 */

#include "ModuleBase.h"
#include "TrackBase.h"
#include "CompletionTree.h"

#include "I_ShmemTeamTrack.h"
#include "ShmemTeam.h"

#include <map>

#ifndef SHMEMTEAMTTRACK_H
#define SHMEMTEAMTTRACK_H

using namespace gti;

namespace must
{
	/**
     * Implementation for I_ShmemTeamTrack.
     */
    class ShmemTeamTrack : public TrackBase<ShmemTeam, I_ShmemTeam, MustShmemTeamType, MustShmemTeamPredefined, ShmemTeamTrack, I_ShmemTeamTrack>
    {
    public:
        /**
         * Constructor.
         * @param instanceName name of this module instance.
         */
    		ShmemTeamTrack (const char* instanceName);

    		/**
    		 * Destructor.
    		 */
    		virtual ~ShmemTeamTrack (void);


    		/**
    		 * @see I_ShmemTeamTrack::teamDestroy
			 */
			
			GTI_ANALYSIS_RETURN teamDestroy(
					MustParallelId pId,
					MustLocationId lId,
					MustShmemTeamType team);

    		/**
    		 * @see I_ShmemTeamTrack::teamSplit.
    		 */
    		GTI_ANALYSIS_RETURN teamSplit(
					MustParallelId pId,
					MustLocationId lId,
					MustShmemTeamType team,
					MustShmemTeamType newTeam,
					int newTeamSize,
					int *newRank2WorldArray);

    		/**
    		 * @see I_ShmemTeamTrack::addPredefinedTeams.
    		 */
    		GTI_ANALYSIS_RETURN addPredefinedTeams (
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
					gti::I_ChannelId *channId);

    	

    		/**
    		 * @see I_ShmemTeamTrack::getTeam
    		 */
    		I_ShmemTeam* getTeam (
    				MustParallelId pId,
    				MustShmemTeamType team);

    		/**
    		 * @see I_ShmemTeamTrack::getTeam
    		 */
    		I_ShmemTeam* getTeam (
    				int rank,
    				MustShmemTeamType team);

    		/**
    		 * @see I_ShmemTeamTrack::getPersistentTeam
    		 */
    		I_ShmemTeamPersistent* getPersistentTeam (
    		        MustParallelId pId,
    		        MustShmemTeamType team);

    		/**
    		 * @see I_ShmemTeamTrack::getPersistentTeam
    		 */
    		I_ShmemTeamPersistent* getPersistentTeam (
    		        int rank,
    		        MustShmemTeamType team);

    		/**
    		 * @see I_ShmemTeamTrack::notifyOfShutdown
    		 * @see TrackBase::notifyOfShutdown
    		 */
    		void notifyOfShutdown (void);

    protected:
    		I_GroupTrack *myGroupMod; /**< The group tracking module.*/

			std::vector <ShmemTeam*> mySharedTeamInfos; /**< Information for SHMEM_TEAM_SHARED of each rank */
    		std::vector <ShmemTeam*> myWorldTeamInfos; /**< Information for SHMEM_TEAM_WORLD of each rank */
			ShmemTeam* myTeamInvalid;

    		bool myReachableAvailable; /**< Set to true once all information on reachable processes arrived.*/
    		int myReachableBegin; /**< Beginning SHMEM_TEAM_WORLD rank of reachable processes.*/
    		int myReachableEnd; /**< Last SHMEM_TEAM_WORLD rank of reachable processes.*/

    		std::map<int, MustShmemTeamType> myTeamSharedHandles; //maps a rank to its shared team handle
    		std::map<int, MustShmemTeamType> myTeamWorldHandles; //maps a rank to its world team
			MustShmemTeamType myTeamInvalidValue;

    		/**
    		 * Returns the full team information for the given team and context.
    		 * Returns an info for user, predefined and null teams.
    		 *
    		 * We can't use TrackBase::getHandleInfo here as we have a specialized handling of
    		 * SHMEM_TEAM_WORLD and SHMEM_TEAM_Shared as predefineds!
    		 *
    		 * @param pId context for team.
    		 * @param team to query for.
    		 * @return the team in question or NULL if not found.
    		 */
    		ShmemTeam* getTeamInfo (
    				MustParallelId pId,
    				MustShmemTeamType team);

    		/**
    		 * @see other getTeamInfo, difference is pid.
    		 */
    		ShmemTeam* getTeamInfo (
    				int rank,
    				MustShmemTeamType team);

    }; /*class ShmemTeamTrack */
} /*namespace MUST*/

#endif /*SHMEMTEAMTTRACK_H*/
