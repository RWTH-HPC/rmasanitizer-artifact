#!/usr/bin/env bash

docker build -f overhead_evaluation/chameleon/Dockerfile.bootstrap -t chameleon_start

echo "===="
echo "This script expects that application credentials have been created in the ChameleonCLoud infrastructure CHI@TACC."
echo "See: https://chameleoncloud.readthedocs.io/en/latest/technical/cli.html#creating-an-application-credential"
echo "Please create the application credentials (unrestricted) and source the openrc file in the container."
echo ""
echo "Then, run /workingdir/reserve_chameleon_node.sh to allocate a node."
echo "===="

docker run -v $PWD:/workingdir -it chameleon_start /bin/bash