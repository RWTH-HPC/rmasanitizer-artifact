/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file RmaMap.h
 *
 *  @date 16.06.2017
 *  @author Simon Schwitanski
 */

#ifndef RMA_MAP_H
#define RMA_MAP_H

#include <unordered_map>
#include <list>
#include <set>

#include "BaseIds.h"
#include "MustTypes.h"
#include "I_RMASanitize.h"

namespace must
{

/**
 * Implements a map that stores RMAOp objects.
 * In addition to access of RMAOp objects by their id, it is possible to get a
 * list of RMAOp objects corresponding to a window or a window-target pair.
 *
 * This template class is used for implementation of the concrete classes
 * OriginRMAMap (RMA_OP_TYPE: OriginRMAOp) and TargetRMAMap
 * (RMA_OP_TYPE: TargetRMAOp).
 */
template <typename RMA_OP_TYPE>
class RMAMap
{
  public:
    /**
     * Adds an RMAOp object with a given id to the map.
     *
     * @param id id of the object
     * @param op RMAOp object to add
     */
    virtual void addOp(MustRMAId id, RMA_OP_TYPE* op);

    /**
     * Returns the RMAOp object associated with the id.
     *
     * @param id id of the object
     * @return RMAOp object associated with the id
     */
    virtual RMA_OP_TYPE* getOp(MustRMAId callId);

    /**
     * Returns all stored RMA operations.
     *
     * @return List of RMAOp objects
     */
    virtual std::list<RMA_OP_TYPE*> getAllOps();

    /**
     * Returns all stored RMAOp objects that belong to a given context.
     *
     * @param context id the RMAOp objects are filtered by
     * @return list of RMAOp objects that belong to the given context
     */
    virtual std::list<MustRMAId> getContextOps(RMAContextId context);

    /**
     * Returns all stored RMAOp objects that belong to a given context
     * and are addressed to a given target rank.
     *
     * @param context id the RMAOp objects are filtered by
     * @param target target rank
     * @return list of RMAOp objects that belong to the given context and rank
     */
    virtual std::list<MustRMAId> getContextTargetOps(RMAContextId context, int target);

    /**
     * Returns all stored RMAOp objects that belong to a given context
     * and belong given origin rank.
     *
     * @param context id the RMAOp objects are filtered by
     * @param origin origin rank
     * @return list of RMAOp objects that belong to the given context and rank
     */
    virtual std::list<MustRMAId> getContextOriginOps(RMAContextId context, int origin);

    /**
     * Removes the RMAOp object associated with the given id.
     *
     * @param id id of the object to delete
     */
    virtual void removeOp(MustRMAId id);

    /**
     * Removes the RMAOp objects associated with the given ids.
     *
     * @param idList list containing ids of objects to delete
     */
    virtual void removeOps(const std::list<MustRMAId>& idList);

    /**
     * Returns the number of elements in the map.
     *
     * @return number of elements in the map
     */
    virtual size_t size();

  private:
    // actual map storing the RMAOp objects
    std::unordered_map<MustRMAId, RMA_OP_TYPE*> myRMAMap;
    // internal map for caching RMA ops associated with a certain context
    std::unordered_map<RMAContextId, std::set<MustRMAId>> myContextRMAMap;
};

#include "RMAMap.hpp"
} // namespace must

#endif
