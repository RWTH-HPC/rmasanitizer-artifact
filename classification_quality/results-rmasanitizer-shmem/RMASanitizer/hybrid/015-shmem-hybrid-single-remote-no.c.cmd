/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240409-163106/RMASanitizer/hybrid/015-shmem-hybrid-single-remote-no.c -o results-20240409-163106/RMASanitizer/hybrid/015-shmem-hybrid-single-remote-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results-20240409-163106/RMASanitizer/hybrid/015-shmem-hybrid-single-remote-no.c.exe-must
