/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240330-172552/RMASanitizer/atomic/003-shmem-atomic-same-domain-remote-no.c -o results-20240330-172552/RMASanitizer/atomic/003-shmem-atomic-same-domain-remote-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 3 --must:output stdout --must:rma results-20240330-172552/RMASanitizer/atomic/003-shmem-atomic-same-domain-remote-no.c.exe-must
