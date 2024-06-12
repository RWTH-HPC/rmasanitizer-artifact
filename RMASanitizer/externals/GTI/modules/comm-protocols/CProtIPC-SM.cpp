/* This file is part of GTI (Generic Tool Infrastructure)
 *
 * Copyright (C)
 *  2008-2019 ZIH, Technische Universitaet Dresden, Federal Republic of Germany
 *  2008-2019 Lawrence Livermore National Laboratories, United States of America
 *  2013-2019 RWTH Aachen University, Federal Republic of Germany
 *
 * See the LICENSE file in the package base directory for details
 */

/**
 * @file CProtIPC-SM.cpp
 *       A shared memory implementation of the communication protocol interface.
 *
 *  This implementation may be used to communicate between processes that share
 *  memory.
 *
 * @author Joachim Protze
 * @date 15.03.2012
 *
 */

#include <assert.h>
#include <mpi.h>
#include <stdio.h>
#include <pnmpimod.h>
#include <stdlib.h>
#include <algorithm>
#include <utility>

#include "CProtIPC-SM.h"
#include "GtiMacros.h"

#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <inttypes.h>

#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>

#define PERMS S_IRUSR | S_IWUSR

#define ERROR_CHECK(i)                                                                             \
    {                                                                                              \
        int temp = i;                                                                              \
        if (temp < 0)                                                                              \
            error_handler(temp, errno);                                                            \
    }

using namespace gti;

mGET_INSTANCE_FUNCTION(CommProtIpcSM)
mFREE_INSTANCE_FUNCTION(CommProtIpcSM)
mPNMPI_REGISTRATIONPOINT_FUNCTION(CommProtIpcSM)

/*
 * use shared memory blocks for large messages
 * memory block is allocated by sender, freed by receiver
 * memory block is identified by shmid, generated by sender, passed by message queue to receiver.
 */

/*
 * implementation of sending part
 */

pipe_t shm_send(const void* buf, size_t bytes)
{
    int shmid = shmget(0, bytes, IPC_CREAT | IPC_EXCL | PERMS);
    if (shmid == -1)
        // throw error
        return SHMGET_ERROR;
    // attach to memory block
    void* shmem = shmat(shmid, NULL, 0);
    if (shmem == (void*)-1) {
        // cleanup on error
        int tmperrno = errno;
        shmctl(shmid, IPC_RMID, NULL);
        errno = tmperrno;
        // throw error
        return SHMAT_ERROR;
    }
    // copy message to memory block
    memcpy(shmem, buf, bytes);
    // detach from memory block
    if (shmdt(shmem) == -1) {
        // cleanup on error
        int tmperrno = errno;
        shmctl(shmid, IPC_RMID, NULL);
        errno = tmperrno;
        // throw error
        return SHMDT_ERROR;
    }
    return shmid;
}

/*
 * implementation of sending part
 */

ssize_t shm_recv(pipe_t shmid, void* buf, size_t bytes)
{
    // attach / get shared memory pointer
    void* shmem = shmat(shmid, NULL, 0);
    if (shmem == (void*)-1) {
        // cleanup on error
        int tmperrno = errno;
        shmctl(shmid, IPC_RMID, NULL);
        errno = tmperrno;
        // throw error
        return SHMAT_ERROR;
    }
    // copy to target buffer
    if (buf != NULL)
        memcpy(buf, shmem, bytes);
    else
        bytes = 0;
    // detach shmem
    if (shmdt(shmem) == -1) {
        // cleanup on error
        int tmperrno = errno;
        shmctl(shmid, IPC_RMID, NULL);
        errno = tmperrno;
        // throw error
        return SHMDT_ERROR;
    }
    // release shmem
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
        // throw error
        return SHMCTL_ERROR;
    return bytes;
}

/* end of memory block communication */

/*
 * create a pipe, to be called once per pipe
 */

pipe_t pipe_create(key_t key)
{
    // Create message queue
    pipe_t ret = msgget(key, IPC_CREAT | PERMS);
    if (ret == -1)
        // throw error
        return MSGGET_ERROR;
    return ret;
}

/*
 * send message via pipe
 */

ssize_t pipe_send(
    pipe_t p,
    key_t& openLongSendKey,
    const void* buf,
    size_t bytes,
    key_t localkey,
    int msgflg = 0)
{
    struct gti::msgbuf buffer;
    struct gti::msgbuf* msgbuf_p = &buffer;
    struct gti::msgpointer* msgpointer_p = (struct gti::msgpointer*)&buffer;
    msgbuf_p->mtype = localkey;
    msgbuf_p->length = bytes;
    // large messages are sent by shared memory
    if (bytes > GTI_SHM_SHORT_MSG_SIZE) {
        // check for no unfinished long send
        if (openLongSendKey < 0) {
            // call the memory block send mechanism, save key to message queue payload
            openLongSendKey = shm_send(buf, bytes);
            if (openLongSendKey < 0)
                // throw error from shm_send
                return openLongSendKey;
        }
        msgpointer_p->shmid = openLongSendKey;
        // register long message type
        msgpointer_p->type = GTI_SHM_LONG_MSG;
        // submit message to message queue
        if (msgsnd(
                p,
                msgpointer_p,
                (sizeof(msgpointer) -
                 ((char*)&(msgpointer_p->length) - (char*)&(msgpointer_p->mtype))),
                msgflg) == -1)
            // throw error
            return MSGSND_ERROR;
        // Long send finished successfully
        openLongSendKey = -1;
    }
    // small messages are sent directly by message queue
    else {
        // register short message type
        msgbuf_p->type = GTI_SHM_SHORT_MSG;
        // copy buffer to message queue payload
        memcpy(msgbuf_p->mtext, buf, bytes);
        // submit message to message queue
        if (msgsnd(p, msgbuf_p, (msgbuf_p->mtext - (char*)&(msgbuf_p->length) + bytes), msgflg) ==
            -1)
            // throw error
            return MSGSND_ERROR;
    }
    return bytes;
}

/*
 * receive message via pipe
 */

ssize_t
pipe_recv(pipe_t p, void* buf, size_t bytes, key_t remotekey, key_t* out_remotekey, int msgflg = 0)
{
    struct gti::msgbuf buffer;
    struct gti::msgbuf* msgbuf_p = &buffer;
    struct gti::msgpointer* msgpointer_p = (struct gti::msgpointer*)&buffer;
    // fetch message from message queue
    int size = msgrcv(
        p,
        msgbuf_p,
        msgbuf_p->mtext - (char*)&(msgbuf_p->length) + GTI_SHM_SHORT_MSG_SIZE,
        remotekey,
        msgflg);
    if (size == -1)
        // throw error
        return MSGRCV_ERROR;
    // given buffersize ('bytes') has to be at least message length
    assert(bytes >= static_cast<size_t>(msgbuf_p->length) || buf == NULL);
    // get the remotekey from message
    if (out_remotekey != NULL)
        *out_remotekey = msgbuf_p->mtype;
    // test for method (short/long)
    if (msgbuf_p->type == GTI_SHM_SHORT_MSG) {
        // get short message payload
        if (buf != NULL)
            memcpy(buf, msgbuf_p->mtext, msgbuf_p->length);
    } else if (msgbuf_p->type == GTI_SHM_LONG_MSG) {
        // receive long message from message block
        return shm_recv(msgpointer_p->shmid, buf, msgbuf_p->length);
    } else {
        // throw error
        return INTERNAL_ERROR;
    }
    return msgbuf_p->length;
}

void print_error(const char* string, int err)
{
    std::cerr << "shm-ERROR: " << string << std::endl;
    assert(0);
}

void print_info(const char* string, int err)
{
    //     std::cerr << "shm-INFO: " << string << std::endl;
}

/*
 * produce detailed error messages for errors within the systemcalls
 * descriptions c&p'ed from the manpages
 */

void error_handler(long int retVal, int err)
{
    if (retVal >= 0)
        return;
    switch (retVal) {
    case MSGRCV_ERROR: {
        switch (err) {
        case E2BIG:
            print_error(
                "msgrcv error(E2BIG) The message text length is greater than msgsz and MSG_NOERROR "
                "isn't specified in msgflg.",
                err);
            break;

        case EACCES:
            print_error(
                "msgrcv error(EACCES) The calling process does not have read permission on the "
                "message queue, and does not have the CAP_IPC_OWNER capability.",
                err);
            break;

        case EAGAIN:
            print_info(
                "msgrcv error(EAGAIN) No message was available in the queue and IPC_NOWAIT was "
                "specified in msgflg.",
                err);
            break;

        case EFAULT:
            print_error(
                "msgrcv error(EFAULT) The address pointed to by msgp isn't accessible.",
                err);
            break;

        case EIDRM:
            print_error(
                "msgrcv error(EIDRM) While the process was sleeping to receive a message, the "
                "message queue was removed.",
                err);
            break;

        case EINTR:
            print_error(
                "msgrcv error(EINTR) While the process was sleeping to receive a message, the "
                "process caught a signal; see signal(7).",
                err);
            break;

        case EINVAL:
            print_error("msgrcv error(EINVAL) msgqid was invalid, or msgsz was less than 0.", err);
            break;

        case ENOMSG:
            print_info(
                "msgrcv error(ENOMSG) IPC_NOWAIT was specified in msgflg and no message of the "
                "requested type existed on the message queue.",
                err);
            break;

        case ENOSYS:
            print_error("msgrcv error(ENOSYS) Function not implemented", err);
            break;

        default:
            printf("msgrcv error(%i) - unusual errno, look it up in your errno.h\n", err);
            assert(0);
            break;
        }
        break;
    }
    case MSGSND_ERROR: {
        switch (err) {
        case EACCES:
            print_error(
                "msgsnd error(EACCES) The calling process does not have write permission on the "
                "message queue, and does not have the CAP_IPC_OWNER capability.",
                err);
            break;

        case EAGAIN:
            print_info(
                "msgsnd error(EAGAIN) The message can't be sent due to the msg_qbytes limit for "
                "the queue and IPC_NOWAIT was specified in msgflg.",
                err);
            break;

        case EFAULT:
            print_error(
                "msgsnd error(EFAULT) The address pointed to by msgp isn't accessible.",
                err);
            break;

        case EIDRM:
            print_error("msgsnd error(EIDRM) The message queue was removed.", err);
            break;

        case EINTR:
            print_error(
                "msgsnd error(EINTR) Sleeping on a full message queue condition, the process "
                "caught a signal.",
                err);
            break;

        case EINVAL:
            print_error(
                "msgsnd error(EINVAL) Invalid msqid value, or nonpositive mtype value, or invalid "
                "msgsz value (less than 0 or greater than the system value MSGMAX).",
                err);
            break;

        case ENOMEM:
            print_error(
                "msgsnd error(ENOMEM) The system does not have enough memory to make a copy of the "
                "message pointed to by msgp.",
                err);
            break;

        case ENOSYS:
            print_error("msgsnd error(ENOSYS) Function not implemented", err);
            break;

        default:
            printf("msgsnd error(%i) - unusual errno, look it up in your errno.h\n", err);
            assert(0);
            break;
        }
        break;
    }
    case MSGGET_ERROR: {
        switch (err) {
        case EACCES:
            print_error(
                "msgget error(EACCES) A message queue exists for key, but the calling process does "
                "not have permission to access the queue, and does not have the CAP_IPC_OWNER "
                "capability.",
                err);
            break;

        case EEXIST:
            print_error(
                "msgget error(EEXIST) A message queue exists for key and msgflg specified both "
                "IPC_CREAT and IPC_EXCL.",
                err);
            break;

        case ENOENT:
            print_error(
                "msgget error(ENOENT) No message queue exists for key and msgflg did not specify "
                "IPC_CREAT.",
                err);
            break;

        case ENOMEM:
            print_error(
                "msgget error(ENOMEM) A message queue has to be created but the system does not "
                "have enough memory for the new data structure.",
                err);
            break;

        case ENOSPC:
            print_error(
                "msgget error(ENOSPC) A message queue has to be created but the system limit for "
                "the maximum number of message queues (MSGMNI) would be exceeded.",
                err);
            break;

        case ENOSYS:
            print_error("msgget error(ENOSYS) Function not implemented", err);
            break;

        default:
            printf("msgget error(%i) - unusual errno, look it up in your errno.h\n", err);
            assert(0);
            break;
        }
        break;
    }
    case MSGCTL_ERROR: {
        switch (err) {
        case EACCES:
            print_error(
                "msgctl error(EACCES) The argument cmd is equal to IPC_STAT or MSG_STAT, but the "
                "calling process does not have read permission on the message queue msqid, and "
                "does not  have  the CAP_IPC_OWNER capability.",
                err);
            break;

        case EFAULT:
            print_error(
                "msgctl error(EFAULT) The argument cmd has the value IPC_SET or IPC_STAT, but the "
                "address pointed to by buf isn't accessible.",
                err);
            break;

        case EIDRM:
            print_error("msgctl error(EIDRM) The message queue was removed.", err);
            break;

        case EINVAL:
            print_error(
                "msgctl error(EINVAL) Invalid value for cmd or msqid.  Or: for a MSG_STAT "
                "operation, the index value specified in msqid referred to an array slot that is "
                "currently unused.",
                err);
            break;

        case EPERM:
            print_error(
                "msgctl error(EPERM) The  argument  cmd has the value IPC_SET or IPC_RMID, but the "
                "effective user ID of the calling process is not the creator (as found in "
                "msg_perm.cuid) or the owner (as found in msg_perm.uid) of the message queue, and "
                "the process is not privileged (Linux: it does not have the CAP_SYS_ADMIN "
                "capability).",
                err);
            break;

        case ENOSYS:
            print_error("msgctl error(ENOSYS) Function not implemented", err);
            break;

        default:
            printf("msgctl error(%i) - unusual errno, look it up in your errno.h\n", err);
            assert(0);
            break;
        }
        break;
    }
    case SHMGET_ERROR: {
        switch (err) {
        case EACCES:
            print_error(
                "shmget error(EACCES) The user does not have permission to access the shared "
                "memory segment, and does not have the CAP_IPC_OWNER capability.",
                err);
            break;

        case EEXIST:
            print_error(
                "shmget error(EEXIST) IPC_CREAT | IPC_EXCL was specified and the segment exists.",
                err);
            break;

        case EINVAL:
            print_error(
                "shmget error(EINVAL) A  new  segment  was  to  be  created and size < SHMMIN or "
                "size > SHMMAX, or no new segment was to be created, a segment with given key "
                "existed, but size is greater than the size of that segment.",
                err);
            break;

        case ENFILE:
            print_error(
                "shmget error(ENFILE) The system limit on the total number of open files has been "
                "reached.",
                err);
            break;

        case ENOENT:
            print_error(
                "shmget error(ENOENT) No segment exists for the given key, and IPC_CREAT was not "
                "specified.",
                err);
            break;

        case ENOMEM:
            print_error(
                "shmget error(ENOMEM) No memory could be allocated for segment overhead.",
                err);
            break;

        case ENOSPC:
            print_error(
                "shmget error(ENOSPC) All possible shared memory IDs have been taken (SHMMNI), or "
                "allocating a segment of the requested size would cause the  system  to  exceed  "
                "the  system-wide limit on shared memory (SHMALL).",
                err);
            break;

        case EPERM:
            print_error(
                "shmget error(EPERM) The SHM_HUGETLB flag was specified, but the caller was not "
                "privileged (did not have the CAP_IPC_LOCK capability).",
                err);
            break;

        case ENOSYS:
            print_error("shmget error(ENOSYS) Function not implemented", err);
            break;

        default:
            printf("shmget error(%i) - unusual errno, look it up in your errno.h\n", err);
            assert(0);
            break;
        }
        break;
    }
    case SHMAT_ERROR: {
        switch (err) {
        case EACCES:
            print_error(
                "shmat error(EACCES) The calling process does not have the required permissions "
                "for the requested attach type, and does not have the CAP_IPC_OWNER capability.",
                err);
            break;

        case EINVAL:
            print_error(
                "shmat error(EINVAL) Invalid  shmid  value,  unaligned  (i.e.,  not  page-aligned "
                "and SHM_RND was not specified) or invalid shmaddr value, or can't attach segment "
                "at shmaddr, or SHM_REMAP was specified and shmaddr was NULL.",
                err);
            break;

        case ENOMEM:
            print_error(
                "shmat error(ENOMEM) Could not allocate memory for the descriptor or for the page "
                "tables.",
                err);
            break;

        case ENOSYS:
            print_error("shmat error(ENOSYS) Function not implemented", err);
            break;

        default:
            printf("shmat error(%i) - unusual errno, look it up in your errno.h\n", err);
            assert(0);
            break;
        }
        break;
    }
    case SHMDT_ERROR: {
        switch (err) {
        case EINVAL:
            print_error(
                "shmdt error(EINVAL) There is no shared memory segment attached at shmaddr; or, "
                "shmaddr is not aligned on a page boundary.",
                err);
            break;

        case ENOSYS:
            print_error("shmdt error(ENOSYS) Function not implemented", err);
            break;

        default:
            printf("shmdt error(%i) - unusual errno, look it up in your errno.h\n", err);
            assert(0);
            break;
        }
        break;
    }
    case SHMCTL_ERROR: {
        switch (err) {
        case EACCES:
            print_error(
                "shmctl error(EACCES) IPC_STAT or SHM_STAT is requested and shm_perm.mode does not "
                "allow read access for shmid, and the calling process does not have the  "
                "CAP_IPC_OWNER  capability.",
                err);
            break;

        case EFAULT:
            print_error(
                "shmctl error(EFAULT) The argument cmd has value IPC_SET or IPC_STAT but the "
                "address pointed to by buf isn't accessible.",
                err);
            break;

        case EIDRM:
            print_error("shmctl error(EIDRM) shmid points to a removed identifier.", err);
            break;

        case EINVAL:
            print_error(
                "shmctl error(EINVAL) shmid  is not a valid identifier, or cmd is not a valid "
                "command.  Or: for a SHM_STAT operation, the index value specified in shmid "
                "referred to an array slot that is currently unused.",
                err);
            break;

        case ENOMEM:
            print_error(
                "shmctl error(ENOMEM) (In kernels since 2.6.9), SHM_LOCK was specified and the "
                "size of the to-be-locked segment would mean that the total bytes in locked shared "
                " memory  segments would exceed the limit for the real user ID of the calling "
                "process.  This limit is defined by the RLIMIT_MEMLOCK soft resource limit (see "
                "setrlimit(2)).",
                err);
            break;

        case EOVERFLOW:
            print_error(
                "shmctl error(EOVERFLOW) IPC_STAT is attempted, and the GID or UID value is too "
                "large to be stored in the structure pointed to by buf.",
                err);
            break;

        case EPERM:
            print_error(
                "shmctl error(EPERM) IPC_SET  or IPC_RMID is attempted, and the effective user ID "
                "of the calling process is not that of the creator (found in shm_perm.cuid), or "
                "the owner (found in shm_perm.uid), and the process was not privileged (Linux: did "
                "not have the CAP_SYS_ADMIN capability).",
                err);
            break;

        case ENOSYS:
            print_error("shmctl error(ENOSYS) Function not implemented", err);
            break;

        default:
            printf("shmctl error(%i) - unusual errno, look it up in your errno.h\n", err);
            assert(0);
            break;
        }
        break;
    }
    case INTERNAL_ERROR: {
        errno = err;
        perror("Errorcode -1");
        assert(0);
    }
    default: {
        printf("Errorcode: %ld\n", retVal);
        errno = err;
        perror("unknown errorcode in shared memory protocol");
        assert(0);
    }
    }
    errno = err;
}

void CommProtIpcSM::connect()
{
    int start_index;
    uint64_t remain;
    // key_base_offset is common offset derived from parent process id and gti::commId
    key_t key_base_offset = mySeed * ((commId + 1) * 10), key_bottom_offset;

    if (myIsIntra) {
        numPartners = tierSize;
        remotePipes.resize(numPartners);
        remoteKeys.resize(numPartners);
        localPipes.resize(numPartners);
        localKeys.resize(numPartners);
        openLongSendKeys.resize(numPartners, -1);
        //        start_index = selfID * numPartners + std::min(remain, selfID);
        for (int i = 0; i < numPartners; i++) {
            remoteKeys[i] = key_base_offset + selfID + i * numPartners;
            key2Channel[remoteKeys[i]] = i;
            remotePipes[i] = pipe_create(remoteKeys[i]);
            ERROR_CHECK(remotePipes[i]);
            localKeys[i] = key_base_offset + selfID * numPartners + i;
            key2Channel[localKeys[i]] = i;
            localPipes[i] = pipe_create(localKeys[i]);
            ERROR_CHECK(localPipes[i]);
        }
    } else /* myIsIntra */
    {
        // isTop is true for parent node in the communication tree
        if (isTop) {
            key_bottom_offset = key_base_offset + remoteTierSize;
            if (distrib == GTI_UNIFORM) {

                numPartners = remoteTierSize / tierSize;
                remain = remoteTierSize - tierSize * numPartners;
                start_index = selfID * numPartners + std::min(remain, selfID);
                if (selfID < remain)
                    numPartners++;
            } else {
                numPartners = std::min(blocksize, int(remoteTierSize - selfID * blocksize));
                start_index = selfID * blocksize;
            }

            remotePipes.resize(numPartners);
            remoteKeys.resize(numPartners);

            openLongSendKeys.resize(numPartners, -1);

            localPipes.resize(numPartners);
            localKeys.resize(numPartners);
            for (int i = 0; i < numPartners; i++) {
                remoteKeys[i] = key_bottom_offset + start_index + i;
                key2Channel[remoteKeys[i]] = i;
                remotePipes[i] = pipe_create(remoteKeys[i]);
                ERROR_CHECK(remotePipes[i]);
                localKeys[i] = key_base_offset + start_index + i;
                key2Channel[localKeys[i]] = i;
                localPipes[i] = pipe_create(localKeys[i]);
                ERROR_CHECK(localPipes[i]);
            }
        } else {
            numPartners = 1;

            remotePipes.resize(numPartners);
            remoteKeys.resize(numPartners);

            openLongSendKeys.resize(numPartners, -1);

            localPipes.resize(numPartners);
            localKeys.resize(numPartners);

            key_bottom_offset = key_base_offset + tierSize;

            remoteKeys[0] = key_base_offset + selfID;
            remotePipes[0] = pipe_create(remoteKeys[0]);
            ERROR_CHECK(remotePipes[0]);
            key2Channel[remoteKeys[0]] = 0;

            localKeys[0] = key_bottom_offset + selfID;
            localPipes[0] = pipe_create(localKeys[0]);
            ERROR_CHECK(localPipes[0]);
            key2Channel[localKeys[0]] = 0;
        }
    } /* myIsIntra */
}

//=============================
// CommProtIpcSM
//=============================
CommProtIpcSM::CommProtIpcSM(const char* instanceName)
    : ModuleBase<CommProtIpcSM, I_CommProtocol>(instanceName), isTop(true), myIsIntra(false),
      requestId(1)
{
    mySeed = 12345;
    if (getenv("THIS_RUN_SEED") != NULL) {
        mySeed = atoi(getenv("THIS_RUN_SEED"));
    }

    // highest shm_err_type should be -2
    assert(LAST_SHM_ERROR < 0);
    char string[32];

    std::vector<I_Module*> subModInstances;
    subModInstances = createSubModuleInstances();

    // A Comm Protocol likely needs no sub modules
    assert(subModInstances.empty());

    // === (1) Read data ===
    // General protocol data
    std::map<std::string, std::string> data = getData();
    std::map<std::string, std::string>::iterator i;

    i = data.find("comm_id");
    assert(i != data.end());
    commId = atoi(i->second.c_str());

    i = data.find("is_intra");
    if (i != data.end()) {
        if (i->second.c_str()[0] != '0' && i->second.c_str()[0] != '1') {
            std::cerr << "Error: Invalid specification for \"is_intra\" module data field in "
                      << __FILE__ << ":" << __LINE__ << std::endl;
            assert(0);
        }

        if (i->second.c_str()[0] == '1')
            myIsIntra = true;
    }
    i = data.find("side");
    assert(myIsIntra || i != data.end());
    assert(myIsIntra || i->second.length() == 1); // just one letter !
    if (!myIsIntra) {
        commSide = i->second.c_str()[0];
        assert((commSide == 't') || (commSide == 'b')); // either "t" or "b"
        if (commSide == 't')
            isTop = true;
        else
            isTop = false;
    }

    i = data.find("tier_size");
    assert(i != data.end());
    tierSize = atol(i->second.c_str());

    i = data.find("target_tier_size");
    assert(myIsIntra || i != data.end());
    if (!myIsIntra)
        remoteTierSize = atol(i->second.c_str());

    i = data.find("id");
    assert(i != data.end());
    selfID = atol(i->second.c_str());
    myPlaceId = selfID;

    i = data.find("gti_own_level");
    assert(i != data.end());
    gtiOwnLevel = atol(i->second.c_str());

    distrib = GTI_UNIFORM;
    uint64_t topLevel = gtiOwnLevel;
    if (!isTop)
        topLevel++;

    sprintf(string, "gti_level_%" PRIu64 "_%" PRIu64 "_distribution", topLevel - 1, topLevel);
    i = data.find(std::string(string));
    if (i != data.end() and i->second == std::string("by-block")) {
        distrib = GTI_BY_BLOCK;
        sprintf(string, "gti_level_%" PRIu64 "_%" PRIu64 "_blocksize", topLevel - 1, topLevel);
        i = data.find(std::string(string));
        assert(i != data.end());
        blocksize = atoi(i->second.c_str());
    }

    srand(time(NULL) + selfID);
    connect();
    initialized = true;
    finalized = false;
}

//=============================
// ~CommProtIpcSM
//=============================
CommProtIpcSM::~CommProtIpcSM(void)
{
    // TODO
}

//=============================
// isConnected
//=============================
bool CommProtIpcSM::isConnected(void) { return isInitialized() && !isFinalized(); }

//=============================
// isInitialized
//=============================
bool CommProtIpcSM::isInitialized(void) { return initialized; }

//=============================
// isFinalized
//=============================
bool CommProtIpcSM::isFinalized(void) { return finalized; }

//=============================
// shutdown
//=============================
GTI_RETURN CommProtIpcSM::shutdown(void)
{
    for (int i = 0; i < numPartners; i++)
        msgctl(localPipes[i], IPC_RMID, NULL);
    finalized = true;
    return GTI_SUCCESS;
}

//=============================
// getNumChannels
//=============================
GTI_RETURN CommProtIpcSM::getNumChannels(uint64_t* out_numChannels)
{
    *out_numChannels = numPartners;
    return GTI_SUCCESS;
}

//=============================
// getPlaceId
//=============================
GTI_RETURN CommProtIpcSM::getPlaceId(uint64_t* outPlaceId)
{
    if (!initialized)
        return GTI_ERROR_NOT_INITIALIZED;

    if (outPlaceId)
        *outPlaceId = selfID;
    return GTI_SUCCESS;
}

//=============================
// removeOutstandingRequests
//=============================
GTI_RETURN CommProtIpcSM::removeOutstandingRequests(void)
{
    //     //TODO: verify the algorithm
    //     do
    //     {
    //         pipe_recv(localPipe, NULL, 0, RECV_ANY_CHANNEL, NULL, IPC_NOWAIT);
    //     }
    //     while (errno!=EAGAIN);
    return GTI_SUCCESS;
}

// int pipe_send(pipe_t p, const char* buf, int bytes, long source);

//=============================
// ssend
//=============================
GTI_RETURN CommProtIpcSM::ssend(void* buf, uint64_t num_bytes, uint64_t channel)
{
    ERROR_CHECK(pipe_send(
        remotePipes[channel],
        openLongSendKeys[channel],
        buf,
        num_bytes,
        localKeys[channel]));
    return GTI_SUCCESS;
}

//=============================
// isend
//=============================
GTI_RETURN
CommProtIpcSM::isend(void* buf, uint64_t num_bytes, unsigned int* out_request, uint64_t channel)
{
    shmRequest* req = new shmRequest(requestId++, buf, num_bytes, channel, true);
    req->length = pipe_send(
        remotePipes[channel],
        openLongSendKeys[channel],
        buf,
        num_bytes,
        localKeys[channel],
        IPC_NOWAIT);
    if (req->length >= 0) { // recv finished
        req->finished = true;
    } else {
        if (errno != EAGAIN) { // when msg not already sent errno should be
            //                    EAGAIN  for full queue
            // everything else is error and fatal
            ERROR_CHECK(req->length);
            assert(0);
        }
        requestId--;
        delete req;
        return GTI_ERROR_OUTSTANDING_LIMIT;
    }
    if (out_request != NULL)
        *out_request = req->request;
    requestMap.insert(std::make_pair(req->request, req));
    return GTI_SUCCESS;
}

// ssize_t pipe_recv(pipe_t p, void* buf, size_t bytes, key_t remotekey, key_t* out_remotekey, int
// msgflg=0);

//=============================
// recv_wrapper mapps channelids to keys and backwards
//=============================
ssize_t CommProtIpcSM::recv_wrapper(
    void* out_buf,
    size_t num_bytes,
    uint64_t channel,
    uint64_t* out_channel,
    int msgflg)
{
    key_t remotekey = 0;
    pipe_t localPipe;
    ssize_t length;
    static int next_channel = 0;
    if (channel == RECV_ANY_CHANNEL) {
        if (msgflg == IPC_NOWAIT) {
            for (int i = 0; i < numPartners; i++) {
                localPipe = localPipes[(next_channel + i) % numPartners];
                length = pipe_recv(localPipe, out_buf, num_bytes, remotekey, &remotekey, msgflg);
                ERROR_CHECK(length);
                if (length >= 0) {
                    next_channel = (next_channel + i) % numPartners;
                    break;
                }
            }
            next_channel++;
            if (next_channel >= numPartners)
                next_channel = 0;
        } else {
            bool gotMessage = false;
            while (!gotMessage) {
                for (int i = 0; i < numPartners; i++) {
                    localPipe = localPipes[i];
                    length = pipe_recv(
                        localPipes[i],
                        out_buf,
                        num_bytes,
                        remotekey,
                        &remotekey,
                        IPC_NOWAIT);
                    ERROR_CHECK(length);
                    if (length >= 0) {
                        gotMessage = true;
                        break;
                    }
                }
            }
        }
    } else {
        localPipe = localPipes[channel];
        length = pipe_recv(localPipe, out_buf, num_bytes, remotekey, &remotekey, msgflg);
        ERROR_CHECK(length);
    }
    if (length < 0)
        return -1;
    std::map<key_t, int>::iterator iter = key2Channel.find(remotekey);
    assert(iter != key2Channel.end());
    if (out_channel != NULL)
        *out_channel = iter->second;
    return length;
}

//=============================
// recv
//=============================
GTI_RETURN CommProtIpcSM::recv(
    void* out_buf,
    uint64_t num_bytes,
    uint64_t* out_length,
    uint64_t channel,
    uint64_t* out_channel)
{
    if (out_length != NULL)
        *out_length = recv_wrapper(out_buf, num_bytes, channel, out_channel);
    else
        recv_wrapper(out_buf, num_bytes, channel, out_channel);
    return GTI_SUCCESS;
}

//     struct {
//         void* out_buf;
//         uint64_t num_bytes;
//         unsigned int request;
//         uint64_t length;
//         uint64_t channel;
//         int finished;
//         shmRequest(unsigned int id, void* out_buf, uint64_t num_bytes, uint64_t channel) :
//         request(id), finished(false), out_buf(out_buf), num_bytes(num_bytes), channel(channel);
//     }shmRequest;

//=============================
// irecv
//=============================
GTI_RETURN
CommProtIpcSM::irecv(void* out_buf, uint64_t num_bytes, unsigned int* out_request, uint64_t channel)
{
    shmRequest* req = new shmRequest(requestId++, out_buf, num_bytes, channel);
    req->length =
        recv_wrapper(req->out_buf, req->num_bytes, req->channel, &(req->channel), IPC_NOWAIT);
    if (req->length >= 0) { // recv finished
        req->finished = true;
    } else { // when msg not already recved errno should be
             //                    EAGAIN  for wildcard recv
             //                    ENOMSG  for given channel
             // everything else is fatal
        assert(errno == ENOMSG || errno == EAGAIN);
    }
    if (out_request != NULL)
        *out_request = req->request;
    requestMap.insert(std::make_pair(req->request, req));
    return GTI_SUCCESS;
}

//=============================
// test_msg
//=============================
GTI_RETURN CommProtIpcSM::test_msg(
    unsigned int request,
    int* out_completed,
    uint64_t* out_receive_length,
    uint64_t* out_channel)
{
    if (out_completed != NULL)
        *out_completed = false;
    std::map<int, shmRequest*>::iterator iter = requestMap.find(request);
    assert(iter != requestMap.end());
    shmRequest* req = iter->second;
    if (!req->finished) {
        assert(!req->send);
        req->length =
            recv_wrapper(req->out_buf, req->num_bytes, req->channel, &(req->channel), IPC_NOWAIT);
        if (req->length >= 0) { // recv finished
            req->finished = true;
            assert(static_cast<std::size_t>(req->length) <= req->num_bytes);
        } else { // errno should be ENOMSG, when msg not already recved
            // everything else is fatal
            assert(errno == ENOMSG || errno == EAGAIN);
        }
    }
    if (req->finished) {
        if (out_completed != NULL)
            *out_completed = true;
        if (out_receive_length != NULL)
            *out_receive_length = req->length;
        if (out_channel != NULL)
            *out_channel = req->channel;
        delete req;
        requestMap.erase(iter);
    }
    return GTI_SUCCESS;
}

//=============================
// wait_msg
//=============================
GTI_RETURN
CommProtIpcSM::wait_msg(unsigned int request, uint64_t* out_receive_length, uint64_t* out_channel)
{
    std::map<int, shmRequest*>::iterator iter = requestMap.find(request);
    assert(iter != requestMap.end());
    shmRequest* req = iter->second;
    if (!req->finished) {
        assert(!req->send);
        req->length = recv_wrapper(req->out_buf, req->num_bytes, req->channel, &(req->channel));
    }
    if (out_receive_length != NULL)
        *out_receive_length = req->length;
    if (out_channel != NULL)
        *out_channel = req->channel;
    delete req;
    requestMap.erase(iter);
    return GTI_SUCCESS;
}

/*EOF*/