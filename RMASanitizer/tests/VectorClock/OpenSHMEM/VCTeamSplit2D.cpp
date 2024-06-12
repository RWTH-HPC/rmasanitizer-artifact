/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 *  @file VCTeamSplit2D.cpp
 *
 *  @date 16.02.2023
 *  @author Simon Schwitanski
 */

// RUN: %must-run --must:layout \
// RUN: %builddir/tests/VectorClock/VCTeamSplit2DLayout.xml \
// RUN: --must:mpimode SPMD  %must-bin-dir/VCTeamSplit2D 2>&1 \
// RUN: | FileCheck %s

// CHECK-DAG: shutdown(0){{.*}}clk=(1, 1, 2, 2, 2, 3, 1, 1, 2, 1, 1, 2)
// CHECK-DAG: shutdown(1){{.*}}clk=(1, 1, 2, 2, 2, 3, 1, 1, 2, 1, 1, 2)
// CHECK-DAG: shutdown(2){{.*}}clk=(1, 1, 2, 2, 2, 3, 1, 1, 2, 1, 1, 2)
// CHECK-DAG: shutdown(4){{.*}}clk=(1, 1, 2, 2, 2, 3, 1, 1, 2, 1, 1, 2)
// CHECK-DAG: shutdown(5){{.*}}clk=(1, 1, 2, 2, 2, 3, 1, 1, 2, 1, 1, 2)
// CHECK-DAG: shutdown(6){{.*}}clk=(1, 1, 2, 2, 2, 3, 1, 1, 2, 1, 1, 2)
// CHECK-DAG: shutdown(7){{.*}}clk=(1, 1, 2, 2, 2, 3, 1, 1, 2, 1, 1, 2)
// CHECK-DAG: shutdown(8){{.*}}clk=(1, 1, 2, 2, 2, 3, 1, 1, 2, 1, 1, 2)
// CHECK-DAG: shutdown(9){{.*}}clk=(1, 1, 2, 2, 2, 3, 1, 1, 2, 1, 1, 2)
// CHECK-DAG: shutdown(10){{.*}}clk=(1, 1, 2, 2, 2, 3, 1, 1, 2, 1, 1, 2)
// CHECK-DAG: shutdown(11){{.*}}clk=(1, 1, 2, 2, 2, 3, 1, 1, 2, 1, 1, 2)

#include <mpi.h>
#include <shmem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    shmem_team_t new_team;
    shmem_team_config_t* config;
    shmem_init();

    int mype = shmem_my_pe();
    int npes = shmem_n_pes();

    int xdim = 3;
    int ydim = npes / xdim;
    shmem_team_t xteam, yteam;
    shmem_team_split_2d(SHMEM_TEAM_WORLD, xdim, NULL, 0, &xteam, NULL, 0, &yteam);

    // sync across x-row
    if (mype / xdim == 1) {
        shmem_team_sync(xteam);
    }

    // sync across y-column
    if (mype % xdim == 2) {
        shmem_team_sync(yteam);
    }

    shmem_team_sync(SHMEM_TEAM_WORLD);

    shmem_finalize();

    return 0;
}
