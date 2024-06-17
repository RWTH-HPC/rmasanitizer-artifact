#!/usr/bin/env sh
set -e

RESULTS_DIR=$PWD/cq-results-$(date +"%Y%m%d-%H%M%S")
echo "Results will be stored in ${RESULTS_DIR}."

mkdir -p $RESULTS_DIR

# generate results
docker build -f classification_quality/Dockerfile . -t rmaracebench
docker run --rm -u $UID:$UID -v ${RESULTS_DIR}:/rmaracebench/results -it rmaracebench /bin/bash generate_results.sh

# analyze results
docker run --rm -u $UID:$UID -v ${RESULTS_DIR}:/rmaracebench/results -it rmaracebench /bin/bash parse_results.sh

echo "Results will are stored in ${RESULTS_DIR}."