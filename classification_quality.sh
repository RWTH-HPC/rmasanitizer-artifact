#!/usr/bin/env sh

set -e

#docker build -f classification_quality/Dockerfile . -t rmaracebench
docker run --name eval -it rmaracebench /bin/bash generate_results.sh
docker cp eval:/rmaracebench/results .
docker stop eval
docker rm eval