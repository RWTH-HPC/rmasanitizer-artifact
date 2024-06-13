#!/usr/bin/env sh

# Run tests for RMASanitizer
python run_test.py tools --rma-model MPIRMA -o results/results-rmasanitizer-mpirma --tool 'RMASanitizer'
python run_test.py tools --rma-model SHMEM -o results/results-rmasanitizer-shmem --tool 'RMASanitizer'
python run_test.py tools --rma-model GASPI -o results/results-rmasanitizer-gaspi --tool 'RMASanitizer'

# Run tests for the other tools
python run_test.py tools --rma-model MPIRMA -o results/results-other-tools --tool 'MUST-RMA' 'PARCOACH-dynamic' 'PARCOACH-static'