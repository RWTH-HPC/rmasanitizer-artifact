mpicc -fopenmp -O0 -g -S -emit-llvm results-20240330-164421/PARCOACH-static/sync/001-MPI-sync-fence-local-yes.c -o results-20240330-164421/PARCOACH-static/sync/001-MPI-sync-fence-local-yes.c.ll
parcoach -S --check=rma results-20240330-164421/PARCOACH-static/sync/001-MPI-sync-fence-local-yes.c.ll -o results-20240330-164421/PARCOACH-static/sync/001-MPI-sync-fence-local-yes.c-instrumented.ll
