/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240409-163106/RMASanitizer/conflict/049-shmem-conflict-atomiccompareswapnbi-atomicfetchnbi-remote-no.c -o results-20240409-163106/RMASanitizer/conflict/049-shmem-conflict-atomiccompareswapnbi-atomicfetchnbi-remote-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 3 --must:output stdout --must:rma results-20240409-163106/RMASanitizer/conflict/049-shmem-conflict-atomiccompareswapnbi-atomicfetchnbi-remote-no.c.exe-must
