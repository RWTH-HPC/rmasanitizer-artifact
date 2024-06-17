#!/usr/bin/env bash

obj_dir=$HOME/obj_mount

mkdir -p ${obj_dir}

if mountpoint -q "${obj_dir}" ; then
    echo "$HOME/obj_mount is already mounted"
else
    cc-cloudfuse mount ${obj_dir}
fi

perf_result=$(find . -maxdepth 1 -print | grep -m1 'perf-results-')
echo ${perf_result}

if [ -d "${perf_result}" ]; then
    # Copy *.dat files and result PNG
    rsync -zrv -O --prune-empty-dirs --include '*/' --include '*.dat' --include '*.png' --exclude '*' "${perf_result}" "${obj_dir}"
else
    echo "Could not find any overhead analysis results to copy."
fi

cq_result=$(find . -maxdepth 1 -print | grep -m1 'cq-results-')

if [ -d "${cq_result}" ]; then
    # Copy *.summary files
    rsync -zrv --prune-empty-dirs --include '*/' --include '*.summary' --exclude '*' "${cq_result}" "${obj_dir}"
else
    echo "Could not find any classification quality results to copy."
fi
