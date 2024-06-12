#! /bin/bash

# Part of the MUST Project, under BSD-3-Clause License
# See https://hpc.rwth-aachen.de/must/LICENSE for license information.
# SPDX-License-Identifier: BSD-3-Clause

# Shell skeleton to call actual script to generate initial OpenSHMEM specification

export FRAMEWORK_NAME=OpenSHMEM
export FRAMEWORK_SHORTNAME=shmem
export FRAMEWORK_HEADERS="shmem.h pshmem.h"
export FRAMEWORK_FUNC_PREFIX=shmem
export FRAMEWORK_FUNC_IGNORE="shmem_pcontrol shmem_complexd_prod_reduce shmem_complexf_prod_reduce shmem_complexd_sum_reduce shmem_complexf_sum_reduce shmem_complexd_prod_to_all shmem_complexf_prod_to_all shmem_complexd_sum_to_all shmem_complexf_sum_to_all"

./mk_initial_specifications.sh
