/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file ShmemSegment.cpp
 *       @see ShmemSegment.cpp
 *
 *  @date 14.02.2023
 *  @author Simon Schwitanski
 */

#include "ShmemSegment.h"

using namespace must;

//=============================
// Constructor
//=============================
ShmemSegment::ShmemSegment()
    : HandleInfoBase("ShmemSegment"), myIsPredefined(false), myBaseAddr(0), mySize(0),
      myCreationPId(0), myCreationLId(0)
{
    // Nothing to do
}

//=============================
// Constructor
//=============================
ShmemSegment::ShmemSegment(I_ShmemSegmentTrack* segmentTrack)
    : HandleInfoBase("ShmemSegment"), myIsPredefined(false), myBaseAddr(0), mySize(0),
      myCreationPId(0), myCreationLId(0), mySegmentTrack(segmentTrack)
{
    // Nothing to do
}

//=============================
// Destructor
//=============================
ShmemSegment::~ShmemSegment() {}

//=============================
// isPredefined
//=============================
bool ShmemSegment::isPredefined(void) const { return myIsPredefined; }

//=============================
// getCreationPId
//=============================
MustParallelId ShmemSegment::getCreationPId(void) { return myCreationPId; }

//=============================
// getCreationLId
//=============================
MustLocationId ShmemSegment::getCreationLId(void) { return myCreationLId; }

MustAddressType ShmemSegment::getBaseAddress(void) { return myBaseAddr; }

// get base address of SHMEM segment
size_t ShmemSegment::getSize(void) { return mySize; }

//=============================
// compareSegments
//=============================
bool ShmemSegment::compareSegments(I_ShmemSegment* other)
{
    return getBaseAddress() == getBaseAddress();
}

//=============================
// operator ==
//=============================
bool ShmemSegment::operator==(I_ShmemSegment& other)
{
    if (this == &other)
        return true;

    return compareSegments(&other);
}

//=============================
// operator !=
//=============================
bool ShmemSegment::operator!=(I_ShmemSegment& other) { return !(*this == other); }

//=============================
// getResourceName
//=============================
std::string ShmemSegment::getResourceName(void) { return "ShmemSegment"; }

//=============================
// printInfo
//=============================
bool ShmemSegment::printInfo(
    std::stringstream& out,
    std::list<std::pair<MustParallelId, MustLocationId>>* pReferences)
{
    out << "Shmem segment output printing not implemented yet" << std::endl;
    return true;
}

//=============================
// getUniqueId
//=============================
unsigned long long ShmemSegment::getUniqueId(void) { return myUniqueId; }

/*EOF*/
