/opt/rmasanitizer/bin/must-cc -g -fopenmp -lsma -lGPI2 results-20240406-161127/RMASanitizer/atomic/004-MPI-atomic-disp-remote-no.c -o results-20240406-161127/RMASanitizer/atomic/004-MPI-atomic-disp-remote-no.c.exe-must
/opt/rmasanitizer/bin/mustrun -np 3 --must:output stdout --must:rma results-20240406-161127/RMASanitizer/atomic/004-MPI-atomic-disp-remote-no.c.exe-must
