/* Part of RMARaceBench, under BSD-3-Clause License
 * See https://github.com/RWTH-HPC/RMARaceBench/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

// RUN: %must-cc %s -o %must-bin-dir/%basename_t.exe %must-compiler-rma-flags %gaspi-flags
// RUN: %must-run --must:rma --must:rma-mode %must-rma-mode -np 3 %must-bin-dir/%basename_t.exe 2>&1 | %filecheck -DFILENAME=%basename_t %s
// CHECK-DAG: data race
// CHECK-DAG: [[FILENAME]]:71
// CHECK-DAG: [[FILENAME]]:77

// RACE LABELS BEGIN
/*
{
    "RACE_KIND": "remote",
    "ACCESS_SET": ["rma atomic write","rma atomic write"],
    "RACE_PAIR": ["gaspi_atomic_fetch_add@71","gaspi_atomic_fetch_add@77"],
    "CONSISTENCY_CALLS": [""],
    "SYNC_CALLS": ["gaspi_barrier"],
    "NPROCS": 3,
    "DESCRIPTION": "Two atomic operations gaspi_atomic_fetch_add with unaligned offets. The gaspi_atomic_fetch_add call from rank 0 adds an offset of 1 byte which is incorrect. "
}
*/
// RACE LABELS END

#include <GASPI.h>
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define PROC_NUM 3

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);
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
    gaspi_segment_create(remote_seg_id, seg_size, GASPI_GROUP_ALL, GASPI_BLOCK, GASPI_ALLOC_DEFAULT);

    gaspi_pointer_t src_segment_data;
    gaspi_pointer_t dst_segment_data;
    gaspi_segment_ptr(loc_seg_id, &src_segment_data);
    gaspi_segment_ptr(remote_seg_id, &dst_segment_data);
    int* localbuf = (int*)src_segment_data;
    int* remote_data = (int*)dst_segment_data;

    gaspi_barrier(GASPI_GROUP_ALL, GASPI_BLOCK);
    gaspi_atomic_value_t old;

    if (rank == 0) {
        // CONFLICT
        gaspi_atomic_fetch_add(remote_seg_id, 1, 1, 1, &old, GASPI_BLOCK);
        printf("rank 0 old value = %lu\n", old);
    }

    if (rank == 2) {
        // CONFLICT
        gaspi_atomic_fetch_add(remote_seg_id, 0, 1, 1, &old, GASPI_BLOCK);
        printf("rank 2 old value = %lu\n", old);
    }

    gaspi_barrier(GASPI_GROUP_ALL, GASPI_BLOCK);

    gaspi_wait(queue_id, GASPI_BLOCK);
    gaspi_barrier(GASPI_GROUP_ALL, GASPI_BLOCK);

    // ensure synchronization between all ranks by using notifications
    // to avoid race with printf statement (gaspi_wait + gaspi_barrier
    // is not enough in some cases), both ranks send a notification to
    // the other rank and wait for the notification from the other rank.
    for (int i = 0; i < num; i++) {
        gaspi_notify(remote_seg_id, i, rank, rank, queue_id, GASPI_BLOCK);
    }
    gaspi_notification_id_t firstId;
    gaspi_notify_waitsome(remote_seg_id, 0, num, &firstId, GASPI_BLOCK);

    printf(
        "Process %d: Execution finished, variable contents: localbuf[0] = %d, remote_data[0] = %d\n",
        rank,
        localbuf[0],
        remote_data[0]);
    gaspi_proc_term(GASPI_BLOCK);

    MPI_Finalize();

    return EXIT_SUCCESS;
}