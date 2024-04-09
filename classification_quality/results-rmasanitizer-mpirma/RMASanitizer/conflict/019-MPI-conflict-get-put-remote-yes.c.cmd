/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240409-162050/RMASanitizer/conflict/019-MPI-conflict-get-put-remote-yes.c -o results-20240409-162050/RMASanitizer/conflict/019-MPI-conflict-get-put-remote-yes.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 3 --must:output stdout --must:rma results-20240409-162050/RMASanitizer/conflict/019-MPI-conflict-get-put-remote-yes.c.exe-must
