/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240409-163106/RMASanitizer/sync/022-shmem-sync-team-sync-remote-no.c -o results-20240409-163106/RMASanitizer/sync/022-shmem-sync-team-sync-remote-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 4 --must:output stdout --must:rma results-20240409-163106/RMASanitizer/sync/022-shmem-sync-team-sync-remote-no.c.exe-must
