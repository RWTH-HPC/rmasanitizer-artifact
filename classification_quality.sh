#!/usr/bin/env sh

set -e

docker build . -t rmaracebench
docker run -it rmaracebench
docker run -v $(pwd)/result-rmasanitizer:/result -it rmaracebench python run_test.py tools --rma-model MPIRMA --output-folder /result --tool 'RMASanitizer' 