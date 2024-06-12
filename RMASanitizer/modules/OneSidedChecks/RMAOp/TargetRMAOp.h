/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file TargetRMAOp.h
 *
 *  @date 20.06.2017
 *  @author Simon Schwitanski
 */

#ifndef TARGETRMAOP_H
#define TARGETRMAOP_H

#include "I_Destructable.h"
#include "HandleInfoBase.h"
#include "I_TargetRMAOp.h"
#include "RMAOp.h"

namespace must
{
class TargetRMAOp : public RMAOp, public I_TargetRMAOpPersistent
{
  public:
    TargetRMAOp(void);

    bool isAtomic(void);
    bool isLocked(void);
    RMADataTypeId getTargetDatatype(void);
    size_t getTargetDatatypeSize(void);
    int getClock(void);
    const Clock& getStartVectorClock(void) const;
    const Clock& getEndVectorClock(void) const;

    virtual ~TargetRMAOp(void);

    std::ostream& print(std::ostream& os) const;

  public:
    bool myIsAtomic;
    bool myIsLocked;
    int myClock; // local clock value that represents the sync state when the access occurred
    Clock myStartVectorClock;
    Clock myEndVectorClock;
    RMADataTypeId myTargetDatatype;
    size_t myTargetDatatypeSize;
};
} // namespace must

#endif
