/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 *  @file VCTeamSplitStridedSimple.cpp
 *
 *  @date 16.02.2023
 *  @author Simon Schwitanski
 */

// RUN: %must-run --must:layout \
// RUN: %builddir/tests/VectorClock/VCTeamSplitStridedSimpleLayout.xml \
// RUN: --must:mpimode SPMD  %must-bin-dir/VCTeamSplitStridedSimple 2>&1 \
// RUN: | FileCheck %s

// CHECK-DAG: shutdown(0){{.*}}clk=(2, 1, 2, 1, 2, 1, 2, 1, 2, 1)
// CHECK-DAG: shutdown(1){{.*}}clk=(2, 1, 2, 1, 2, 1, 2, 1, 2, 1)
// CHECK-DAG: shutdown(2){{.*}}clk=(2, 1, 2, 1, 2, 1, 2, 1, 2, 1)
// CHECK-DAG: shutdown(4){{.*}}clk=(2, 1, 2, 1, 2, 1, 2, 1, 2, 1)
// CHECK-DAG: shutdown(5){{.*}}clk=(2, 1, 2, 1, 2, 1, 2, 1, 2, 1)
// CHECK-DAG: shutdown(6){{.*}}clk=(2, 1, 2, 1, 2, 1, 2, 1, 2, 1)
// CHECK-DAG: shutdown(7){{.*}}clk=(2, 1, 2, 1, 2, 1, 2, 1, 2, 1)
// CHECK-DAG: shutdown(8){{.*}}clk=(2, 1, 2, 1, 2, 1, 2, 1, 2, 1)
// CHECK-DAG: shutdown(9){{.*}}clk=(2, 1, 2, 1, 2, 1, 2, 1, 2, 1)

#include <mpi.h>
#include <shmem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Example taken from SHMEM specification

int main(int argc, char** argv)
{
    shmem_team_t new_team;
    shmem_team_config_t* config;

    shmem_init();

    config = NULL;
    int mype = shmem_my_pe();
    int npes = shmem_n_pes();
    shmem_team_split_strided(SHMEM_TEAM_WORLD, 0, 2, npes / 2, config, 0, &new_team);
    if (new_team != SHMEM_TEAM_INVALID) {
        int team_npes = shmem_team_n_pes(new_team);
        int team_mype = shmem_team_my_pe(new_team);
        if ((mype % 2 != 0) || (mype / 2 != team_mype) || (npes / 2 != team_npes)) {
            shmem_global_exit(1);
        }

        shmem_team_sync(new_team);
    }

    shmem_team_sync(SHMEM_TEAM_WORLD);

    shmem_finalize();

    return 0;
}
