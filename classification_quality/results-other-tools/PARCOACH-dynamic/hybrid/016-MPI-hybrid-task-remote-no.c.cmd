mpicc -fopenmp -O0 -g -S -emit-llvm results-20240330-164421/PARCOACH-dynamic/hybrid/016-MPI-hybrid-task-remote-no.c -o results-20240330-164421/PARCOACH-dynamic/hybrid/016-MPI-hybrid-task-remote-no.c.ll
parcoach -S --check=rma results-20240330-164421/PARCOACH-dynamic/hybrid/016-MPI-hybrid-task-remote-no.c.ll -o results-20240330-164421/PARCOACH-dynamic/hybrid/016-MPI-hybrid-task-remote-no.c-instrumented.ll
mpicc -fopenmp -O0 -g results-20240330-164421/PARCOACH-dynamic/hybrid/016-MPI-hybrid-task-remote-no.c-instrumented.ll -o results-20240330-164421/PARCOACH-dynamic/hybrid/016-MPI-hybrid-task-remote-no.c-instrumented.exe -Wl,-rpath=/opt/parcoach/lib /opt/parcoach/lib/libParcoachCollDynamic_MPI_C.so /opt/parcoach/lib/libParcoachRMADynamic_MPI_C.so
mpirun -np 2 results-20240330-164421/PARCOACH-dynamic/hybrid/016-MPI-hybrid-task-remote-no.c-instrumented.exe