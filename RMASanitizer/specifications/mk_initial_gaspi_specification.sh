#! /bin/bash

# Part of the MUST Project, under BSD-3-Clause License
# See https://hpc.rwth-aachen.de/must/LICENSE for license information.
# SPDX-License-Identifier: BSD-3-Clause

# Shell skeleton to call actual script to generate initial GASPI specification

export FRAMEWORK_NAME=GASPI
export FRAMEWORK_SHORTNAME=gaspi
export FRAMEWORK_HEADERS="GASPI.h PGASPI.h"
export FRAMEWORK_FUNC_PREFIX=gaspi
export FRAMEWORK_FUNC_IGNORE="gaspi_passive_transfer_size_min gaspi_atomic_max gaspi_build_infrastructure gaspi_print_error"

./mk_initial_specifications.sh
