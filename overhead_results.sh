#!/usr/bin/env sh

set -e

benchmarks_mustrma=( PRK_stencil  BT-RMA  lulesh  miniMD )
benchmarks_rmasanitizer=( PRK_stencil BT-RMA lulesh miniMD PRK_stencil_shmem BT-SHMEM CFD-Proxy )
for benchmark in ${benchmarks_mustrma[*]}
do
    jube result evaluation/MUST-RMA/${benchmark}
done

for benchmark in ${benchmarks_rmasanitizer[*]}
do
    jube result evaluation/RMASanitizer/${benchmark}
done


python evaluation/plots/plot_performance_results.py