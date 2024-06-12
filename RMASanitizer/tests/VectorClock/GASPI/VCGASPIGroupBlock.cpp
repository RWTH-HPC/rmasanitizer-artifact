/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file VCGASPIGroupBlock.cpp
 *       Block sync on groups
 *
 *  @date 06.09.2023
 *  @author Yussur Mustafa Oraji
 */

// RUN: %must-run --must:layout \
// RUN: %builddir/tests/VectorClock/VCGASPIGroupBlockLayout.xml \
// RUN: %must-bin-dir/VCGASPIGroupBlock 2>&1 \
// RUN: | %filecheck %s

// CHECK-DAG: shutdown(0){{.*}}clk=(3, 3, 0)
// CHECK-DAG: shutdown(1){{.*}}clk=(3, 4, 3)
// CHECK-DAG: shutdown(2){{.*}}clk=(3, 4, 3)

#include <GASPI.h>
#include <cstdio>
#include <cstdlib>
#include <mpi.h>

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

    gaspi_group_t group01;
    gaspi_group_t group12;

    gaspi_group_create(&group01);
    gaspi_group_create(&group12);

    gaspi_group_add(group01, 0);
    gaspi_group_add(group01, 1);

    gaspi_group_add(group12, 1);
    gaspi_group_add(group12, 2);

    gaspi_group_commit(group01, GASPI_BLOCK);
    gaspi_group_commit(group12, GASPI_BLOCK);

    if (rank != 2)
        gaspi_barrier(group01, GASPI_BLOCK);
    if (rank != 0)
        gaspi_barrier(group12, GASPI_BLOCK);

    gaspi_proc_term(GASPI_BLOCK);

    return EXIT_SUCCESS;
}
