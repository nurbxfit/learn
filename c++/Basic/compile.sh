#!/usr/bin/bash

# while getopts f:o: flag
# do
#     case "${flag}" in
#         f) filein=${OPTARG};;
#         o) fileout=${OPTARG};;
#     esac
# done
FILEIN=$1
FILEOUT="${FILEIN%%.*}"
# echo "filein: ${FILEIN}"
# echo "fileout: ${FILEOUT}" 

g++ ${FILEIN} -o "./bin/${FILEOUT}.bin";
echo "binary in ./bin folder" && ls -l ./bin

