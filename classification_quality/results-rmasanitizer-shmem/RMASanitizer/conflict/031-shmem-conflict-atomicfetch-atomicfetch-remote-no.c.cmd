/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240330-172552/RMASanitizer/conflict/031-shmem-conflict-atomicfetch-atomicfetch-remote-no.c -o results-20240330-172552/RMASanitizer/conflict/031-shmem-conflict-atomicfetch-atomicfetch-remote-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 3 --must:output stdout --must:rma results-20240330-172552/RMASanitizer/conflict/031-shmem-conflict-atomicfetch-atomicfetch-remote-no.c.exe-must
