#!/usr/bin/env sh

set -e

benchmarks_mustrma=( PRK_stencil  BT-RMA  lulesh  miniMD )
benchmarks_rmasanitizer=( PRK_stencil BT-RMA lulesh miniMD PRK_stencil_shmem BT-SHMEM CFD-Proxy )
for benchmark in ${benchmarks_mustrma[*]}
do
    jube result MUST-RMA/${benchmark}/000000
done

for benchmark in ${benchmarks_rmasanitizer[*]}
do
    jube result RMASanitizer/${benchmark}/000000
done


python evaluation_results/plots/plot_performance_results.py