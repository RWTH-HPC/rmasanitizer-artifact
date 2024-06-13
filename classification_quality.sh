#!/usr/bin/env sh
set -e

# generate results
docker build -f classification_quality/Dockerfile . -t rmaracebench
docker run --name eval -it rmaracebench /bin/bash generate_results.sh
docker cp eval:/rmaracebench/results .
docker stop eval && docker rm eval

# analyze results
docker run --name parse -v $PWD/results:/rmaracebench/results -it rmaracebench /bin/bash /rmaracebench/parse_results.sh
docker cp parse:/rmaracebench/summaries results
docker stop eval && docker rm eval