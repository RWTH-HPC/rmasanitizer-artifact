mpicc -fopenmp -O0 -g -S -emit-llvm results-20240330-164421/PARCOACH-static/sync/005-MPI-sync-lock-flush-local-yes.c -o results-20240330-164421/PARCOACH-static/sync/005-MPI-sync-lock-flush-local-yes.c.ll
parcoach -S --check=rma results-20240330-164421/PARCOACH-static/sync/005-MPI-sync-lock-flush-local-yes.c.ll -o results-20240330-164421/PARCOACH-static/sync/005-MPI-sync-lock-flush-local-yes.c-instrumented.ll
