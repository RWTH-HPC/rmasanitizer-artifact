/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

// RUN: %must-run-ddl %mpiexec-numproc-flag 2 %must-bin-dir/OverlapIbcast 2>&1 \
// RUN: | %filecheck %s

// CHECK-DAG: [MUST-REPORT]{{.*Error[:] from[:] call MPI_Recv@0[:] The memory regions to be transfered by this receive operation overlap with regions spanned by a pending non-blocking operation!}}
// CHECK-DAG: [MUST-REPORT]{{.*Error[:] from[:] call MPI_Send@1[:] The memory regions to be transfered by this send operation overlap with regions spanned by a pending non-blocking receive operation!}}

/**
 * @file overlapIbcast.c
 * A must overlap test.
 * Bcast that overlaps a pending receive request
 *
 * @author Joachim Protze
 */
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include "mustTest.h"

#define COUNT 4

int main(int argc, char** argv)
{

    int i = 0, rank, size;
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
    for (i = 0; i < COUNT; i++) {
        request[i] = MPI_REQUEST_NULL;
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

    MPI_Ibcast(inbuf, 1, structtype, 0, MPI_COMM_WORLD, request);

    if (rank == 1) {
        for (i = 0; i < COUNT; i++) {
            MPI_Send(inbuf + i, 1, structtype, 0, 42 + i, MPI_COMM_WORLD);
        }
    }

    if (rank == 0) {
        for (i = 0; i < COUNT; i++) {
            MPI_Recv(inbuf + i, 1, structtype, 1, 42 + i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    }

    //    if (rank == 0 || rank == 1)
    //    {
    MPI_Waitall(COUNT, request, status);
    //    }

    //     MPI_Startall(COUNT,request);
    MPI_Type_free(&vectortype);
    MPI_Type_free(&structtype);
    free(inbuf);

    MPI_Finalize();

    return 0;
}
