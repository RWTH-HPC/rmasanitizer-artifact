mpicc -fopenmp -O0 -g -S -emit-llvm results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c -o results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c.ll
parcoach -S --check=rma results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c.ll -o results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c-instrumented.ll
mpicc -fopenmp -O0 -g results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c-instrumented.ll -o results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c-instrumented.exe -Wl,-rpath=/opt/parcoach/lib /opt/parcoach/lib/libParcoachCollDynamic_MPI_C.so /opt/parcoach/lib/libParcoachRMADynamic_MPI_C.so
mpirun -np 2 results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c-instrumented.exe
mpirun -np 2 results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c-instrumented.exe
mpirun -np 2 results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c-instrumented.exe
mpirun -np 2 results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c-instrumented.exe
mpirun -np 2 results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c-instrumented.exe
mpirun -np 2 results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c-instrumented.exe
mpirun -np 2 results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c-instrumented.exe
mpirun -np 2 results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c-instrumented.exe
mpirun -np 2 results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c-instrumented.exe
mpirun -np 2 results-20240330-164421/PARCOACH-dynamic/sync/023-MPI-sync-lock-barrier-sameorigin-remote-no.c-instrumented.exe
