/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240406-162207/RMASanitizer/conflict/034-shmem-conflict-put_signal-store-remote-yes.c -o results-20240406-162207/RMASanitizer/conflict/034-shmem-conflict-put_signal-store-remote-yes.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results-20240406-162207/RMASanitizer/conflict/034-shmem-conflict-put_signal-store-remote-yes.c.exe-must
