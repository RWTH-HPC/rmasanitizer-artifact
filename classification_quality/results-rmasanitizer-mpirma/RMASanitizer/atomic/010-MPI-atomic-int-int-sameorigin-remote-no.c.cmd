/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240330-171252/RMASanitizer/atomic/010-MPI-atomic-int-int-sameorigin-remote-no.c -o results-20240330-171252/RMASanitizer/atomic/010-MPI-atomic-int-int-sameorigin-remote-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results-20240330-171252/RMASanitizer/atomic/010-MPI-atomic-int-int-sameorigin-remote-no.c.exe-must
