/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240330-173751/RMASanitizer/hybrid/015-GASPI-hybrid-single-remote-no.c -o results-20240330-173751/RMASanitizer/hybrid/015-GASPI-hybrid-single-remote-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results-20240330-173751/RMASanitizer/hybrid/015-GASPI-hybrid-single-remote-no.c.exe-must
