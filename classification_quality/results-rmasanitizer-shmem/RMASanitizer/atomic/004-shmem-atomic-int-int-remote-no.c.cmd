/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240406-162207/RMASanitizer/atomic/004-shmem-atomic-int-int-remote-no.c -o results-20240406-162207/RMASanitizer/atomic/004-shmem-atomic-int-int-remote-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 3 --must:output stdout --must:rma results-20240406-162207/RMASanitizer/atomic/004-shmem-atomic-int-int-remote-no.c.exe-must
