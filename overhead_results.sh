#!/usr/bin/env bash

set -e

benchmarks_mustrma=( PRK_stencil  BT-RMA  lulesh  miniMD )
benchmarks_rmasanitizer=( PRK_stencil BT-RMA lulesh miniMD PRK_stencil_shmem BT-SHMEM CFD-Proxy )
for benchmark in ${benchmarks_mustrma[*]}
do
    echo "== ${benchmark} =="
    jube result perf-eval-result/MUST-RMA/${benchmark}
done

for benchmark in ${benchmarks_rmasanitizer[*]}
do
    echo "== ${benchmark} =="
    jube result perf-eval-result/RMASanitizer/${benchmark}
done


#python overhead_evaluation/plots/plot_performance_results.py