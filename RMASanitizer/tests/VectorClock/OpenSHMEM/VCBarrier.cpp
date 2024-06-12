/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 *  @file VCBarrier.cpp
 *
 *  @date 12.03.2022
 *  @author Simon Schwitanski
 */

// RUN: %must-run --must:layout \
// RUN: %builddir/tests/VectorClock/VCBarrierLayout.xml \
// RUN: --must:mpimode SPMD %must-bin-dir/VCBarrier 2>&1 \
// RUN: | FileCheck %s

// CHECK-DAG: shutdown(0){{.*}}clk=(1, 1, 1, 1)
// CHECK-DAG: shutdown(1){{.*}}clk=(1, 1, 1, 1)
// CHECK-DAG: shutdown(2){{.*}}clk=(1, 1, 2, 2)
// CHECK-DAG: shutdown(3){{.*}}clk=(1, 1, 2, 2)

#include <mpi.h>
#include <shmem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NPROCS 4
long pSync[4 * NPROCS]; // for some reason Sandia OpenSHMEM needs a 4 times larger pSync array

int main(int argc, char** argv)
{
    int numprocs, mype, npes, i;

    shmem_init();

    mype = shmem_my_pe();
    npes = shmem_n_pes();
    printf("mype is %d\n", mype);

    for (i = 0; i < 4 * NPROCS; i += 1)
        pSync[i] = _SHMEM_SYNC_VALUE;

    shmem_barrier(0, 0, npes, pSync);

    if (mype == 2 || mype == 3) // ranks 2 and 3 perform a barrier
    {
        shmem_barrier(2, 0, 2, pSync);
    }

    shmem_finalize();
}
