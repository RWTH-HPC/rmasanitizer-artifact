/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240406-161127/RMASanitizer/sync/011-MPI-sync-pscw-local-yes.c -o results-20240406-161127/RMASanitizer/sync/011-MPI-sync-pscw-local-yes.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results-20240406-161127/RMASanitizer/sync/011-MPI-sync-pscw-local-yes.c.exe-must
