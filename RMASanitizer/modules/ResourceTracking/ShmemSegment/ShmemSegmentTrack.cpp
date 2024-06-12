/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file ShmemSegmentTrack.cpp
 *       @see MUST::ShmemSegmentTrack.
 *
 *  @date 16.02.2023
 *  @author Simon Schwitanski
 */

#include "GtiEnums.h"
#include "GtiMacros.h"
#include "MustEnums.h"
#include "PrefixedOstream.hpp"

#include "ShmemSegmentTrack.h"
#include "I_Group.h"

#include <iostream>
#include <sstream>
#include <utility>
#include <tuple>
#include <pnmpimod.h>
#include <assert.h>

using namespace must;

mGET_INSTANCE_FUNCTION(ShmemSegmentTrack)
mFREE_INSTANCE_FUNCTION(ShmemSegmentTrack)
mPNMPI_REGISTRATIONPOINT_FUNCTION(ShmemSegmentTrack)

#define CONTEXTID_MULTIPLIER 128

//=============================
// Constructor
//=============================
ShmemSegmentTrack::ShmemSegmentTrack(const char* instanceName)
    : TrackBase<
          ShmemSegment,
          I_ShmemSegment,
          MustShmemSegmentType,
          MustShmemSegmentPredefined,
          ShmemSegmentTrack,
          I_ShmemSegmentTrack>(instanceName),
      myDefaultSegments(), myDefaultSegmentHandles(), myUniqueIdCounter(1)
{
    // Get the GroupTrack module
    if (myFurtherMods.size() < 1) {
        must::cerr << "Error: the ShmemTrack module needs the GroupTrack module as a child, but it "
                      "was not specified."
                   << std::endl;
        assert(0);
    }

    myGroupMod = (I_GroupTrack*)myFurtherMods[0];
}

//=============================
// Destructor
//=============================
ShmemSegmentTrack::~ShmemSegmentTrack()
{
    // Notify HandleInfoBase of ongoing shutdown
    HandleInfoBase::disableFreeForwardingAcross();
    myGroupMod->notifyOfShutdown();

    // User handles and predefineds are freed by TrackBase, modules too.
    myGroupMod = NULL;

    // TODO: Clean up is currently not working as intended

    // 	//Free data
    // 	for (std::vector<I_Module*>::size_type i = 0; i < myWorldSegmentInfos.size(); i++)
    // 	{
    // 	    if (!myWorldSegmentInfos[i]->mpiErase())
    // 	    {
    // #ifdef MUST_DEBUG
    //             must::cout << "Warning: A SHMEM_TEAM_WORLD handle was queried for in a persistent
    //             way and was not freed." << std::endl;
    // #endif
    // 	    }
    // 	}

    // 	for (std::vector<I_Module*>::size_type i = 0; i < mySharedSegmentInfos.size(); i++)
    // 	{
    // 	    if (!mySharedSegmentInfos[i]->mpiErase())
    // 	    {
    // #ifdef MUST_DEBUG
    //             must::cout << "Warning: A SHMEM_TEAM_SHARED handle was queried for in a
    //             persistent way and was not freed." << std::endl;
    // #endif
    // 	    }
    // 	}

    myDefaultSegments.clear();
}

//=============================
// segmentDestroy
//=============================
GTI_ANALYSIS_RETURN
ShmemSegmentTrack::segmentDestroy(MustParallelId pId, MustLocationId lId, void* addr)
{
    // Apply the free
    removeUserHandle(pId, (MustShmemSegmentType)addr);

    return GTI_ANALYSIS_SUCCESS;
}

//=============================
// segmentSplit
//=============================
GTI_ANALYSIS_RETURN
ShmemSegmentTrack::segmentCreate(MustParallelId pId, MustLocationId lId, void* addr, size_t size)
{
    // Create the full information for the new segment
    ShmemSegment* newInfo = new ShmemSegment(this);

    newInfo->myCreationPId = pId;
    newInfo->myCreationLId = lId;

    // context
    newInfo->myBaseAddr = (MustAddressType)addr;
    newInfo->mySize = size;
    newInfo->myUniqueId = myUniqueIdCounter++;

    //==4) Register the new segment
    submitUserHandle(pId, (MustShmemSegmentType)addr, newInfo);

    return GTI_ANALYSIS_SUCCESS;
}

//=============================
// addPredefineds
//=============================
GTI_ANALYSIS_RETURN ShmemSegmentTrack::addPredefinedSegments(
    MustParallelId pId,
    int reachableBegin,
    int reachableEnd,
    int worldSize,
    uint64_t baseAddr,
    uint64_t* baseAddrs,
    int numBaseAddrs,
    gti::I_ChannelId* channId)
{
    // Adept reachable interval
    if (myReachableBegin < 0) {
        getReachableRanks(&myReachableBegin, &myReachableEnd, reachableBegin);
        myReachableAvailable = true;
    }

    // Gather the different values for the default segment
    for (int i = reachableBegin; i < reachableBegin + numBaseAddrs; i++) {
        myDefaultSegmentHandles.insert(std::make_pair(i, baseAddrs[i - reachableBegin]));
    }

#ifdef MUST_DEBUG
    // std::map<int, MustShmemSegmentType>::iterator iter;

    // must::cout << "ShmemSegmentTrack: addPredefineds, MPI_TEAM_WORLD values: ";
    // for (iter = mySegmentWorldHandles.begin(); iter != mySegmentWorldHandles.end(); iter++) {
    //     if (iter != mySegmentWorldHandles.begin())
    //         must::cout << ", ";
    //     must::cout << iter->first << "->" << iter->second;
    // }
    // must::cout << std::endl;

    // must::cout << "ShmemSegmentTrack: addPredefineds, MPI_TEAM_SHARED values: ";
    // for (iter = mySegmentSharedHandles.begin(); iter != mySegmentSharedHandles.end(); iter++) {
    //     if (iter != mySegmentSharedHandles.begin())
    //         must::cout << ", ";
    //     must::cout << iter->first << "->" << iter->second;
    // }
    // must::cout << std::endl;
#endif

    /*
     * We need one full info for each rank to make
     * their context ids independent!
     */
    if (myDefaultSegments.size() != worldSize)
        myDefaultSegments.resize(worldSize);

    for (int i = reachableBegin; i < reachableBegin + numBaseAddrs; i++) {
        myDefaultSegments[i] = new ShmemSegment(this);
        myDefaultSegments[i]->myBaseAddr = baseAddrs[i];
        myDefaultSegments[i]->mySize = 0;
        myDefaultSegments[i]->myIsPredefined = true;
        myDefaultSegments[i]->myPredefinedName = "SHMEM_DEFAULT_SEGMENT";
        myDefaultSegments[i]->myPredefined = MUST_SHMEM_SEGMENT_DEFAULT;
        myDefaultSegments[i]->myUniqueId = 0;
    }

    // add own segment
    myDefaultSegments[pId2Rank((pId))]->myBaseAddr = baseAddr;
    myDefaultSegments[pId2Rank((pId))]->mySize = 0;
    myDefaultSegments[pId2Rank((pId))]->myUniqueId = 0;

    // 	//Call addPredefineds of TrackBase
    // 	int predefEnumIds[2] = {(int)MUST_MPI_ShmemSegment_SELF, (int)MUST_MPI_ShmemSegment_WORLD};
    // 	MustShmemSegmentType predefValues[2] = {commSelf, commWorld};
    // 	TrackBase<Comm, I_ShmemSegment, MustShmemSegmentType, MustMpiCommPredefined,
    // ShmemSegmentTrack, I_ShmemSegmentTrack>::addPredefineds (
    //             pId,
    // 			commNull,
    // 			2,
    // 			predefEnumIds,
    // 			predefValues
    // 			);

    return GTI_ANALYSIS_SUCCESS;
}

//=============================
// getShmemSegment
//=============================
I_ShmemSegment* ShmemSegmentTrack::getSegment(MustParallelId pId, MustShmemSegmentType segment)
{
    return getSegment(pId2Rank(pId), segment);
}

//=============================
// getShmemSegment
//=============================
I_ShmemSegment* ShmemSegmentTrack::getSegment(int rank, MustShmemSegmentType segment)
{
    return getSegmentInfo(rank, segment);
}

//=============================
// getPersistentSegment
//=============================
I_ShmemSegmentPersistent*
ShmemSegmentTrack::getPersistentSegment(MustParallelId pId, MustShmemSegmentType segment)
{
    return getPersistentSegment(pId2Rank(pId), segment);
}

//=============================
// getPersistentSegment
//=============================
I_ShmemSegmentPersistent*
ShmemSegmentTrack::getPersistentSegment(int rank, MustShmemSegmentType segment)
{
    ShmemSegment* ret = getSegmentInfo(rank, segment);
    ;
    if (ret)
        ret->incRefCount();
    return ret;
}

I_ShmemSegment* ShmemSegmentTrack::getDefaultSegment(MustParallelId pId)
{
    return myDefaultSegments[pId2Rank(pId)];
}

MustShmemSegmentType ShmemSegmentTrack::findSegment(MustParallelId pId, void* addr)
{
    return findSegment(pId2Rank(pId), addr);
}

MustShmemSegmentType ShmemSegmentTrack::findSegment(int rank, void* addr)
{
    for (const auto& elem : getUserHandles()) {
        if (elem.first == rank) {
            HandleMap::const_iterator pos = findUserHandle(rank, elem.second);
            if (pos == slock_safe_ptr(myUserHandles)->end()) {
                cerr << "Internal error in ShmemSegmentTrack: Could not find user handle "
                     << elem.second << std::endl;
            } else {
                MustAddressType start = pos->second->getBaseAddress();
                MustAddressType end = start + pos->second->getSize() - 1;
                if ((MustAddressType)addr >= start && (MustAddressType)addr <= end) {
                    return elem.second;
                }
            }
        }
    }

    return myDefaultSegmentHandles[rank];
}

//=============================
// getShmemSegmentInfo
//=============================
ShmemSegment* ShmemSegmentTrack::getSegmentInfo(MustParallelId pId, MustShmemSegmentType segment)
{
    return getSegmentInfo(pId2Rank(pId), segment);
}

//=============================
// getShmemSegmentInfo
//=============================
ShmemSegment* ShmemSegmentTrack::getSegmentInfo(int rank, MustShmemSegmentType segment)
{
    // Is it an allocated segment?
    HandleMap::const_iterator pos = findUserHandle(rank, segment);

    if (pos == slock_safe_ptr(myUserHandles)->end()) {
        // if not, it must be the default segment
        return myDefaultSegments[rank];
    } else {
        return pos->second;
    }
}

//=============================
// notifyOfShutdown
//=============================
void ShmemSegmentTrack::notifyOfShutdown(void)
{
    TrackBase<
        ShmemSegment,
        I_ShmemSegment,
        MustShmemSegmentType,
        MustShmemSegmentPredefined,
        ShmemSegmentTrack,
        I_ShmemSegmentTrack>::notifyOfShutdown();
    if (myGroupMod)
        myGroupMod->notifyOfShutdown();
}

/*EOF*/
