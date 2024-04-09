/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240409-162050/RMASanitizer/sync/018-MPI-sync-fence-3procs-remote-yes.c -o results-20240409-162050/RMASanitizer/sync/018-MPI-sync-fence-3procs-remote-yes.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 3 --must:output stdout --must:rma results-20240409-162050/RMASanitizer/sync/018-MPI-sync-fence-3procs-remote-yes.c.exe-must
