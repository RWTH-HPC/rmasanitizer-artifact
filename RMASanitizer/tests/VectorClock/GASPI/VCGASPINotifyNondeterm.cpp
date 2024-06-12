/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file VCGASPINotifyNondeterm.cpp
 *       Vector clock test for nondeterministic message matching (2 rank send, 1 rank recv, same ID).
 *
 *  @date 28.07.2023
 *  @author Simon Schwitanski
 */

// RUN: %must-run --must:layout \
// RUN: %builddir/tests/VectorClock/VCGASPINotifyNondetermLayout.xml \
// RUN: %must-bin-dir/VCGASPINotifyNondeterm 2>&1 \
// RUN: | %filecheck %s

// CHECK-DAG: Placeholder
// XFAIL: *

#include <GASPI.h>
#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define PROC_NUM 3

int main(int argc, char* argv[])
{
    gaspi_proc_init(GASPI_BLOCK);

    gaspi_rank_t rank;
    gaspi_rank_t num;

    gaspi_proc_rank(&rank);
    gaspi_proc_num(&num);

    if (num != PROC_NUM) {
        printf("Wrong number of processes: %d. Expected: %d\n", num, PROC_NUM);
        gaspi_proc_term(GASPI_BLOCK);
    }

    const gaspi_segment_id_t loc_seg_id = 0;
    const gaspi_segment_id_t remote_seg_id = 1;
    const gaspi_queue_id_t queue_id = 0;
    gaspi_size_t const seg_size = 10 * sizeof(int);

    // local segment (for local buffers)
    gaspi_segment_alloc(loc_seg_id, seg_size, GASPI_ALLOC_DEFAULT);
    // remote segment (for one-sided accesses)
    gaspi_segment_create(
        remote_seg_id,
        seg_size,
        GASPI_GROUP_ALL,
        GASPI_BLOCK,
        GASPI_ALLOC_DEFAULT);

    gaspi_pointer_t src_segment_data;
    gaspi_pointer_t dst_segment_data;
    gaspi_segment_ptr(loc_seg_id, &src_segment_data);
    gaspi_segment_ptr(remote_seg_id, &dst_segment_data);

    gaspi_barrier(GASPI_GROUP_ALL, GASPI_BLOCK);

    if (rank == 0) {
        gaspi_notify(remote_seg_id, 2, 0, 1, queue_id, GASPI_BLOCK);
        gaspi_wait(queue_id, GASPI_BLOCK);
    }

    if (rank == 1) {
        gaspi_notify(remote_seg_id, 2, 0, 1, queue_id, GASPI_BLOCK);
        gaspi_wait(queue_id, GASPI_BLOCK);
    }

    if (rank == 2) {
        gaspi_notification_id_t firstId;
        // Following will wait for one of the notifications sent by rank 0 or 1. However, receiver has no way of distinguishing this.
        // Thus, VC value is undetermined after this call as synchronization origin is unknown.
        gaspi_notify_waitsome(remote_seg_id, 0, 1, &firstId, GASPI_BLOCK);
    }

    gaspi_proc_term(GASPI_BLOCK);

    return EXIT_SUCCESS;
}
