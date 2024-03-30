/* Part of RMARaceBench, under BSD-3-Clause License
 * See https://github.com/RWTH-HPC/RMARaceBench/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

// RUN: %must-cc %s -o %must-bin-dir/%basename_t.exe %must-compiler-rma-flags %openshmem-flags
// RUN: %must-run --must:rma --must:rma-mode %must-rma-mode -np 2 %must-bin-dir/%basename_t.exe 2>&1 | %filecheck -DFILENAME=%basename_t %s
// CHECK-DAG: data race
// CHECK-DAG: [[FILENAME]]:53
// CHECK-DAG: [[FILENAME]]:55

// RACE LABELS BEGIN
/*
{
    "RACE_KIND": "local",
    "ACCESS_SET": ["local buffer write","load"],
    "RACE_PAIR": ["shmem_int_get@53","LOAD@55"],
    "NPROCS": 2,
    "CONSISTENCY_CALLS": ["shmem_quiet"],
    "SYNC_CALLS": ["shmem_barrier_all"],
    "DESCRIPTION": "Two conflicting operations get_nbi and load which are not correctly separated by a shmem_quiet leading to a local race. The shmem_quiet should be in between the two conflicting operations to be correct."
}
*/
// RACE LABELS END

#include <shmem.h>
#include <stdio.h>
#include <stdlib.h>

#define PROC_NUM 2

int main(int argc, char** argv)
{
    static int remote = 0;
    int localbuf = 1;

    shmem_init();

    int num_pe = shmem_n_pes();
    int my_pe = shmem_my_pe();

    if (num_pe != PROC_NUM) {
        printf("Got %d PEs, expected %d\n", num_pe, PROC_NUM);
        shmem_global_exit(1);
    }

    shmem_barrier_all();

    if (my_pe == 0) {
        int source = 1;

        // CONFLICT
        shmem_int_get_nbi(&localbuf, &remote, 1, 1);
        // CONFLICT
        printf("localbuf is %d\n", localbuf);
        shmem_quiet();
    }

    shmem_barrier_all();

    printf("PE %d: localbuf = %d, remote = %d, \n", my_pe, localbuf, remote);

    shmem_barrier_all();
    printf("Process %d: Execution finished, variable contents: remote = %d, localbuf = %d\n", my_pe, remote, localbuf);
    shmem_finalize();

    return 0;
}
