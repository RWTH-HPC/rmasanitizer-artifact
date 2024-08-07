/* Part of the MUST Project, under BSD-3-Clause License
 * See https://hpc.rwth-aachen.de/must/LICENSE for license information.
 * SPDX-License-Identifier: BSD-3-Clause
 */

// RUN: %must-run %mpiexec-numproc-flag 4 \
// RUN: %must-bin-dir/IntegerEntryGreaterEqualArrayNoError 2>&1 \
// RUN: | %filecheck --implicit-check-not \
// RUN: '[MUST-REPORT]{{.*(Error|ERROR|Warning|WARNING)}}' %s

/**
 * @file IntegerEntryGreaterEqualArrayNoError.cpp
 * This is a a test for the analysis group BasicChecks.
 *
 * Description:
 * Creates a graph communicator, without any errors or warnings.
 *
 *  @date 11.04.2011
 *  @author Mathias Korepkat
 */

#include <iostream>
#include <mpi.h>

int main(int argc, char** argv)
{
    int size, rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    //Enough tasks ?
    if (size < 4) {
        std::cerr << "This test needs at least 4 processes!" << std::endl;
        MPI_Finalize();
        return 1;
    }

    //Say hello
    std::cout << "Hello, I am rank " << rank << " of " << size << " processes." << std::endl;

    MPI_Comm comm1;
    int index[4] = {2, 3, 4, 6};
    int edges[6] = {1, 3, 0, 3, 0, 2};

    MPI_Graph_create(MPI_COMM_WORLD, 4, index, edges, 0, &comm1);

    MPI_Comm_free(&comm1);
    //Say bye bye
    std::cout << "Signing off, rank " << rank << "." << std::endl;

    MPI_Finalize();

    return 0;
}
