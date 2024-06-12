/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 *  @file VCTeamSplitStridedNested.cpp
 *
 *  @date 16.02.2023
 *  @author Simon Schwitanski
 */

// RUN: %must-run --must:layout \
// RUN: %builddir/tests/VectorClock/VCTeamSplitStridedNestedLayout.xml \
// RUN: --must:mpimode SPMD  %must-bin-dir/VCTeamSplitStridedNested 2>&1 \
// RUN: | FileCheck %s

// CHECK-DAG: shutdown(0){{.*}}clk=(3, 1, 2, 1, 3, 1, 2, 1, 3, 1, 2, 1)
// CHECK-DAG: shutdown(1){{.*}}clk=(3, 1, 2, 1, 3, 1, 2, 1, 3, 1, 2, 1)
// CHECK-DAG: shutdown(2){{.*}}clk=(3, 1, 2, 1, 3, 1, 2, 1, 3, 1, 2, 1)
// CHECK-DAG: shutdown(4){{.*}}clk=(3, 1, 2, 1, 3, 1, 2, 1, 3, 1, 2, 1)
// CHECK-DAG: shutdown(5){{.*}}clk=(3, 1, 2, 1, 3, 1, 2, 1, 3, 1, 2, 1)
// CHECK-DAG: shutdown(6){{.*}}clk=(3, 1, 2, 1, 3, 1, 2, 1, 3, 1, 2, 1)
// CHECK-DAG: shutdown(7){{.*}}clk=(3, 1, 2, 1, 3, 1, 2, 1, 3, 1, 2, 1)
// CHECK-DAG: shutdown(8){{.*}}clk=(3, 1, 2, 1, 3, 1, 2, 1, 3, 1, 2, 1)
// CHECK-DAG: shutdown(9){{.*}}clk=(3, 1, 2, 1, 3, 1, 2, 1, 3, 1, 2, 1)
// CHECK-DAG: shutdown(10){{.*}}clk=(3, 1, 2, 1, 3, 1, 2, 1, 3, 1, 2, 1)
// CHECK-DAG: shutdown(11){{.*}}clk=(3, 1, 2, 1, 3, 1, 2, 1, 3, 1, 2, 1)

#include <mpi.h>
#include <shmem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{

    shmem_init();

    int mype = shmem_my_pe();
    int npes = shmem_n_pes();

    shmem_team_t half_team;
    shmem_team_split_strided(SHMEM_TEAM_WORLD, 0, 2, npes / 2, NULL, 0, &half_team);

    if (half_team != SHMEM_TEAM_INVALID) {
        shmem_team_t quarter_team;
        shmem_team_split_strided(
            half_team,
            0,
            4,
            shmem_team_n_pes(half_team) / 2,
            NULL,
            0,
            &quarter_team);
        shmem_team_sync(half_team);

        if (quarter_team != SHMEM_TEAM_INVALID) {
            shmem_team_sync(quarter_team);
            shmem_team_destroy(quarter_team);
        }

        shmem_team_destroy(half_team);
    }

    shmem_team_sync(SHMEM_TEAM_WORLD);

    shmem_finalize();

    return 0;
}
