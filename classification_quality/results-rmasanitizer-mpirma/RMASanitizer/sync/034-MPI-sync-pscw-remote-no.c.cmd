/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240409-162050/RMASanitizer/sync/034-MPI-sync-pscw-remote-no.c -o results-20240409-162050/RMASanitizer/sync/034-MPI-sync-pscw-remote-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 3 --must:output stdout --must:rma results-20240409-162050/RMASanitizer/sync/034-MPI-sync-pscw-remote-no.c.exe-must
