/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results/results-rmasanitizer-gaspi/RMASanitizer/hybrid/015-GASPI-hybrid-single-remote-no.c -o results/results-rmasanitizer-gaspi/RMASanitizer/hybrid/015-GASPI-hybrid-single-remote-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results/results-rmasanitizer-gaspi/RMASanitizer/hybrid/015-GASPI-hybrid-single-remote-no.c.exe-must
