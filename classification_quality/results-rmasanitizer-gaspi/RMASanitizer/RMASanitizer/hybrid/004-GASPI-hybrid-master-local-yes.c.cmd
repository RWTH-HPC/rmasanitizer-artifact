/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240406-163658/RMASanitizer/hybrid/004-GASPI-hybrid-master-local-yes.c -o results-20240406-163658/RMASanitizer/hybrid/004-GASPI-hybrid-master-local-yes.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results-20240406-163658/RMASanitizer/hybrid/004-GASPI-hybrid-master-local-yes.c.exe-must
