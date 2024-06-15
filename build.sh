#!/usr/bin/env sh

docker run --rm --shm-size=128g --ulimit memlock=32939628:32939628 -v $PWD/overhead_evaluation/jube:/jube -it rmasan /bin/bash 

#docker build -f chameleon/Dockerfile -t rmasan .


# --tag S ignorelist memusage rebuild_source tsan-opt chameleon