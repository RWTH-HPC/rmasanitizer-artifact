/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240330-171252/RMASanitizer/hybrid/020-MPI-hybrid-for-remote-yes.c -o results-20240330-171252/RMASanitizer/hybrid/020-MPI-hybrid-for-remote-yes.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results-20240330-171252/RMASanitizer/hybrid/020-MPI-hybrid-for-remote-yes.c.exe-must
