/* Part of RMARaceBench, under BSD-3-Clause License
 * See https://github.com/RWTH-HPC/RMARaceBench/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

// RUN: %must-cc %s -o %must-bin-dir/%basename_t.exe %must-compiler-rma-flags %openshmem-flags
// RUN: %must-run --must:rma --must:rma-mode %must-rma-mode -np 3 %must-bin-dir/%basename_t.exe 2>&1 | %filecheck -DFILENAME=%basename_t %s
// CHECK-DAG: data race
// CHECK-DAG: [[FILENAME]]:50
// CHECK-DAG: [[FILENAME]]:57

// RACE LABELS BEGIN
/*
{
    "RACE_KIND": "remote",
    "ACCESS_SET": ["rma write","rma write"],
    "RACE_PAIR": ["shmem_int_put_signal@50","shmem_int_put_signal@57"],
    "NPROCS": 3,
    "DESCRIPTION": "Two conflicting operations put_signal and put_signal executed concurrently which leads to a race."
}
*/
// RACE LABELS END

#include <shmem.h>
#include <stdio.h>
#include <stdlib.h>

#define PROC_NUM 3

int main(int argc, char** argv)
{
    static int remote = 0;
    int localbuf = 1;
    static uint64_t ps_sig_addr = 0;
    static uint64_t ps_sig_addr2 = 0;

    shmem_init();

    int num_pe = shmem_n_pes();
    int my_pe = shmem_my_pe();

    if (num_pe != PROC_NUM) {
        printf("Got %d PEs, expected %d\n", num_pe, PROC_NUM);
        shmem_global_exit(1);
    }
    shmem_barrier_all();

    if (my_pe == 0) {
        // CONFLICT
        shmem_int_put_signal(&remote, &localbuf, 1, &ps_sig_addr, 1, SHMEM_SIGNAL_SET, 1);
    }

    if (my_pe == 2) {
        localbuf = 2;

        // CONFLICT
        shmem_int_put_signal(&remote, &localbuf, 1, &ps_sig_addr2, 1, SHMEM_SIGNAL_SET, 1);
    }

    shmem_barrier_all();

    printf("PE %d: localbuf = %d, remote = %d, \n", my_pe, localbuf, remote);

    shmem_barrier_all();
    printf("Process %d: Execution finished, variable contents: remote = %d, localbuf = %d\n", my_pe, remote, localbuf);
    shmem_finalize();

    return 0;
}
