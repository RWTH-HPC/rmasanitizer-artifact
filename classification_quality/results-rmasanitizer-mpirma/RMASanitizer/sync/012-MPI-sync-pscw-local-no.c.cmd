/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240409-162050/RMASanitizer/sync/012-MPI-sync-pscw-local-no.c -o results-20240409-162050/RMASanitizer/sync/012-MPI-sync-pscw-local-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results-20240409-162050/RMASanitizer/sync/012-MPI-sync-pscw-local-no.c.exe-must
