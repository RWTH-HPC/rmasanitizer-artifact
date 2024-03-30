/opt/must/bin/must-cc -fopenmp -g -ldl results-20240330-164421/MUST-RMA/conflict/007-MPI-conflict-get-get-local-yes.c -o results-20240330-164421/MUST-RMA/conflict/007-MPI-conflict-get-get-local-yes.c.exe-must
/opt/must/bin/mustrun -np 2 --must:distributed --must:nodl --must:output stdout --must:tsan --must:rma results-20240330-164421/MUST-RMA/conflict/007-MPI-conflict-get-get-local-yes.c.exe-must
