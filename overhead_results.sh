#!/usr/bin/env bash

set -e

result_path=perf-results

benchmarks_mustrma=(PRK_stencil  BT-RMA  lulesh  miniMD)
benchmarks_rmasanitizer=(PRK_stencil BT-RMA lulesh miniMD PRK_stencil_shmem BT-SHMEM CFD-Proxy)
for benchmark in ${benchmarks_mustrma[*]}
do
    echo "== ${benchmark} (MUST-RMA) =="
    jube analyse ${result_path}/MUST-RMA/${benchmark}
    jube result ${result_path}/MUST-RMA/${benchmark}
done

for benchmark in ${benchmarks_rmasanitizer[*]}
do
    echo "== ${benchmark} (RMASanitizer) =="
    jube analyse ${result_path}/RMASanitizer/${benchmark}
    jube result ${result_path}/RMASanitizer/${benchmark}
done

echo "Plotting results for small dataset..."
python overhead_evaluation/plots/plot_performance_results.py perf-eval-result --usetex --small-dataset