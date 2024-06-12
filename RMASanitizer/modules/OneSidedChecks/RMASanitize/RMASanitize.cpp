/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file RMASanitize.cpp
 *       @see must::RMASanitize.
 *
 *  @date 15.12.2023
 *  @author Simon Schwitanski
 */

#include "GtiMacros.h"
#include "RMASanitize.h"
#include "MustEnums.h"
#include "MustDefines.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <system_error>
#include <unistd.h>
#include "I_RMAOp.h"
#include "PrefixedOstream.hpp"

#include <sstream>
#include <fstream>

using namespace must;

mGET_INSTANCE_FUNCTION(RMASanitize)
mFREE_INSTANCE_FUNCTION(RMASanitize)
mPNMPI_REGISTRATIONPOINT_FUNCTION(RMASanitize)

RMASanitize::RMASanitize(const char* instanceName)
    : ModuleBase<RMASanitize, I_RMASanitize>(instanceName), mySegmentId(1), myLocalAccessCounter(0),
      myRemoteAccessCounter(0)
{
    // create sub modules
    std::vector<I_Module*> subModInstances;
    subModInstances = createSubModuleInstances();

    // handle sub modules
#define NUM_SUBMODULES 4
    if (subModInstances.size() < NUM_SUBMODULES) {
        cerr << "Module has not enough sub modules, check its analysis specification! (" << __FILE__
             << "@" << __LINE__ << ")" << std::endl;
        assert(0);
    }
    if (subModInstances.size() > NUM_SUBMODULES) {
        for (std::vector<I_Module*>::size_type i = NUM_SUBMODULES; i < subModInstances.size(); i++)
            destroySubModuleInstance(subModInstances[i]);
    }

    // If libraceChecksList is found in module stack, then we use ISL for race checks, otherwise
    // shadow memory.
    PNMPI_modHandle_t dummy;
    if (PNMPI_Service_GetModuleByName("libraceChecksList", &dummy) == PNMPI_SUCCESS) {
        myRMAAnalysisMode = RMA_ANALYSIS_MODE_ISL;
    } else {
        myRMAAnalysisMode = RMA_ANALYSIS_MODE_SHADOW;
    }

    const char* envvar = std::getenv("MUST_RMASANITIZE_PASS_FULL_VC");
    if (envvar != nullptr && std::string(envvar) == "0") {
        passFullVC = false;
    } else {
        passFullVC = true;
    }

    myPIdMod = (I_ParallelIdAnalysis*)subModInstances[0];
    myLIdMod = (I_LocationAnalysis*)subModInstances[1];
    myVectorClock = (I_VectorClock*)subModInstances[2];
    myLogger = (I_CreateMessage*)subModInstances[3];

    // Initialize module data
    getWrapAcrossFunction("passTargetRMAOpAcross", (GTI_Fct_t*)&myPassTargetRMAOpAcrossFunc);
    getWrapAcrossFunction(
        "passRemoteBulkCompleteAcross",
        (GTI_Fct_t*)&myPassRemoteBulkCompleteAcross);
    getWrapAcrossFunction("passRemoteCompleteAcross", (GTI_Fct_t*)&myPassRemoteCompleteAcross);
    getWrapAcrossFunction("passNotificationAcross", (GTI_Fct_t*)&myPassNotificationAcrossFunc);
    getWrapAcrossFunction(
        "passNotificationAckAcross",
        (GTI_Fct_t*)&myPassNotificationAckAcrossFunc);
    getWrapperFunction("notifyOriginOpStart", (GTI_Fct_t*)&myNotifyOriginOpStartFunc);
    getWrapperFunction("notifyOriginOpComplete", (GTI_Fct_t*)&myNotifyOriginOpCompleteFunc);
    getWrapperFunction("notifyTargetOpStart", (GTI_Fct_t*)&myNotifyTargetOpStartFunc);
    getWrapperFunction("notifyTargetOpComplete", (GTI_Fct_t*)&myNotifyTargetOpCompleteFunc);
}

RMASanitize::~RMASanitize(void)
{
    if (myOrigRMAMap.size() > 0) {
        cout << "[RMASanitize] Error: Lost RMA origin calls that were not annotated: "
             << myOrigRMAMap.size() << std::endl;
        for (const auto& op : myOrigRMAMap.getAllOps()) {
            op->print(cout);
            cout << std::endl;
        }
    }
    if (myTgtRMAMap.size() > 0) {
        cout << "[RMASanitize] Error: Lost RMA target calls that were not annotated: "
             << myTgtRMAMap.size() << std::endl;
        for (const auto& op : myTgtRMAMap.getAllOps()) {
            op->print(cout);
            cout << std::endl;
        }
    }

    if ((getenv("MUST_RMASANITIZER_PRINT_STATISTICS") != NULL &&
         atoi(getenv("MUST_RMASANITIZER_PRINT_STATISTICS")) == 1)) {
        PNMPI_modHandle_t handle;
        PNMPI_Service_descriptor_t service;
        PNMPI_Service_Fct_t fct;

        PNMPI_modHandle_t stack;
        auto err = PNMPI_Service_GetStackByName("level_0", &stack);

        err = PNMPI_Service_GetModuleByName("split_processes", &handle);
        assert(err == PNMPI_SUCCESS);
        err = PNMPI_Service_GetServiceByName(handle, "SplitMod_getMySetComm", "p", &service);
        assert(err == PNMPI_SUCCESS);
        MPI_Comm myToolComm;
        ((int (*)(void*))service.fct)(&myToolComm);

        int rank, size;
        PMPI_Comm_rank(myToolComm, &rank);
        PMPI_Comm_size(myToolComm, &size);

        if (rank == 0) {
            std::vector<uint64_t> numLocalAccesses;
            std::vector<uint64_t> numRemoteAccesses;
            numLocalAccesses.resize(size);
            numRemoteAccesses.resize(size);
            XMPI_Gather_NewStack(
                stack,
                &myLocalAccessCounter,
                1,
                MPI_UINT64_T,
                numLocalAccesses.data(),
                1,
                MPI_UINT64_T,
                0,
                myToolComm);
            XMPI_Gather_NewStack(
                stack,
                &myRemoteAccessCounter,
                1,
                MPI_UINT64_T,
                numRemoteAccesses.data(),
                1,
                MPI_UINT64_T,
                0,
                myToolComm);

            size_t totalLocalAccesses = 0;
            size_t totalRemoteAccesses = 0;
            cerr << "[RMASanitize] Number of local buffer accesses" << std::endl;
            for (int i = 0; i < size; i++) {
                cerr << "[RMASanitize] Rank " << i << ": " << numLocalAccesses[i] << " ";
                totalLocalAccesses += numLocalAccesses[i];
            }
            cerr << std::endl;
            cerr << "[RMASanitize] Number of remote accesses" << std::endl;
            cerr << "[RMASanitize] ";
            for (int i = 0; i < size; i++) {
                cerr << "Rank " << i << ": " << numRemoteAccesses[i] << " ";
                totalRemoteAccesses += numRemoteAccesses[i];
            }
            cerr << std::endl;
            cerr << "[RMASanitize] Total number of local buffer accesses: " << totalLocalAccesses
                 << std::endl;
            cerr << "[RMASanitize] Total number of remote accesses: " << totalRemoteAccesses
                 << std::endl;
        } else {
            XMPI_Gather_NewStack(
                stack,
                &myLocalAccessCounter,
                1,
                MPI_UINT64_T,
                NULL,
                0,
                MPI_UINT64_T,
                0,
                myToolComm);
            XMPI_Gather_NewStack(
                stack,
                &myRemoteAccessCounter,
                1,
                MPI_UINT64_T,
                NULL,
                0,
                MPI_UINT64_T,
                0,
                myToolComm);
        }
    }

    if (myPIdMod)
        destroySubModuleInstance((I_Module*)myPIdMod);
    myPIdMod = NULL;

    if (myLIdMod)
        destroySubModuleInstance((I_Module*)myLIdMod);
    myLIdMod = NULL;

    if (myVectorClock)
        destroySubModuleInstance((I_Module*)myVectorClock);
    myVectorClock = NULL;
}

GTI_ANALYSIS_RETURN RMASanitize::init(MustParallelId pId)
{
    // get own rank
    uint64_t rank = myPIdMod->getInfoForId(pId).rank;

    // set RMA id counter accordingly such that we have unique ids across processes
    myRMAId = rank << 32;

    getPlaceMod(&myPlaceMod);

    return GTI_ANALYSIS_SUCCESS;
}

//====================================
// SEGMENT HANDLING
//====================================

RMASegmentId RMASanitize::allocSegment(MustAddressType baseAddress, void* ann)
{
    // TODO: This will not work together with RMA segments created in different groups, because
    // the IDs might be different (contextId depending on group required here).
    RMASegmentId segId = nextSegmentId();
#ifdef MUST_DEBUG
    cout << "[RMASanitize] Segment " << segId << " created with baseAddress=" << baseAddress
         << std::endl;
#endif

    RMASegment segment;
    segment.baseAddress = baseAddress;
    mySegmentMap[segId] = segment;
    mySegmentAnn[segId] = ann;

    return segId;
}

void RMASanitize::freeSegment(RMASegmentId segment) { mySegmentMap.erase(segment); }

//====================================
// COMMUNICATION PRIMITIVES
//====================================

void RMASanitize::addLocalAccess(
    MustParallelId pId,
    MustLocationId lId,
    unsigned long target,
    MustRMAId rmaId,
    RMASegmentId segment,
    RMAContextId context,
    RMAMemIntervals& localAddrs,
    RMAHandleId handle,
    bool isStore,
    void* ann)
{
#ifdef MUST_DEBUG
    cout << "[RMASanitize] addLocalAccess, RMA id " << rmaId << std::endl;
#endif
    myLocalAccessCounter++;

    OriginRMAOp* memOp = new OriginRMAOp();
    memOp->myPId = pId;
    memOp->myLId = lId;
    memOp->myOrigin = myPIdMod->getInfoForId(pId).rank;
    memOp->myTarget = target; // TODO: This information should be encoded in the remote operation.
    memOp->myIsStore = isStore;
    memOp->myMemIntervals = localAddrs;
    memOp->mySegmentId = segment;
    memOp->myRequestId = handle;
    memOp->myContextId = context;
    memOp->myFiber = ann;
    memOp->myRMAEpoch = getCurrentEpoch(context);
    memOp->myReturnAddr = myLIdMod->getInfoForId(pId, lId).codeptr;
    memOp->myFunctionAddr = myLIdMod->getInfoForId(pId, lId).callptr;

    // add new access to pending operations
    myOrigRMAMap.addOp(rmaId, memOp);

    if (myNotifyOriginOpStartFunc)
        (*myNotifyOriginOpStartFunc)(rmaId);
}

void RMASanitize::addRemoteAccess(
    MustParallelId pId,
    MustLocationId lId,
    unsigned long target,
    MustRMAId rmaId,
    RMASegmentId segment,
    RMAContextId context,
    RMAMemIntervals& remoteAddrs,
    MustDatatypeType remoteDataType,
    size_t remoteDataTypeSize,
    RMAHandleId handle,
    bool isAtomic,
    bool isStore,
    void* ann)
{
#ifdef MUST_DEBUG
    cout << "[RMASanitize] Send remote access to rank " << target << std::endl;
#endif

    int origin = myPIdMod->getInfoForId(pId).rank;

    int levelId;
    getLevelIdForApplicationRank(target, &levelId);

    // Send information about remote access to target
    passTargetRMAOpAcross(
        origin,
        target,
        rmaId,
        pId,
        lId,
        isStore,
        isAtomic,
        remoteAddrs,
        segment,
        context,
        getCurrentEpoch(context), // TODO: Who should manage this?
        remoteDataType,
        remoteDataTypeSize,
        levelId);
}

void RMASanitize::passTargetRMAOpAcross(
    int origin,
    int target,
    MustRMAId rmaId,
    MustParallelId pId,
    MustLocationId lId,
    bool isStore,
    bool isAtomic,
    RMAMemIntervals& memIntervals,
    RMASegmentId segment,
    RMAContextId context,
    int epoch,
    RMADataTypeId datatype,
    size_t datatypeSize,
    int toPlaceId)
{
    if (!myPassTargetRMAOpAcrossFunc)
        assert(0);

    // if nothing has to be transmitted, we do not have to send anything
    if (memIntervals.size() == 0)
        return;

    // serialize mem intervals: TODO think about better strategy here
    std::vector<MustAddressType> memAddresses;
    std::vector<size_t> memSizes;
    for (const auto& memInterval : memIntervals) {
        memAddresses.push_back(memInterval.first);
        memSizes.push_back(memInterval.second);
    }

    if (origin == target) {
        // local call, directly add target operation
        receiveRemoteAccess(
            origin,
            rmaId,
            pId,
            lId,
            &memAddresses[0],
            &memSizes[0],
            memIntervals.size(),
            isStore,
            isAtomic,
            target,
            segment,
            context,
            datatype,
            datatypeSize,
            epoch, // epoch
            myVectorClock->getClockValue(target),
            getCurrentVC(),
            getCurrentVCSize());
    } else {
        // remote call, transmit to target process
        MustRemoteIdType originDatatypeRemoteId = 0, targetDatatypeRemoteId = 0, winRemoteId = 0;

        // pass location of call across
        myLIdMod->passLocationToPlace(pId, lId, toPlaceId);

        // TODO: Do we have to consider that in our new VC analysis module?
        // if (origin != target)
        // only non-local calls count as pending RMA calls
        //    myMPIVectorClock->addPendingRMACall(target);

#ifdef MUST_DEBUG
        std::stringstream msg;
        msg << "[RMASanitize] Pass across"
            << "origin=" << origin << ",rmaId=" << rmaId << ",pId=" << pId << ",lId=" << lId
            << ",isStore=" << isStore << ",isAtomic=" << isAtomic << ",epoch=" << epoch
            << ",clockvalue=" << myVectorClock->getClockValue(target) << ",toPlaceId=" << toPlaceId
            << std::endl;
        cout << msg.str();
#endif

        // pass the actual RMA op across
        (*myPassTargetRMAOpAcrossFunc)(
            origin,
            rmaId,
            pId,
            lId,
            &memAddresses[0],
            &memSizes[0],
            memIntervals.size(),
            isStore,
            isAtomic,
            target,
            segment,
            context,
            datatype,
            datatypeSize,
            epoch, // epoch
            myVectorClock->getClockValue(target),
            getCurrentVC(),     // only for ISL
            getCurrentVCSize(), // only for ISL
            toPlaceId);
    }
}

GTI_ANALYSIS_RETURN RMASanitize::receiveRemoteAccess(
    int origin,
    MustRMAId rmaId,
    MustParallelId pId,
    MustLocationId lId,
    MustAddressType* memAddresses,
    size_t* memSizes,
    size_t memIntervalsSize,
    bool isStore,
    bool isAtomic,
    int target,
    RMASegmentId segment,
    RMAContextId context,
    RMADataTypeId datatype,
    size_t datatypeSize,
    int epoch,
    unsigned long long clockValue,
    unsigned long long* vectorClock,
    size_t vectorClockSize)
{
#ifdef MUST_DEBUG
    cout << "[RMASanitize] Receive remote access " << rmaId << "from " << origin << std::endl;
#endif
    myRemoteAccessCounter++;

    // calculate offset address (for offset calculation)
    MustAddressType offset = mySegmentMap[segment].baseAddress;

    // reconstruct memory intervals
    RMAMemIntervals memIntervals;

    for (int i = 0; i < memIntervalsSize; i++) {
        memIntervals.push_back(std::make_pair(memAddresses[i] + offset, memSizes[i]));
    }

    TargetRMAOp* memOp = new TargetRMAOp();
    memOp->myPId = pId;
    memOp->myLId = lId;
    memOp->myOrigin = origin;
    memOp->myTarget = target;
    memOp->myIsStore = isStore;
    memOp->myIsAtomic = isAtomic;
    memOp->myMemIntervals = memIntervals;
    memOp->mySegmentId = segment;
    memOp->myContextId = context;
    memOp->myRMAEpoch = epoch;
    memOp->myTargetDatatype = datatype;
    memOp->myTargetDatatypeSize = datatypeSize;
    memOp->myClock = clockValue;
    memOp->myStartVectorClock = Clock(vectorClock, vectorClockSize, origin);
    memOp->myReturnAddr = myLIdMod->getInfoForId(pId, lId).codeptr;
    memOp->myFunctionAddr = myLIdMod->getInfoForId(pId, lId).callptr;

    myTgtRMAMap.addOp(rmaId, memOp);

    if (myNotifyTargetOpStartFunc)
        (*myNotifyTargetOpStartFunc)(rmaId);

    // check whether myTgtStateMap[winId][origin] exists, create if it does not exist
    if (myTgtStateMap[context].find(origin) == myTgtStateMap[context].end()) {
        // initialize vector with states
        myTgtStateMap[context].insert(std::make_pair(
            origin,
            std::vector<std::list<MustRMAId>>(TARGET_OP_STATE_COUNT, std::list<MustRMAId>())));
    }

    // Special case required for shadow mode: Check for conflict to operations from the same
    // origin rank that are not already consistent.
    // If the origin locks a target window and performs two conflicting RMA operations
    // on it, then it will not be detected through the TSan annotations, because they are annotated
    // to the same fiber.
    if (myRMAAnalysisMode == RMA_ANALYSIS_MODE_SHADOW) {
        std::list<MustRMAId>& initItems = myTgtStateMap[context][origin][TARGET_OP_STATE_INIT];
        for (auto& rmaId : initItems) {
            I_TargetRMAOp* op = getTargetRMAOp(rmaId);
            const RMAMemIntervals& memIntervals2 = op->getMemIntervals();

            // If both accesses are reads, then we can skip
            if (!isStore && !op->isStore())
                continue;

            // Only for OpenSHMEM: If both accesses are remote writes and have different epochs,
            // we can skip the pairs
            // TODO: Add support for GASPI
            if (isStore && op->isStore() && epoch != op->getRMAEpoch()) {
                continue;
            }

            // If both accesses are accumulates *and* have the same data type, we can skip the
            // pairs, they must be save
            if (isAtomic && op->isAtomic() && datatype == op->getTargetDatatype()) {
                // TODO: Also have to check alignment
                continue;
            }

            // Iterate over all memory intervals from *this* RMA call
            for (auto it1 = memIntervals.begin(); it1 != memIntervals.end(); ++it1) {
                MustAddressType start1 = it1->first;
                MustAddressType end1 = start1 + it1->second - 1;
                // Compare with all memory intervals belonging the RMA call "rmaId"
                for (auto it2 = memIntervals2.begin(); it2 != memIntervals2.end(); ++it2) {
                    MustAddressType start2 = it2->first;
                    MustAddressType end2 = start2 + it2->second - 1;

                    // Report race if intervals are overlapping
                    if ((start1 >= start2 && start1 <= end2) ||
                        (start2 >= start1 && start2 <= end1)) {
                        std::list<std::pair<MustParallelId, MustLocationId>> refs;
                        refs.push_back(std::make_pair(pId, lId));
                        refs.push_back(std::make_pair(op->getPId(), op->getLId()));
                        std::stringstream stream;
                        stream << "Found RMA data race (overlapping accesses) on rank " << target
                               << " originating from rank " << origin;
                        myLogger->createMessage(
                            MUST_ERROR_REQUEST_NOT_KNOWN,
                            pId,
                            lId,
                            MustErrorMessage,
                            stream.str(),
                            refs);
                    }
                }
            }
        }
    }

    // add op to state map
    myTgtStateMap[context][origin][TARGET_OP_STATE_INIT].push_back(rmaId);

    return GTI_ANALYSIS_SUCCESS;
}

//====================================
// CONSISTENCY PRIMITIVES
//====================================

void RMASanitize::localBulkComplete(
    MustParallelId pId,
    MustLocationId lId,
    RMAContextId context,
    bool isLocalOnly,
    const std::vector<int>& groupRanks)
{
    std::list<MustRMAId> completedOps;

    for (auto rank : groupRanks) {
        completedOps.splice(completedOps.end(), myOrigRMAMap.getContextTargetOps(context, rank));

        if (isLocalOnly) {
            // send local completion to target ranks
            passRemoteBulkCompleteAcross(
                rank,
                pId,
                lId,
                myPIdMod->getInfoForId(pId).rank,
                context,
                true,
                -1);
        }
    }

    notifyOriginOpComplete(pId, lId, completedOps);

    myOrigRMAMap.removeOps(completedOps);
}

void RMASanitize::localComplete(MustParallelId pId, MustLocationId lId, MustRMAId rmaId)
{
    std::list<MustRMAId> completed = {rmaId};
    notifyOriginOpComplete(pId, lId, completed);

    OriginRMAOp* op = myOrigRMAMap.getOp(rmaId);
    passRemoteCompletionAcross(op->getTarget(), pId, lId, op->getOrigin(), true, rmaId);
    myOrigRMAMap.removeOp(rmaId);
}

void RMASanitize::bulkCollectiveRemoteComplete(
    MustParallelId pId,
    MustLocationId lId,
    RMAContextId context,
    const std::vector<int>& groupRanks)
{
#ifdef MUST_DEBUG
    cout << "[RMASanitize] Bulk collective remote complete on context " << context << std::endl;
#endif
    // Collective remote completion implies memory consistency and happens-before synchronization
    // Thus, we know that all items currently in the state map in state INIT can be directly
    // annotated without waiting for any further action.
    std::map<int, std::vector<std::list<MustRMAId>>>::iterator it;
    for (it = myTgtStateMap[context].begin(); it != myTgtStateMap[context].end(); ++it) {
        // get all items in state INIT
        std::list<MustRMAId>& initItems = it->second[TARGET_OP_STATE_INIT];
        // mark them all as completed
        notifyTargetOpComplete(pId, lId, initItems);
        // remove the RMA call information
        myTgtRMAMap.removeOps(initItems);
        // remove the RMA ids from the state map
        initItems.clear();
    }

    // start next access epoch
    epochMarker(context);
}

void RMASanitize::originRemoteBulkComplete(
    MustParallelId pId,
    MustLocationId lId,
    RMAContextId context,
    const std::vector<int>& groupRanks)
{
    int origin = myPIdMod->getInfoForId(pId).rank;

    for (std::vector<int>::const_iterator it = groupRanks.begin(); it != groupRanks.end(); ++it) {
#ifdef MUST_DEBUG
        cout << "[RMASanitize] passRemoteBulkCompleteAcross(" << *it << ", " << pId << ", " << lId
             << ", " << origin << ", " << context << ", -1)" << std::endl;
#endif
        passRemoteBulkCompleteAcross(
            *it,
            pId,
            lId,
            origin,
            context,
            false,
            -1); // passive target completion does not need epoch counter, we have to find the
                 // matching call with happened-before analysis
    }
}

void RMASanitize::targetRemoteComplete(
    MustParallelId pId,
    MustLocationId lId,
    RMAContextId context,
    const std::vector<int>& originRanks)
{
#ifdef MUST_DEBUG
    cout << "[RMASanitize] targetRemoteComplete on context " << context << " of ranks: ";
    for (const auto rank : originRanks) {
        cout << rank << ",";
    }
    cout << std::endl;
#endif
    int target = myPIdMod->getInfoForId(pId).rank;
    for (const auto origin : originRanks) {
        // check whether myTgtStateMap[winId][origin] exists
        if (myTgtStateMap[context].find(origin) != myTgtStateMap[context].end()) {
            if (origin != target) {
                // transition INIT -> CONSISTENT
                // get all items in state INIT and CONSISTENT
                std::list<MustRMAId>& initItems =
                    myTgtStateMap[context][origin][TARGET_OP_STATE_INIT];
                std::list<MustRMAId>& consistentItems =
                    myTgtStateMap[context][origin][TARGET_OP_STATE_CONSISTENT];

                // move all items from INIT to CONSISTENT
                consistentItems.splice(consistentItems.end(), initItems);
            } else {
                cerr << "Unexpected target remote completion from rank itself." << std::endl;
            }
        }
    }
}

void RMASanitize::targetNotify(
    MustParallelId pId,
    MustLocationId lId,
    RMAContextId context,
    uint64_t sigaddr,
    MustRMAId rmaId,
    int target)
{
    myWaitNotificationAcks.emplace(std::make_pair(sigaddr, target));

    if (myPassNotificationAcrossFunc) {
        myPassNotificationAcrossFunc(pId, lId, sigaddr, context, rmaId, target);
    }

    while (myWaitNotificationAcks.find(std::make_pair(sigaddr, target)) !=
           myWaitNotificationAcks.end()) {
        myPlaceMod->testIntralayer();
    }
}

void RMASanitize::targetWait(
    MustParallelId pId,
    MustLocationId lId,
    RMAContextId context,
    uint64_t sigaddr)
{
    for (const auto& origin_sigaddr : myPendingNotifications[sigaddr]) {
        int origin = origin_sigaddr.first;
        MustRMAId rmaId = origin_sigaddr.second;

        TargetRMAOp* op = myTgtRMAMap.getOp(rmaId);
        int notifyEpoch = op->getRMAEpoch();

        if (myTgtStateMap[context].find(origin) != myTgtStateMap[context].end()) {
            if (origin != myPIdMod->getInfoForId(pId).rank) {
                // transition INIT -> CONSISTENT
                // get all items in state INIT and CONSISTENT
                std::list<MustRMAId>& initItems =
                    myTgtStateMap[context][origin][TARGET_OP_STATE_INIT];
                std::list<MustRMAId>& consistentItems =
                    myTgtStateMap[context][origin][TARGET_OP_STATE_CONSISTENT];

                std::list<MustRMAId> completedItems;

                auto it_init = initItems.begin();
                while (it_init != initItems.end()) {
                    // find and finish the item itself and all items with epoch smaller than notify
                    // epoch
                    if (myTgtRMAMap.getOp(*it_init)->getRMAEpoch() < notifyEpoch) {
                        completedItems.emplace_back(*it_init);
                        it_init = initItems.erase(it_init);
                    } else {
                        ++it_init;
                    }
                }

                auto it_cons = consistentItems.begin();
                while (it_cons != consistentItems.end()) {
                    // find and finish the item itself and all items with epoch smaller than notify
                    // epoch
                    if (myTgtRMAMap.getOp(*it_cons)->getRMAEpoch() < notifyEpoch) {
                        completedItems.emplace_back(*it_cons);
                        it_cons = consistentItems.erase(it_cons);
                    } else {
                        ++it_cons;
                    }
                }

                // complete all those items
                notifyTargetOpComplete(pId, lId, completedItems);
            } else {
                cerr << "Unexpected target remote completion from rank itself." << std::endl;
            }
        }
    }
}

GTI_ANALYSIS_RETURN RMASanitize::receiveNotification(
    MustParallelId pId,
    MustLocationId lId,
    RMAContextId context,
    uint64_t sigaddr,
    MustRMAId rmaId)
{
    int origin = myPIdMod->getInfoForId(pId).rank;

    // Add pending notification
    myPendingNotifications[sigaddr].emplace_back(origin, rmaId);

    unsigned long rank;
    myPlaceMod->getNodeInLayerId(&rank);
    if (myPassNotificationAckAcrossFunc) {
        myPassNotificationAckAcrossFunc(sigaddr, context, (int)rank, origin);
    }
    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
RMASanitize::receiveNotificationAck(RMAContextId context, uint64_t sigaddr, int target)
{
    if (myWaitNotificationAcks.erase(std::make_pair(sigaddr, target)) < 1) {
        assert(0);
    }
    return gti::GTI_ANALYSIS_SUCCESS;
}

void RMASanitize::passRemoteBulkCompleteAcross(
    int rank,
    MustParallelId pId,
    MustLocationId lId,
    int origin,
    RMAContextId context,
    bool isLocalOnly,
    int epoch)
{

    if (!myPassRemoteBulkCompleteAcross)
        return;

    int toPlaceId;
    getLevelIdForApplicationRank(rank, &toPlaceId);

    if (rank == origin) {
        // pass location of call across
        myLIdMod->passLocationToPlace(pId, lId, toPlaceId);
    }

    // TODO: Do we have to consider that in our new vector clock analysis module?
    // myMPIVectorClock->addPendingRMACall(rank);

    (*myPassRemoteBulkCompleteAcross)(
        pId,
        lId,
        origin,
        rank,
        context,
        epoch,
        isLocalOnly,
        getCurrentVC(),
        getCurrentVCSize(),
        toPlaceId);
}

void RMASanitize::passRemoteCompletionAcross(
    int rank,
    MustParallelId pId,
    MustLocationId lId,
    int origin,
    bool isLocalOnly,
    MustRMAId rmaId)
{
    if (!myPassRemoteCompleteAcross)
        return;

    int toPlaceId;
    getLevelIdForApplicationRank(rank, &toPlaceId);

    if (rank != origin) {
        // pass location of call across
        myLIdMod->passLocationToPlace(pId, lId, toPlaceId);
    }

    (*myPassRemoteCompleteAcross)(
        pId,
        lId,
        origin,
        rmaId,
        isLocalOnly,
        getCurrentVC(),
        getCurrentVCSize(),
        toPlaceId);
}

GTI_ANALYSIS_RETURN RMASanitize::receiveRemoteBulkComplete(
    MustParallelId pId,
    MustLocationId lId,
    int origin,
    int target,
    RMAContextId context,
    int epoch,
    int isLocalOnly,
    unsigned long long* vectorClock,
    size_t vectorClockSize)
{
#ifdef MUST_DEBUG
    cout << "[RMASanitize] Receive remote complete on context=" << context << " from rank "
         << origin << std::endl;
#endif
    Clock remoteClock(vectorClock, vectorClockSize, origin);

    // check whether myTgtStateMap[winId][origin] exists
    if (myTgtStateMap[context].find(origin) != myTgtStateMap[context].end()) {
        // transition INIT -> CONSISTENT
        // get all items in state INIT and CONSISTENT
        std::list<MustRMAId>& initItems = myTgtStateMap[context][origin][TARGET_OP_STATE_INIT];
        std::list<MustRMAId>& consistentItems =
            myTgtStateMap[context][origin][TARGET_OP_STATE_CONSISTENT];

        if (origin != target) {
            if (!isLocalOnly) {
                // default case: target completion affects all items
                // move all items from INIT to CONSISTENT
                if (passFullVC) {
                    for (const auto& item : initItems) {
                        myTgtRMAMap.getOp(item)->myEndVectorClock = remoteClock;
                    }
                }
                consistentItems.splice(consistentItems.end(), initItems);
            } else {
                // completion of all read-only operations (Get)
                for (auto it = initItems.begin(); it != initItems.end();) {
                    if (!myTgtRMAMap.getOp(*it)->isStore()) {
                        if (passFullVC)
                            myTgtRMAMap.getOp(*it)->myEndVectorClock = remoteClock;
                        consistentItems.splice(consistentItems.end(), initItems, it++);
                    } else {
                        ++it;
                    }
                }
            }
        } else if (origin == target) {
            // special case: process accesses its own local window, we can directly
            // annotate those RMA operations and do not have to wait for any
            // process synchronization call
            notifyTargetOpComplete(0, 0, initItems);
            // remove the RMA call information
            myTgtRMAMap.removeOps(initItems);
            // remove the RMA ids from the state map
            initItems.clear();
        }
    }

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN
RMASanitize::receiveRemoteComplete(
    MustParallelId pId,
    MustLocationId lId,
    int origin,
    MustRMAId rmaId,
    int isLocalOnly,
    unsigned long long* vectorClock,
    size_t vectorClockSize)
{
#ifdef MUST_DEBUG
    cout << "[RMASanitize] Receive remote complete of rmaId=" << rmaId << " from rank " << origin
         << std::endl;
#endif

    Clock remoteClock(vectorClock, vectorClockSize, origin);

    // special case: if the completion call is only (locally) completing at the
    // origin and the corresponding RMA call is *reading*, then it is completed at the target
    if (isLocalOnly) {
        // try to find RMA op in state map
        for (auto& kv : myTgtStateMap) {
            if (kv.second.find(origin) == kv.second.end()) {
                // skip if no states stored
                continue;
            }

            auto initItems = kv.second[origin][TARGET_OP_STATE_INIT];
            auto consistentItems = kv.second[origin][TARGET_OP_STATE_CONSISTENT];
            auto it = std::find(initItems.begin(), initItems.end(), rmaId);
            // if found: make the item consistent
            if (it != initItems.end() && !myTgtRMAMap.getOp(*it)->isStore()) {
                if (passFullVC)
                    myTgtRMAMap.getOp(*it)->myEndVectorClock = remoteClock;
                consistentItems.splice(consistentItems.end(), initItems, it);
            }
        }
    } else {
        cout << "[RMASanitize] Internal error: Received unexpected remote completion event."
             << std::endl;
    }

    return GTI_ANALYSIS_SUCCESS;
}

GTI_ANALYSIS_RETURN RMASanitize::receiveSync(int remoteRank, int ownRank)
{
#ifdef MUST_DEBUG
    cout << "[RMASanitize] Sync remote rank " << remoteRank << " with " << ownRank << std::endl;
#endif
    std::map<MustWinType, std::map<int, std::vector<std::list<MustRMAId>>>>::iterator stateIt;
    std::map<int, std::vector<std::list<MustRMAId>>>::iterator rankIt;

    for (stateIt = myTgtStateMap.begin(); stateIt != myTgtStateMap.end(); ++stateIt) {
        // look whether there are RMA operations of remoteRank pending (passive)
        rankIt = stateIt->second.find(remoteRank);
        if (rankIt != stateIt->second.end()) {
            // pending RMA operations found
            std::list<MustRMAId>& consistentItems = rankIt->second[TARGET_OP_STATE_CONSISTENT];
            if (consistentItems.size() == 0)
                continue;

            // consistent items can be annotated
            notifyTargetOpComplete(0, 0, consistentItems);
            // remove the RMA call information
            myTgtRMAMap.removeOps(consistentItems);
            // remove the RMA ids from the state map
            consistentItems.clear();
        }
    }

    return GTI_ANALYSIS_SUCCESS;
}

//====================================
// NOTIFICATION CALLS
//====================================

void RMASanitize::notifyOriginOpComplete(
    MustParallelId pId,
    MustLocationId lId,
    const std::list<MustRMAId>& completedOps)
{
    MustRMAId* rmaIds = new MustRMAId[completedOps.size()];
    std::copy(completedOps.begin(), completedOps.end(), rmaIds);
    if (myNotifyOriginOpCompleteFunc)
        (*myNotifyOriginOpCompleteFunc)(pId, lId, rmaIds, completedOps.size());
    free(rmaIds);
}

void RMASanitize::notifyTargetOpComplete(
    MustParallelId pId,
    MustLocationId lId,
    const std::list<MustRMAId>& completedOps)
{
    MustRMAId* rmaIds = new MustRMAId[completedOps.size()];
    std::copy(completedOps.begin(), completedOps.end(), rmaIds);
    if (myNotifyTargetOpCompleteFunc)
        (*myNotifyTargetOpCompleteFunc)(pId, lId, rmaIds, completedOps.size());
    free(rmaIds);
}

//====================================
// GETTERS
//====================================

I_OriginRMAOp* RMASanitize::getOriginRMAOp(MustRMAId rmaId) { return myOrigRMAMap.getOp(rmaId); }
I_TargetRMAOp* RMASanitize::getTargetRMAOp(MustRMAId rmaId) { return myTgtRMAMap.getOp(rmaId); }

I_OriginRMAOpPersistent* RMASanitize::getPersistentOriginRMAOp(MustRMAId rmaId)
{
    OriginRMAOp* op = myOrigRMAMap.getOp(rmaId);
    if (op)
        op->incRefCount();

    return op;
}
I_TargetRMAOpPersistent* RMASanitize::getPersistentTargetRMAOp(MustRMAId rmaId)
{
    TargetRMAOp* op = myTgtRMAMap.getOp(rmaId);
    if (op)
        op->incRefCount();

    return op;
}

void* RMASanitize::getSegmentAnn(RMASegmentId segmentId) { return mySegmentAnn[segmentId]; }

ClockEntry* RMASanitize::getCurrentVC()
{
    if (passFullVC)
        return myVectorClock->getClock().data();
    else
        return nullptr;
}

size_t RMASanitize::getCurrentVCSize()
{
    if (passFullVC)
        return myVectorClock->getClock().size();
    else
        return 0;
}

void RMASanitize::epochMarker(RMAContextId context)
{
    if (myEpochCounter.find(context) == myEpochCounter.end()) {
        myEpochCounter[context] = 1;
    } else {
        myEpochCounter[context]++;
    }
}

RMAEpoch RMASanitize::getCurrentEpoch(RMAContextId context)
{
    if (myEpochCounter.find(context) == myEpochCounter.end()) {
        cout << "[RMASanitize] epoch counter not found for context " << context
             << "this should not happen." << std::endl;
        myEpochCounter[context] = 1;
        return 1;
    } else {
        return myEpochCounter[context];
    }
}