/opt/must/bin/must-cc -fopenmp -g -ldl results-20240330-164421/MUST-RMA/hybrid/008-MPI-hybrid-section-local-no.c -o results-20240330-164421/MUST-RMA/hybrid/008-MPI-hybrid-section-local-no.c.exe-must
/opt/must/bin/mustrun -np 2 --must:distributed --must:nodl --must:output stdout --must:tsan --must:rma results-20240330-164421/MUST-RMA/hybrid/008-MPI-hybrid-section-local-no.c.exe-must