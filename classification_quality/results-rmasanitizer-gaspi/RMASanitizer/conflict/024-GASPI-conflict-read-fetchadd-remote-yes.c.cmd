/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results/results-rmasanitizer-gaspi/RMASanitizer/conflict/024-GASPI-conflict-read-fetchadd-remote-yes.c -o results/results-rmasanitizer-gaspi/RMASanitizer/conflict/024-GASPI-conflict-read-fetchadd-remote-yes.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 3 --must:output stdout --must:rma results/results-rmasanitizer-gaspi/RMASanitizer/conflict/024-GASPI-conflict-read-fetchadd-remote-yes.c.exe-must
