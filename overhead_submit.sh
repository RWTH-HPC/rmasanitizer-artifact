#!/usr/bin/env bash

set -e

benchmarks_mustrma=(PRK_stencil  BT-RMA  lulesh  miniMD)
benchmarks_rmasanitizer=(PRK_stencil BT-RMA lulesh miniMD PRK_stencil_shmem BT-SHMEM CFD-Proxy)
for benchmark in ${benchmarks_mustrma[*]}
do
    jube run overhead_evaluation/jube/benchmarks/${benchmark}/${benchmark}.xml -o perf-eval-result/MUST-RMA/${benchmark} --tag S ignorelist memusage rebuild_source must-rma chameleon
done

for benchmark in ${benchmarks_rmasanitizer[*]}
do
    jube run overhead_evaluation/jube/benchmarks/${benchmark}/${benchmark}.xml -o perf-eval-result/RMASanitizer/${benchmark} --tag S ignorelist memusage rebuild_source tsan-opt chameleon
done
