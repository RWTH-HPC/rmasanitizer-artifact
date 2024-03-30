/opt/must/bin/must-cc -fopenmp -g -ldl results-20240330-164421/MUST-RMA/conflict/036-MPI-conflict-fop-fop-remote-no.c -o results-20240330-164421/MUST-RMA/conflict/036-MPI-conflict-fop-fop-remote-no.c.exe-must
/opt/must/bin/mustrun -np 3 --must:distributed --must:nodl --must:output stdout --must:tsan --must:rma results-20240330-164421/MUST-RMA/conflict/036-MPI-conflict-fop-fop-remote-no.c.exe-must
