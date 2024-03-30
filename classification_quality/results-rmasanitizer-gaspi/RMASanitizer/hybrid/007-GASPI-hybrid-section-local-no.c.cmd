/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240330-173751/RMASanitizer/hybrid/007-GASPI-hybrid-section-local-no.c -o results-20240330-173751/RMASanitizer/hybrid/007-GASPI-hybrid-section-local-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results-20240330-173751/RMASanitizer/hybrid/007-GASPI-hybrid-section-local-no.c.exe-must
