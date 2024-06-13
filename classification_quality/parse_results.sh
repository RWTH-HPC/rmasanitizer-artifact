#!/usr/bin/env sh

# Parse results in summary files
mkdir -p summaries
python parse_results.py results/results-rmasanitizer-mpirma/results.csv --verbose > summaries/rmasanitizer_mpirma.summary
python parse_results.py results/results-rmasanitizer-shmem/results.csv --verbose >> summaries/rmasanitizer_shmem.summary
python parse_results.py results/results-rmasanitizer-gaspi/results.csv --verbose >> summaries/rmasanitizer_gaspi.summary
python parse_results.py results/results-other-tools/results.csv --verbose > summaries/othertools_mpirma.summary

# Get table with total results
echo "MPI RMA - Other tools"
python parse_results.py results/results-other-tools/results.csv --total-only

echo "RMASanitizer - MPI RMA"
python parse_results.py results/results-rmasanitizer-mpirma/results.csv --total-only
echo "RMASanitizer - SHMEM"
python parse_results.py results/results-rmasanitizer-shmem/results.csv --total-only
echo "RMASanitizer - GASPI"
python parse_results.py results/results-rmasanitizer-gaspi/results.csv --total-only