/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240330-173751/RMASanitizer/sync/005-GASPI-sync-wait-barrier-remote-yes.c -o results-20240330-173751/RMASanitizer/sync/005-GASPI-sync-wait-barrier-remote-yes.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results-20240330-173751/RMASanitizer/sync/005-GASPI-sync-wait-barrier-remote-yes.c.exe-must
