/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 *  @file VCWaitUntil.cpp
 *
 *  @date 12.03.2022
 *  @author Simon Schwitanski
 */

// RUN: %must-run --must:layout \
// RUN: %builddir/tests/VectorClock/VCWaitUntilLayout.xml \
// RUN: --must:mpimode SPMD %must-bin-dir/VCWaitUntil 2>&1 \
// RUN: | FileCheck %s

// CHECK-DAG: shutdown(0){{.*}}clk=(3, 1, 1, 1)
// CHECK-DAG: shutdown(1){{.*}}clk=(3, 2, 1, 1)
// CHECK-DAG: shutdown(2){{.*}}clk=(1, 1, 1, 1)
// CHECK-DAG: shutdown(3){{.*}}clk=(1, 1, 1, 1)

#include <mpi.h>
#include <shmem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long pSync[_SHMEM_BCAST_SYNC_SIZE];

int main(int argc, char** argv)
{
    shmem_init();

    int mype = shmem_my_pe();
    int npes = shmem_n_pes();

    int* val = (int*)shmem_malloc(sizeof(int));
    *val = 0;

    if (mype == 0) {
        // PE0 signals to PE1
        shmem_int_atomic_set(val, 42, 1);
    } else if (mype == 1) {
        // PE1 waits for signal of PE0
        shmem_int_wait_until(val, SHMEM_CMP_EQ, 42);
    }

    // do not free here to avoid synchronization such that we can check the vector clocks
    // of the wait until operation
    // shmem_free(val);

    shmem_finalize();
}
