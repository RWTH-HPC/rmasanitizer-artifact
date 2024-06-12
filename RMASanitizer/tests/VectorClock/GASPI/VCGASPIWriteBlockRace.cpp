/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file VCGASPIWriteBlockRace.cpp
 *       Minimized data race sample, vector clock test
 *
 *  @date 28.07.2023
 *  @author Simon Schwitanski
 */

// RUN: %must-run --must:layout \
// RUN: %builddir/tests/VectorClock/VCGASPIWriteBlockRaceLayout.xml \
// RUN: %must-bin-dir/VCGASPIWriteBlockRace 2>&1 \
// RUN: | %filecheck %s

// CHECK-DAG: shutdown(0){{.*}}clk=(6, 4)
// CHECK-DAG: shutdown(1){{.*}}clk=(6, 4)

#include <GASPI.h>
#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define PROC_NUM 2

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
    int* localbuf = (int*)src_segment_data;
    int* remote_data = (int*)dst_segment_data;

    gaspi_barrier(GASPI_GROUP_ALL, GASPI_BLOCK);

    if (rank == 0) {
        localbuf[0] = 1;
        // CONFLICT
        gaspi_write(loc_seg_id, 0, 1, remote_seg_id, 0, sizeof(int), queue_id, GASPI_BLOCK);
        // CONFLICT
        localbuf[0] = 42;
        gaspi_wait(queue_id, GASPI_BLOCK);
    }

    gaspi_barrier(GASPI_GROUP_ALL, GASPI_BLOCK);

    gaspi_proc_term(GASPI_BLOCK);

    return EXIT_SUCCESS;
}