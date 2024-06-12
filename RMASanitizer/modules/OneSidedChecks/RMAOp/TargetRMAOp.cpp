/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file TargetRMAOp.cpp
 *
 *  @date 20.06.2017
 *  @author Simon Schwitanski
 */

#include "TargetRMAOp.h"

using namespace must;

//=============================
// Constructor
//=============================
TargetRMAOp::TargetRMAOp(void) : myIsAtomic(false), myTargetDatatype(0)
{
    // Nothing to do
}

//=============================
// Destructor
//=============================
TargetRMAOp::~TargetRMAOp(void) {}

//=============================
// isAtomic
//=============================
bool TargetRMAOp::isAtomic(void) { return myIsAtomic; }

//=============================
// isLocked
//=============================
bool TargetRMAOp::isLocked(void) { return myIsLocked; }

//=============================
// getTargetDatatype
//=============================
RMADataTypeId TargetRMAOp::getTargetDatatype(void) { return myTargetDatatype; }

//=============================
// getTargetDatatypeSize
//=============================
RMADataTypeId TargetRMAOp::getTargetDatatypeSize(void) { return myTargetDatatypeSize; }

//=============================
// getClock
//=============================
int TargetRMAOp::getClock(void) { return myClock; }

//=============================
// getStartVectorClock
//=============================
const Clock& TargetRMAOp::getStartVectorClock(void) const { return myStartVectorClock; };

//=============================
// getEndVectorClock
//=============================
const Clock& TargetRMAOp::getEndVectorClock(void) const { return myEndVectorClock; };

std::ostream& TargetRMAOp::print(std::ostream& os) const
{
    std::stringstream msg;
    msg << "TargetRMAOp: "
        << "rmaId: " << myRMAId << ", target: " << myTarget << ", origin: " << myOrigin
        << ", isStore: " << myIsStore << ", context:" << myContextId << ", epoch: " << myRMAEpoch
        << ", isAtomic: " << myIsAtomic << ", targetDatatype: " << myTargetDatatype
        << ", segmentId: " << mySegmentId << ", fiber: " << myFiber;

    if (myStartVectorClock.size() > 0)
        msg << ", startVC: " << myStartVectorClock.toStr();
    if (myEndVectorClock.size() > 0)
        msg << ", endVC: " << myEndVectorClock.toStr();
    msg << std::endl;

    os << msg.str();
    return os;
}