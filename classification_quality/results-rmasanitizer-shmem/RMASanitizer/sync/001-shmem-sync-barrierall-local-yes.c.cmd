/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240409-163106/RMASanitizer/sync/001-shmem-sync-barrierall-local-yes.c -o results-20240409-163106/RMASanitizer/sync/001-shmem-sync-barrierall-local-yes.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results-20240409-163106/RMASanitizer/sync/001-shmem-sync-barrierall-local-yes.c.exe-must
