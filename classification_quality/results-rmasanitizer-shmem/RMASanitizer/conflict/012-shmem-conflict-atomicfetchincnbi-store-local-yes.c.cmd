/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240406-162207/RMASanitizer/conflict/012-shmem-conflict-atomicfetchincnbi-store-local-yes.c -o results-20240406-162207/RMASanitizer/conflict/012-shmem-conflict-atomicfetchincnbi-store-local-yes.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results-20240406-162207/RMASanitizer/conflict/012-shmem-conflict-atomicfetchincnbi-store-local-yes.c.exe-must
