// RUN: %must-cc %s -o %must-bin-dir/%basename_t.exe %must-compiler-rma-flags
// RUN: %must-run --must:rma --must:rma-mode %must-rma-mode -np 2 %must-bin-dir/%basename_t.exe 2>&1 | %filecheck -DFILENAME=%basename_t %s

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PROC_NUM 2
#define WIN_SIZE 1024

int main(int argc, char** argv)
{
    int rank, size;
    MPI_Win win;
    int* win_base;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != PROC_NUM) {
        printf("Wrong number of MPI processes. Expected: %d\n", PROC_NUM);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    MPI_Win_allocate(
        WIN_SIZE * sizeof(int),
        sizeof(int),
        MPI_INFO_NULL,
        MPI_COMM_WORLD,
        &win_base,
        &win);
    for (int i = 0; i < WIN_SIZE; i++) {
        win_base[i] = 0;
    }
    MPI_Barrier(MPI_COMM_WORLD);

    if (rank == 0) {
        MPI_Win_lock(MPI_LOCK_EXCLUSIVE, 1, 0, win);
        // send "signal" to rank 1
        char value = 1;
        // CHECK-DAG: [[FILENAME]]:[[@LINE+1]]
        MPI_Put(&value, 1, MPI_BYTE, 1, 0, 1, MPI_BYTE, win);
        MPI_Win_unlock(1, win);
    } else {
        sleep(
            1); // ensures that rank 0 gets the lock first, otherwise there is no race in the execution path
        // conflicting concurrent access
        // CHECK-DAG: [[FILENAME]]:[[@LINE+1]]
        win_base[0] = 42;
        MPI_Win_lock(MPI_LOCK_EXCLUSIVE, 1, 0, win);
        MPI_Win_unlock(1, win);
    }

    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Win_free(&win);

    MPI_Finalize();
}

// CHECK-DAG: data race