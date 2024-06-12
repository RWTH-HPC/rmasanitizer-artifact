/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file I_ShmemTeam.h
 *       @see I_ShmemTeam.
 *
 *  @date 14.02.2023
 *  @author Simon Schwitanski
 */

#include "I_ShmemTeam.h"
#include "I_ShmemTeamTrack.h"
#include "HandleInfoBase.h"

#ifndef SHMEM_TEAM_H
#define SHMEM_TEAM_H

namespace must
{
    /**
     * Implementation of I_ShmemTeam (and I_ShmemTeamPersistent).
     */
    class ShmemTeam : public I_ShmemTeamPersistent, public HandleInfoBase
    {
    public:
        /**
         * Constructor.
         * Initializes as a MUST_SHMEM_TEAM_UNKNOWN info.
         */
        ShmemTeam ();

        /**
         * Constructor.
         */
        ShmemTeam (I_ShmemTeamTrack* teamTrack);

        /**
         * Destructor.
         */
        ~ShmemTeam ();

        bool isPredefined (void) const; /**< @see I_ShmemTeam::isPredefined.*/
        I_GroupTable* getGroup (void) const; /**< @see I_ShmemTeam::group.*/
        unsigned long long getContextId (void); /**< @see I_ShmemTeam::contextId.*/
        unsigned long long getNextContextId (void); /**< @see I_ShmemTeam::getNextContextId.*/
        MustParallelId getCreationPId (void); /**< @see I_ShmemTeam::creationPId.*/
        MustLocationId getCreationLId (void); /**< @see I_ShmemTeam::creationLId.*/
        MustShmemTeamPredefined getPredefinedInfo (void); /**< @see I_ShmemTeam::getPredefinedInfo.*/
        bool isInvalid(void) const;
        bool compareTeams (I_ShmemTeam* other); /**< @see I_ShmemTeam::compareTeams.*/
        bool operator == (I_ShmemTeam &other); /**< @see I_ShmemTeam::operator==.*/
        bool operator != (I_ShmemTeam &other); /**< @see I_ShmemTeam::operator!=.*/
        std::string getResourceName (void);
        bool printInfo (std::stringstream &out, std::list<std::pair<MustParallelId,MustLocationId> > *pReferences);

    public:
        bool myIsPredefined;
        MustShmemTeamPredefined myPredefined;
        std::string myPredefinedName;

        /**
         * Identifiers that areused to compare teams (comparison not fully implemented yet)
         */
        unsigned long long myContextId;
        unsigned long long myNextContextId; /**< Value of the next context id for team creating calls on this team.*/

        I_GroupTable *myGroup;

        // Only for user defined teams
        MustParallelId myCreationPId;
        MustLocationId myCreationLId;

        // Backreference to creating teamTrack
        I_ShmemTeamTrack* myTeamTrack;

        // True if this is SHMEM_TEAM_INVALID
        bool myIsInvalid;

    };/*class ShmemTeam*/
}/*namespace must*/

#endif /*SHMEM_TEAM_H*/

