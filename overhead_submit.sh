#!/usr/bin/env bash

set -e

result_path=perf-eval-result
benchmark_size=S

if [ -d "${result_path}" ]; then
    echo "The path '${result_path}' already exists. Please delete the directory or choose another path."
    exit 1
fi

benchmarks_mustrma=(PRK_stencil  BT-RMA  lulesh  miniMD)
benchmarks_rmasanitizer=(PRK_stencil BT-RMA lulesh miniMD PRK_stencil_shmem BT-SHMEM CFD-Proxy)
echo "Running MUST-RMA benchmarks..."
for benchmark in ${benchmarks_mustrma[*]}
do
    jube run overhead_evaluation/jube/benchmarks/${benchmark}/${benchmark}.xml -o ${result_path}/MUST-RMA/${benchmark} --tag ${benchmark_size} ignorelist memusage rebuild_source must-rma chameleon
done

echo "Running RMASanitizer benchmarks..."
for benchmark in ${benchmarks_rmasanitizer[*]}
do
    jube run overhead_evaluation/jube/benchmarks/${benchmark}/${benchmark}.xml -o ${result_path}/RMASanitizer/${benchmark} --tag ${benchmark_size} ignorelist memusage rebuild_source tsan-opt chameleon
done
