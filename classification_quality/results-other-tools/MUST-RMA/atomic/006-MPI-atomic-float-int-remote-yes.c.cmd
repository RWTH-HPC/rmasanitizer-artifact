/opt/must/bin/must-cc -fopenmp -g -ldl results-20240330-164421/MUST-RMA/atomic/006-MPI-atomic-float-int-remote-yes.c -o results-20240330-164421/MUST-RMA/atomic/006-MPI-atomic-float-int-remote-yes.c.exe-must
/opt/must/bin/mustrun -np 3 --must:distributed --must:nodl --must:output stdout --must:tsan --must:rma results-20240330-164421/MUST-RMA/atomic/006-MPI-atomic-float-int-remote-yes.c.exe-must
