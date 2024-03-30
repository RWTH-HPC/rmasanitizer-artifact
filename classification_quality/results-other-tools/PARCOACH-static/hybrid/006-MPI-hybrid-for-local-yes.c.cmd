mpicc -fopenmp -O0 -g -S -emit-llvm results-20240330-164421/PARCOACH-static/hybrid/006-MPI-hybrid-for-local-yes.c -o results-20240330-164421/PARCOACH-static/hybrid/006-MPI-hybrid-for-local-yes.c.ll
parcoach -S --check=rma results-20240330-164421/PARCOACH-static/hybrid/006-MPI-hybrid-for-local-yes.c.ll -o results-20240330-164421/PARCOACH-static/hybrid/006-MPI-hybrid-for-local-yes.c-instrumented.ll
