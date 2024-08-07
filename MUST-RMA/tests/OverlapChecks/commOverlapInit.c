/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

// RUN: %must-run %mpiexec-numproc-flag 2 %must-bin-dir/CommOverlapInit 2>&1 \
// RUN: | %filecheck %s

// CHECK: [MUST-REPORT] Error: from: call MPI_Startall@1: A start of a persistent request will transfer memory regions that are still used by a pending non-blocking communication!
// CHECK: [MUST-REPORT] References of a representative process:
// CHECK: Reference 1: call MPI_Recv_init@rank 1

/**
 * @file commOverlap.c
 * A must overlap test.
 * Creates overlapping persistent requests
 *
 * @author Joachim Protze
 */
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include "mustTest.h"

#define COUNT 6

int main(int argc, char** argv)
{

    int i, rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Status status[COUNT];
    MPI_Request request[COUNT];
    //Enough tasks ?
    if (size < 2) {
        printf("This test needs at least 2 processes!\n");
        MPI_Finalize();
        return 1;
    }

    MPI_Datatype vectortype, structtype;

    MPI_Type_vector(10, 1, 5, MPI_INT, &vectortype);

    MPI_Aint displs[3] = {0, 0, 4};

    MPI_Type_extent(MPI_INT, displs + 2);

    int* inbuf = malloc(100000);
#ifdef HAVE_MPI_TYPE_CREATE_RESIZED
    MPI_Type_create_resized(vectortype, displs[0], displs[2], &structtype);
#else
    int blocklens[3] = {1, 1, 1};
    MPI_Datatype types[3] = {MPI_LB, vectortype, MPI_UB};
    MPI_Type_struct(3, blocklens, displs, types, &structtype);
#endif
    MPI_Type_commit(&structtype);

    //Say hello
    printf("Hello, I am rank %i of %i processes.\n", rank, size);
    ;

    if (rank == 0) {
        for (i = 0; i < COUNT; i++) {
            MPI_Send_init(inbuf + i, 1, structtype, 1, 42 + i, MPI_COMM_WORLD, &(request[i]));
        }
        MPI_Startall(COUNT, request);
        MPI_Waitall(COUNT, request, status);
        for (i = 0; i < COUNT; i++) {
            MPI_Request_free(&(request[i]));
        }
    }

    if (rank == 1) {
        for (i = 0; i < COUNT; i++) {
            MPI_Recv_init(inbuf + i, 1, structtype, 0, 42 + i, MPI_COMM_WORLD, &(request[i]));
        }
        MPI_Startall(COUNT, request);
        MPI_Waitall(COUNT, request, status);
        for (i = 0; i < COUNT; i++) {
            MPI_Request_free(&(request[i]));
        }
    }
    //     MPI_Startall(COUNT,request);
    MPI_Type_free(&vectortype);
    MPI_Type_free(&structtype);
    free(inbuf);

    MPI_Finalize();

    return 0;
}
