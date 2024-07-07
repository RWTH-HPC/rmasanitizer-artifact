/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results/results-rmasanitizer-gaspi/RMASanitizer/sync/001-GASPI-sync-wait-local-yes.c -o results/results-rmasanitizer-gaspi/RMASanitizer/sync/001-GASPI-sync-wait-local-yes.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results/results-rmasanitizer-gaspi/RMASanitizer/sync/001-GASPI-sync-wait-local-yes.c.exe-must
