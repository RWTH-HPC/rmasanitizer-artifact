/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240330-173751/RMASanitizer/sync/009-GASPI-sync-wait-allreduce-remote-no.c -o results-20240330-173751/RMASanitizer/sync/009-GASPI-sync-wait-allreduce-remote-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 3 --must:output stdout --must:rma results-20240330-173751/RMASanitizer/sync/009-GASPI-sync-wait-allreduce-remote-no.c.exe-must
