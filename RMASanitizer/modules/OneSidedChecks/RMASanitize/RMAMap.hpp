/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file RMAMap.hpp
 *       @see must::RMAMap.
 *
 *  @date 16.06.2017
 *  @author Simon Schwitanski
 */

//=============================
// addOp
//=============================
template <typename RMA_OP_TYPE>
void RMAMap<RMA_OP_TYPE>::addOp(MustRMAId id, RMA_OP_TYPE* op)
{
    if (op) {
        myRMAMap.insert(std::make_pair(id, op));
        myContextRMAMap[op->getContextId()].insert(id);
    }
}

//=============================
// getOp
//=============================
template <typename RMA_OP_TYPE>
RMA_OP_TYPE* RMAMap<RMA_OP_TYPE>::getOp(MustRMAId callId)
{
    typename std::unordered_map<MustRMAId, RMA_OP_TYPE*>::iterator it = myRMAMap.find(callId);
    if (it == myRMAMap.end())
        return NULL;
    else
        return it->second;
}

//=============================
// getContextOps
//=============================
template <typename RMA_OP_TYPE>
std::list<RMA_OP_TYPE*> RMAMap<RMA_OP_TYPE>::getAllOps()
{
    std::list<RMA_OP_TYPE*> ret;
    for (const auto& elem : myContextRMAMap) {
        std::set<MustRMAId> ids = elem.second;
        for (auto it = ids.begin(); it != ids.end(); ++it) {
            RMA_OP_TYPE* op = getOp(*it);
            ret.push_back(op);
        }
    }

    return ret;
}

//=============================
// getContextOps
//=============================
template <typename RMA_OP_TYPE>
std::list<MustRMAId> RMAMap<RMA_OP_TYPE>::getContextOps(RMASegmentId segment)
{
    std::list<MustRMAId> ret;
    std::copy(
        myContextRMAMap[segment].begin(),
        myContextRMAMap[segment].end(),
        std::back_inserter(ret));

    return ret;
}

//=============================
// getContextTargetOps
//=============================
template <typename RMA_OP_TYPE>
std::list<MustRMAId> RMAMap<RMA_OP_TYPE>::getContextTargetOps(RMASegmentId segment, int target)
{
    std::list<MustRMAId> ret;

    for (std::set<MustRMAId>::iterator it = myContextRMAMap[segment].begin();
         it != myContextRMAMap[segment].end();
         ++it) {
        RMA_OP_TYPE* op = getOp(*it);
        if (op->getTarget() == target)
            ret.push_back(*it);
    }

    return ret;
}

//=============================
// getContextOriginOps
//=============================
template <typename RMA_OP_TYPE>
std::list<MustRMAId> RMAMap<RMA_OP_TYPE>::getContextOriginOps(RMASegmentId segment, int origin)
{
    std::list<MustRMAId> ret;

    for (std::set<MustRMAId>::iterator it = myContextRMAMap[segment].begin();
         it != myContextRMAMap[segment].end();
         ++it) {
        RMA_OP_TYPE* op = getOp(*it);
        if (op->getOrigin() == origin)
            ret.push_back(*it);
    }

    return ret;
}

//=============================
// removeOp
//=============================
template <typename RMA_OP_TYPE>
void RMAMap<RMA_OP_TYPE>::removeOp(MustRMAId callId)
{
    RMA_OP_TYPE* removeOp = getOp(callId);

    if (removeOp) {
        // remove from all containers
        myRMAMap.erase(callId);
        myContextRMAMap[removeOp->getContextId()].erase(callId);
        delete removeOp;
    }
}

//=============================
// removeOps
//=============================
template <typename RMA_OP_TYPE>
void RMAMap<RMA_OP_TYPE>::removeOps(const std::list<MustRMAId>& callIds)
{
    for (std::list<MustRMAId>::const_iterator it = callIds.begin(); it != callIds.end(); ++it) {
        removeOp(*it);
    }
}

//=============================
// size
//=============================
template <typename RMA_OP_TYPE>
size_t RMAMap<RMA_OP_TYPE>::size()
{
    return myRMAMap.size();
}
