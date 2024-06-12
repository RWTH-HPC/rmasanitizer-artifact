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

#include "MustTypes.h"
#include "MustEnums.h"
#include "BaseIds.h"

#include "I_GroupTable.h"
#include "I_Destructable.h"

#include <sstream>
#include <list>

#ifndef I_SHMEM_TEAM_H
#define I_SHMEM_TEAM_H

namespace must
{
    /**
     * Interface for storage and accessing Information
     * on a team as defined in OpenSHMEM.
     */
    class I_ShmemTeam
    {
    public:
        /*
         * Basic information for a team handle.
         */
        virtual bool isPredefined (void) const = 0; /**< True if this type is predefined*/

        bool isInvalid(void) const; /* True is this is SHMEM_TEAM_INVALID */

        virtual must::I_GroupTable *getGroup (void) const = 0; /**< The group of PEs.*/

        //For all known and non-null teams
        virtual unsigned long long getContextId (void) = 0; /**< The id that determines whether two team handles with equal groups actually refer to the same team or not.*/

        //Provide a context ID for whole team
        //Needs to be called by all ranks of the team
        virtual unsigned long long getNextContextId (void) = 0; /**< The id that determines whether to team handles with equal groups actually refer to the same team or not.*/

        /*
         * History information.
         */
        virtual MustParallelId getCreationPId (void) = 0; /**< For persistent teams information for call that created the team, otherwise not set.*/
        virtual MustLocationId getCreationLId (void) = 0; /**< For persistent teamms information for call that created the team, otherwise not set.*/

        /**
         * For teams that are predefined and not SHMEM_TEAM_INVALID,
         * returns an enumeration that identifies the name of the
         * predefined team.
         *
         * @return value of predefined team enumeration.
         */
        virtual MustShmemTeamPredefined getPredefinedInfo (void) = 0;

        /**
         * Returns true if this team is equal to the given one.
         * (Refer to the same communication group with equal context id.)
         * Returns false otherwise.
         *
         * @param other team to compare to.
         */
        virtual bool compareTeams (
                I_ShmemTeam* other) = 0;

        /**
         * Returns true if this team is equal to the given one.
         * (Refer to the same communication group with equal context id.)
         * Returns false otherwise. This is the 'operator version' of
         * compareTeams().
         *
         * @param other team to compare to.
         */
        virtual bool operator == (I_ShmemTeam &other) = 0;

        /**
         * Returns false if this team is equal to the given one.
         * (Refer to the same communication group with equal context id.)
         * Returns true otherwise. This is the 'operator version' of
         * the opposite of compareTeams().
         *
         * @param other team to compare to.
         */
        virtual bool operator != (I_ShmemTeam &other) = 0;

    }; /*class I_ShmemTeam*/

    /**
     * Interface for storage and accessing Information
     * on a team as defined in SHMEM. This is the persistent
     * version of the interface. The user needs to call I_ShmemTeamPersistent::erase
     * when he is finished with it.
     */
    class I_ShmemTeamPersistent : public I_ShmemTeam, public virtual I_Destructable
    {
    };/*class I_ShmemTeamPersistent*/

}/*namespace must*/

#endif /*I_SHMEM_TEAM_H*/

