/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240330-171252/RMASanitizer/conflict/017-MPI-conflict-get-get-remote-no.c -o results-20240330-171252/RMASanitizer/conflict/017-MPI-conflict-get-get-remote-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 3 --must:output stdout --must:rma results-20240330-171252/RMASanitizer/conflict/017-MPI-conflict-get-get-remote-no.c.exe-must
