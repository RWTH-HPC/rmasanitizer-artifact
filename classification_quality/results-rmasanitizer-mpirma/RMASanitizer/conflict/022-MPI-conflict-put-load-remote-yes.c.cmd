/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240406-161127/RMASanitizer/conflict/022-MPI-conflict-put-load-remote-yes.c -o results-20240406-161127/RMASanitizer/conflict/022-MPI-conflict-put-load-remote-yes.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 2 --must:output stdout --must:rma results-20240406-161127/RMASanitizer/conflict/022-MPI-conflict-put-load-remote-yes.c.exe-must
