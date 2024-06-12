/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file ShmemTeam.cpp
 *       @see ShmemTeam.cpp
 *
 *  @date 14.02.2023
 *  @author Simon Schwitanski
 */

#include "ShmemTeam.h"

using namespace must;

//=============================
// Constructor
//=============================
ShmemTeam::ShmemTeam()
: HandleInfoBase ("ShmemTeam"),
  myIsPredefined (false),
  myPredefined (MUST_SHMEM_TEAM_UNKNOWN),
  myContextId (0),
  myNextContextId (1),
  myGroup (NULL),
  myCreationPId (0),
  myCreationLId (0)
{
    //Nothing to do
}

//=============================
// Constructor
//=============================
ShmemTeam::ShmemTeam(I_ShmemTeamTrack* teamTrack)
: HandleInfoBase ("ShmemTeam"),
  myIsPredefined (false),
  myPredefined (MUST_SHMEM_TEAM_UNKNOWN),
  myContextId (0),
  myNextContextId (1),
  myGroup (NULL),
  myCreationPId (0),
  myCreationLId (0),
  myTeamTrack(teamTrack)
{
    //Nothing to do
}

//=============================
// Destructor
//=============================
ShmemTeam::~ShmemTeam ()
{
    if (myGroup)
        myGroup->erase();
    myGroup = NULL;
}

//=============================
// isPredefined
//=============================
bool ShmemTeam::isPredefined (void) const
{
    return myIsPredefined;
}

//=============================
// isInvalid
//=============================
bool ShmemTeam::isInvalid (void) const
{
    return myIsInvalid;
}


//=============================
// group
//=============================
must::I_GroupTable* ShmemTeam::getGroup (void) const
{
    return myGroup;
}


//=============================
// getContextId
//=============================
unsigned long long ShmemTeam::getContextId (void)
{
    return myContextId;
}

//=============================
// getNextContextId
//=============================
unsigned long long ShmemTeam::getNextContextId (void)
{
    return myNextContextId++;
}

//=============================
// getCreationPId
//=============================
MustParallelId ShmemTeam::getCreationPId (void)
{
    return myCreationPId;
}

//=============================
// getCreationLId
//=============================
MustLocationId ShmemTeam::getCreationLId (void)
{
    return myCreationLId;
}

//=============================
// getPredefinedInfo
//=============================
MustShmemTeamPredefined ShmemTeam::getPredefinedInfo (void)
{
    return myPredefined;
}

//=============================
// compareTeams
//=============================
bool ShmemTeam::compareTeams (I_ShmemTeam* other)
{
    return getGroup() == other->getGroup() && getContextId() == other->getContextId();
}

//=============================
// operator ==
//=============================
bool ShmemTeam::operator == (I_ShmemTeam &other)
{
	if (this == &other)
		return true;

	return compareTeams(&other);
}

//=============================
// operator !=
//=============================
bool ShmemTeam::operator != (I_ShmemTeam &other)
{
	return ! (*this == other);
}

//=============================
// getResourceName
//=============================
std::string ShmemTeam::getResourceName (void)
{
    return "ShmemTeam";
}

//=============================
// printInfo
//=============================
bool ShmemTeam::printInfo (
        std::stringstream &out,
        std::list<std::pair<MustParallelId,MustLocationId> > *pReferences)
{
    out << "Shmem team output printing not implemented yet" << std::endl;
    return true;
}


/*EOF*/
