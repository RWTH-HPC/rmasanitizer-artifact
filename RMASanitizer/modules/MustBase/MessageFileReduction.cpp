/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file MessageFileReduction.cpp
 *       @see MUST::MessageFileReduction.
 */

#include <cassert>
#include <iostream>
#include <atomic>

#include "MessageFileReduction.h"

#include "GtiEnums.h"
#include "GtiMacros.h"
#include "MustDefines.h"

using gti::CompletionTree;
using gti::GTI_ANALYSIS_IRREDUCIBLE;
using gti::GTI_ANALYSIS_RETURN;
using gti::GTI_ANALYSIS_SUCCESS;
using gti::GTI_ANALYSIS_WAITING;
using gti::GTI_RETURN;
using gti::GTI_SUCCESS;
using gti::I_ChannelId;
using gti::ModuleBase;
using must::MessageFileReduction;
using std::list;
using std::vector;

mGET_INSTANCE_FUNCTION(MessageFileReduction);
mFREE_INSTANCE_FUNCTION(MessageFileReduction);
mPNMPI_REGISTRATIONPOINT_FUNCTION(MessageFileReduction);

/**
 * Constructor.
 */
MessageFileReduction::MessageFileReduction(const char* instanceName)
    : ModuleBase<MessageFileReduction, I_MessageFileReduction>(instanceName),
      reduceCompletion(NULL), reducePartners(), reduceTimedOut(false), filterId(0)
{
    // create sub modules
    std::vector<I_Module*> subModInstances;
    subModInstances = createSubModuleInstances();

    // handle sub modules
#define NUM_MODS_REQUIRED 1
    if (subModInstances.size() < NUM_MODS_REQUIRED) {
        std::cerr << "Module has not enough sub modules, check its analysis "
                     "specification! ("
                  << __FILE__ << "@" << __LINE__ << ")" << std::endl;
        assert(0);
    }
    if (subModInstances.size() > NUM_MODS_REQUIRED)
        for (vector<I_Module*>::size_type i = NUM_MODS_REQUIRED; i < subModInstances.size(); i++)
            destroySubModuleInstance(subModInstances[i]);

    // save sub modules
    myCreateMessageModule = (I_CreateMessage*)subModInstances[0];

    /* Get the function pointers for the open- and closeMessageFile wrapper
     * functions, generated by the GTI weaver.
     *
     * NOTE: If one or both of the wrapper functions can't be found, this module
     *       can't operate and an error will be raised.
     *
     * TODO: Maybe a kind of exception should be thrown in this case? */
    getWrapperFunction("openMessageFile", (GTI_Fct_t*)&(this->fpOpen));
    getWrapperFunction("closeMessageFile", (GTI_Fct_t*)&fpClose);

    assert(this->fpOpen);
    assert(this->fpClose);
}

/**
 *  @see I_MessageFileReduction::changeMessageFile
 */
GTI_ANALYSIS_RETURN
MessageFileReduction::changeMessageFile(size_t fileId, const char* filename, size_t len)
{
    /* The fileId needs to be greater 0, as the initial fileId is 0 and
     * therefore any new fileId needs to be greater than 0. */
    assert(fileId > 0);

    /* Trigger the 'changeFileId' method of the local process. As this method is
     * called in application processes only, this will change the fileId for new
     * message events of the application process only.
     *
     * NOTE: The fileId of other processes will be changed in the reduction
     *       function below.*/
    myCreateMessageModule->changeFileId(fileId);

    /* Start distributing the event as openMessageFile event in an internal
     * filter to open the new log-file and the closeMessageFile event in a
     * reduction to close the old log-file, when all processes have switched the
     * message file. */
    fpOpen(fileId, filename, len);
    //    fpClose(fileId - 1); /* The file is closed in the reduce function. */

    return gti::GTI_ANALYSIS_SUCCESS;
}

/**
 *  @see I_MessageFileReduction::changeMessageFile
 */
GTI_ANALYSIS_RETURN
MessageFileReduction::changeMessageFileWrapper(const char* filename)
{
    /* TODO: fileId needs to be atomic! */
    static std::atomic<size_t> fileId{0};
    return changeMessageFile(++fileId, filename, strlen(filename) + 1);
}

/**
 * @see I_MessageFileReduction::filter
 */
GTI_ANALYSIS_RETURN
MessageFileReduction::filter(
    size_t fileId,
    const char* filename,
    size_t len,
    I_ChannelId* thisChannel,
    list<I_ChannelId*>* outFinishedChannels)
{
    /* If the calling process is the first with the new fileId, the event will
     * be forwarded. All other processes with the same fileId will ignore this
     * call. */
    if (fileId > filterId) {
        filterId = fileId;
        fpOpen(fileId, filename, len);
    }

    return GTI_ANALYSIS_SUCCESS;
}

/**
 * @see I_MessageFileReduction::reduce
 */
GTI_ANALYSIS_RETURN
MessageFileReduction::reduce(
    size_t fileId,
    I_ChannelId* thisChannel,
    list<I_ChannelId*>* outFinishedChannels)
{
    /* If the reduction already timed out, there's nothing to do here. */
    if (reduceTimedOut)
        return GTI_ANALYSIS_IRREDUCIBLE;

    /* If the completion tree is not initialized yet, initialize it now. */
    if (!reduceCompletion)
        reduceCompletion = new CompletionTree(
            thisChannel->getNumUsedSubIds() - 1,
            thisChannel->getSubIdNumChannels(thisChannel->getNumUsedSubIds() - 1));

    /* Add the calling process (channel) to the completion tree and check, if
     * the reduction is completed now. */
    reduceCompletion->addCompletion(thisChannel);
    if (reduceCompletion->isCompleted()) {
        /* Reset completions tree. */
        reduceCompletion->flushCompletions();

        /* Add reduction partners to outFinishedChannels list. */
        std::list<I_ChannelId*>::iterator i;
        for (i = reducePartners.begin(); i != reducePartners.end(); i++)
            outFinishedChannels->push_back(*i);

        /* IMPORTANT: clear stored partners ... (do not delete their channel
         *            ids, this is done by the caller, as they are in the list
         *            of outFinishedChannels). */
        reducePartners.clear();

        /* As all reduction partners have triggered the reduction, the fileId
         * can be updated for this process now. For further processing, the
         * reduction will be passed to the upper level in the reduction tree. */
        myCreateMessageModule->changeFileId(fileId);
        fpClose(fileId);

        return GTI_ANALYSIS_SUCCESS;
    }

    /* Waiting for more reduction partners, add to list of blocked partners. */
    reducePartners.push_back(thisChannel);

    return GTI_ANALYSIS_WAITING;
}

/**
 * @see gti::I_Reduction.timeout
 */
void MessageFileReduction::timeout()
{
    if (reducePartners.size() > 0) {
        std::list<I_ChannelId*>::iterator i;
        for (i = reducePartners.begin(); i != reducePartners.end(); i++)
            delete (*i);
        reducePartners.clear();

        reduceTimedOut = true;
    }
}
