mpicc -fopenmp -O0 -g -S -emit-llvm results-20240330-164421/PARCOACH-static/sync/004-MPI-sync-lock-local-no.c -o results-20240330-164421/PARCOACH-static/sync/004-MPI-sync-lock-local-no.c.ll
parcoach -S --check=rma results-20240330-164421/PARCOACH-static/sync/004-MPI-sync-lock-local-no.c.ll -o results-20240330-164421/PARCOACH-static/sync/004-MPI-sync-lock-local-no.c-instrumented.ll
