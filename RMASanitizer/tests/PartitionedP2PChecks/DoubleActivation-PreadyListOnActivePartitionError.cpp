/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

// UNSUPPORTED: fast-tests
// RUN: %must-run %mpiexec-numproc-flag 2 %must-bin-dir/DoubleActivation-PreadyListOnActivePartitionError \
// RUN: 2>&1 \
// RUN: | %filecheck-may-segfault --check-prefix=CHECK-STANDARD %s

// RUN: %must-run --must:stacktrace backward --must:partitioned_verbose_report %mpiexec-numproc-flag 2 %must-bin-dir/DoubleActivation-PreadyListOnActivePartitionError \
// RUN: 2>&1 \
// RUN: | %filecheck-may-segfault --check-prefix=CHECK-ST %s

// CHECK-STANDARD: [MUST-REPORT]{{.*Calling MPI_Pready_[*] on active partition[(]s[)][(].*[)] is erroneous.*}}
// CHECK-ST: [MUST-REPORT]{{.*Found the following already active partitions, which is erroneous.*}}

/**
 * @file DoubleActivation-PreadyListOnActivePartitionError.cpp
 * This is a test for the analysis group PartitionedP2PChecks.
 *
 * Description:
 * Performs a partitioned send and receive test with MPI_Pready_list instead of MPI_Pready.
 * Pready_list is called on partitions that are already active, which is erroneous.
 *
 *  @date 02.10.2022
 *  @author Niko Sakic
 */

#include <iostream>
#include <mpi.h>
#define PARTITIONS 20
#define COUNT 5
int main(int argc, char** argv)
{
    double message[PARTITIONS * COUNT];
    MPI_Count partitions = PARTITIONS;
    int size, rank;
    int source = 0, dest = 1, tag = 1, flag = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Request request;

    //Enough tasks ?
    if (size < 2) {
        std::cerr << "This test needs at least 2 processes!" << std::endl;
        MPI_Finalize();
        return 1;
    }

    //Say hello
    std::cout << "Hello, I am rank " << rank << " of " << size << " processes." << std::endl;

    if (rank == 0) {
        MPI_Psend_init(
            message,
            partitions,
            COUNT,
            MPI_DOUBLE,
            dest,
            tag,
            MPI_COMM_WORLD,
            MPI_INFO_NULL,
            &request);
        MPI_Start(&request);
        int array[20];
        for (int x = 0; x < 20; ++x) {
            array[x] = x;
        }
        // CHECK-ST: PreadyListOnActivePartitionError.cpp:[[@LINE+1]]
        MPI_Pready(4, request);
        // CHECK-ST: PreadyListOnActivePartitionError.cpp:[[@LINE+1]]
        MPI_Pready(8, request);
        // CHECK-ST: PreadyListOnActivePartitionError.cpp:[[@LINE+1]]
        MPI_Pready(9, request);

        MPI_Pready_list(20, array, request);

        while (!flag) {
            /* do useful work #1 */
            MPI_Test(&request, &flag, MPI_STATUS_IGNORE);
            /* do useful work #2 */
        }
        MPI_Request_free(&request);
    }

    if (rank == 1) {
        MPI_Precv_init(
            message,
            partitions,
            COUNT,
            MPI_DOUBLE,
            source,
            tag,
            MPI_COMM_WORLD,
            MPI_INFO_NULL,
            &request);
        MPI_Start(&request);
        while (!flag) {
            /* do useful work #1 */
            MPI_Test(&request, &flag, MPI_STATUS_IGNORE);
            /* do useful work #2 */
        }
        MPI_Request_free(&request);
    }

    //Say bye bye
    std::cout << "Signing off, rank " << rank << "." << std::endl;

    MPI_Finalize();

    return 0;
}
