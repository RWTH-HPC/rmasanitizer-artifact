/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240406-163658/RMASanitizer/hybrid/009-GASPI-hybrid-task-local-no.c -o results-20240406-163658/RMASanitizer/hybrid/009-GASPI-hybrid-task-local-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results-20240406-163658/RMASanitizer/hybrid/009-GASPI-hybrid-task-local-no.c.exe-must
