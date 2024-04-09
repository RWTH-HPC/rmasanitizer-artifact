/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240409-162050/RMASanitizer/conflict/007-MPI-conflict-get-get-local-yes.c -o results-20240409-162050/RMASanitizer/conflict/007-MPI-conflict-get-get-local-yes.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results-20240409-162050/RMASanitizer/conflict/007-MPI-conflict-get-get-local-yes.c.exe-must
