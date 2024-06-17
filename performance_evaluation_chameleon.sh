#!/usr/bin/env bash
set -e

RESULTS_DIR=$PWD/perf-results-$(date +"%Y%m%d-%H%M%S")

echo "Building Docker image. This may take some time..."
docker build -f overhead_evaluation/chameleon/Dockerfile -t rmasan .
echo "Build completed."

echo "Start container and run experiments..."
docker run -u $UID:$UID --rm --shm-size=128g --ulimit memlock=32939628:32939628 -v $PWD:/2024-icpp-rmasanitizer -it rmasan /bin/bash -c "cd /2024-icpp-rmasanitizer && ./overhead_submit.sh"

echo "Gather results and plot them..."
docker run -u $UID:$UID --rm --shm-size=128g --ulimit memlock=32939628:32939628 -v $PWD:/2024-icpp-rmasanitizer -it rmasan /bin/bash -c "cd /2024-icpp-rmasanitizer && ./overhead_results.sh"

# rename directory and move files
mv perf-results $RESULTS_DIR
mv performance_results.png $RESULTS_DIR
mv performance_results.pdf $RESULTS_DIR