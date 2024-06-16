#!/usr/bin/env sh
set -e

echo "Building Docker image. This may take some time..."
docker build -f chameleon/Dockerfile -t rmasan .

# echo "Build completed, start container..."
# echo "Run experiments..."
# docker run --rm --shm-size=128g --ulimit memlock=32939628:32939628 -v $PWD:/2024-icpp-rmasanitizer -it rmasan /bin/bash -c "cd /2024-icpp-rmasanitizer && ./overhead_submit.sh"

echo "Gather results and plot them..."
docker run --rm --shm-size=128g --ulimit memlock=32939628:32939628 -v $PWD:/2024-icpp-rmasanitizer -it rmasan /bin/bash -c "cd /2024-icpp-rmasanitizer && ./overhead_results.sh"

# echo "Plot results..."
# docker run --rm -v $PWD:/2024-icpp-rmasanitizer -it rmasan /bin/bash -c "cd /2024-icpp-rmasanitizer && python overhead_evaluation/plots/plot_performance_results.py perf-eval-result --usetex"

# --tag S ignorelist memusage rebuild_source tsan-opt chameleon