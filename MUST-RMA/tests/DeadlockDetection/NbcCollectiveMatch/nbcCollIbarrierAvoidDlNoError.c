/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

// RUN: %must-run %mpiexec-numproc-flag 3 --must:fanin 2 \
// RUN: %must-bin-dir/DnbcCollIbarrierAvoidDlNoError 2>&1 \
// RUN: | %filecheck --implicit-check-not \
// RUN: '[MUST-REPORT]{{.*(Error|ERROR|Warning|WARNING)}}' %s

/**
 * @file nbcCollIbarrierAvoidDlNoError.c
 * A test with a correct MPI_Ibarrier call (No Error).
 *
 * Description:
 * The test interlinks an MPI_Ibarrier with P2P communication such that it would deadlock with an MPI_Barrier instead,
 * while with the non-blocking collective it is correct.
 *
 * @author Tobias Hilbrich
 */

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int rank, size;
    MPI_Status status;
    MPI_Request request;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    //Enough tasks ?
    if (size < 2) {
        printf("This test needs at least 2 processes!\n");
        MPI_Finalize();
        return 1;
    }

    //Say hello
    printf("Hello, I am rank %d of %d processes.\n", rank, size);

    //Start a receive
    if (rank == 1) {
        MPI_Recv(&size, 1, MPI_INT, 0, 666, MPI_COMM_WORLD, &status);
    }

    //Intermix a non-blocking collective
    MPI_Ibarrier(MPI_COMM_WORLD, &request);

    //Finish up the P2P communication (receive above)
    if (rank == 0) {
        MPI_Send(&size, 1, MPI_INT, 1, 666, MPI_COMM_WORLD);
    }

    //Complete the non-blocking collective
    MPI_Wait(&request, &status);

    //Say bye bye
    printf("Signing off, rank %d.\n", rank);

    MPI_Finalize();

    return 0;
}
