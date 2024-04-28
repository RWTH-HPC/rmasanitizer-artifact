#!/usr/bin/env sh

set -e

benchmarks_mustrma=( PRK_stencil  BT-RMA  lulesh  miniMD )
benchmarks_rmasanitizer=( PRK_stencil BT-RMA lulesh miniMD PRK_stencil_shmem BT-SHMEM CFD-Proxy )
for benchmark in ${benchmarks_mustrma[*]}
do
    jube run overhead_evaluation/jube/${benchmark}/${benchmark}.xml -o MUST-RMA/${benchmark} --tag M ignorelist pnmpi memusage rebuild_source must-rma
done

for benchmark in ${benchmarks_rmasanitizer[*]}
do
    jube run overhead_evaluation/jube/${benchmark}/${benchmark}.xml -o RMASanitizer/${benchmark} --tag M ignorelist pnmpi memusage rebuild_source tsan-opt
done
