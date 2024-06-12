/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file VCGASPIPassive.cpp
 *       Passive communication test (1 send/recv)
 *
 *  @date 13.09.2023
 *  @author Yussur Mustafa Oraji
 */

// RUN: %must-run --must:layout \
// RUN: %builddir/tests/VectorClock/VCGASPIPassiveLayout.xml \
// RUN: %must-bin-dir/VCGASPIPassive 2>&1 \
// RUN: | %filecheck %s

// CHECK-DAG: shutdown(0){{.*}}clk=(3, 2)
// CHECK-DAG: shutdown(1){{.*}}clk=(3, 3)

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
    const gaspi_queue_id_t queue_id = 0;
    gaspi_size_t const seg_size = 10 * sizeof(int);

    // local segment (for local buffers)
    gaspi_segment_alloc(loc_seg_id, seg_size, GASPI_ALLOC_DEFAULT);

    gaspi_pointer_t src_segment_data;
    gaspi_segment_ptr(loc_seg_id, &src_segment_data);

    gaspi_barrier(GASPI_GROUP_ALL, GASPI_BLOCK);

    if (rank == 0) {
        ((int*)src_segment_data)[0] = 42;
        gaspi_passive_send(loc_seg_id, 0, 1, sizeof(int), GASPI_BLOCK);
    }

    if (rank == 1) {
        gaspi_rank_t orig_rank;
        gaspi_passive_receive(loc_seg_id, 0, &orig_rank, sizeof(int), GASPI_BLOCK);
    }

    gaspi_proc_term(GASPI_BLOCK);

    return EXIT_SUCCESS;
}
