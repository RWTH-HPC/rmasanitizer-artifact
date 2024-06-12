/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file I_ShmemTeamTrack.h
 *       @see I_ShmemTeamTrack.
 *
 *  @date 16.02.2023
 *  @author Simon Schwitanski
 */

#include "I_Module.h"
#include "GtiEnums.h"

#include "MustEnums.h"
#include "MustTypes.h"
#include "BaseIds.h"
#include "I_ChannelId.h"
#include "I_GroupTrack.h"
#include "I_GroupTable.h"
#include "I_ShmemTeam.h"
#include "I_TrackBase.h"

#include <mpi.h>
#include <list>

#ifndef I_SHMEMTEAMTRACK_H
#define I_SHMEMTEAMTRACK_H

/**
 * Interface for querying information on SHMEM teams.
 *
 * Important: This analysis module only tracks teams,
 * it provides no correctness checking. However, it tries
 * to handle incorrect actions as good as possible.
 *
 * Dependencies (in listed order):
 * - ParallelIdAnalysis
 * - LocationAnalysis
 * - GroupTrack
 */
class I_ShmemTeamTrack : public gti::I_Module, public virtual must::I_TrackBase<must::I_ShmemTeam>
{
public:

	/**
	 * Frees a team.
	 *
	 * @param pId parallel id of call site.
	 * @param lId location id of call site.
	 * @param team team to free
	 * @return see gti::GTI_ANALYSIS_RETURN.
	 */
	virtual gti::GTI_ANALYSIS_RETURN teamDestroy(
			MustParallelId pId,
			MustLocationId lId,
			MustShmemTeamType team) = 0;

	/**
	 * Splits a team into another.
	 *
	 * @param pId parallel id of call site.
	 * @param lId location id of call site.
	 * @param team to split.
	 * @param newteam handle of the new team.
	 * @param newTeamSize number of processes in the
	 *               group associated with newTeam.
	 * @param newRank2WorldArray array of newTeam group
	 *               ranks to SHMEM_TEAM_WORLD rank translations.
	 * @return see gti::GTI_ANALYSIS_RETURN.
	 */
	virtual gti::GTI_ANALYSIS_RETURN teamSplit(
			MustParallelId pId,
			MustLocationId lId,
			MustShmemTeamType team,
			MustShmemTeamType newTeam,
			int newTeamSize,
			int *newRank2WorldArray) = 0;

	/**
	 * Adds the predefineds and important values for them
	 * like the list of processes reachable by this place.
	 *
	 * The extra channel id is used to track whether the reachable
	 * interval is already complete, or whether some processes
	 * are missing.
	 *
	 *
	 * @param reachableBegin start of interval of processes reachable by this place.
    	 * @param reachableEnd end of interval of processes reachable by this place.
    	 * @param worldSize size of SHMEM_TEAM_WORLD
    	 * @param teamInvalid value of the real SHMEM_TEAM_INVALID constant
		 * @param teamShared value of the real SHMEM_TEAM_SHARED constant
		 * @param teamWorld value of the real SHMEM_TEAM_WORLD constant
		 * @param numShareds number of SHMEM_TEAM_SHARED values in list.
    	 * @param shareds values for SHMEM_TEAM_SHARED on each task (Value of the possibly replaced SHMEM_TEAM_SHARED, can differ on each rank e.g. Sandia SHMEM).
    	 * @param numWorlds number of SHMEM_TEAM_WORLD values in list.
    	 * @param worlds values for SHMEM_TEAM_WORLD on each task (Value of the possibly replaced SHMEM_TEAM_WORLD, can differ on each rank e.g. Sandia SHMEM).
    	 * @param channId channel id of this record.
	 */
    virtual gti::GTI_ANALYSIS_RETURN addPredefinedTeams (
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
    		gti::I_ChannelId *channId) = 0;

	/**
	 * Returns pointer to team information.
	 * Is NULL if this is an unknown handle.
	 *
	 * Memory must not be freed and is valid until I_ShmemTeamTrack
	 * receives the next event, if you need the information longer
	 * query getPersistentTeam instead.
	 *
	 * @param pId of the team context.
	 * @param team to query for.
	 * @return information for the given team.
	 */
    virtual must::I_ShmemTeam* getTeam (
    		MustParallelId pId,
    		MustShmemTeamType team) = 0;

    /** As I_ShmemTeamTrack::getTeam with rank instead of pid.*/
    virtual must::I_ShmemTeam* getTeam (
    		int rank,
    		MustShmemTeamType team) = 0;

    /**
     * Like I_ShmemTeamTrack::getTeam, though returns a persistent information
     * that is valid until you erase it, i.e.:
     *@code
     I_TeamPersistent * teamInfo = myTeamTrack->getPersistentTeam (pId, handle);
     if (teamInfo == NULL) return;
     .... //Do something with teamInfo
     teamInfo->erase(); //Mark as not needed any longer
     *@endcode
     *
     * A reference count mechanism is used to implement this.
     *
     * @param pId of the team context.
     * @param team to query for.
     * @return information for the given team.
     */
    virtual must::I_ShmemTeamPersistent* getPersistentTeam (
            MustParallelId pId,
            MustShmemTeamType team) = 0;

    /** As I_ShmemTeamTrack::getPersistentTeam with rank instead of pid.*/
    virtual must::I_ShmemTeamPersistent* getPersistentTeam (
            int rank,
            MustShmemTeamType team) = 0;

	/**
	 * Returns a list of all currently known user handles.
	 * Usage scenarios involve logging lost handles at finalize.
	 * @return a list of pairs of the form (rank, handle id).
	 */
	virtual std::list<std::pair<int, MustShmemTeamType> > getUserHandles (void) = 0;

	/**
	 * Allows other modules to notify this module of an ongoing shutdown.
	 * This influcences the behavior of passing free calls across to other layers.
	 */
	virtual void notifyOfShutdown (void) = 0;

    virtual bool isPredefined(must::I_ShmemTeam * info) {return info->isPredefined();}  
    
}; /*class I_ShmemTeamTrack*/

#endif /*I_SHMEMTEAMTRACK_H*/
