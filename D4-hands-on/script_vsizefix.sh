#!/bin/bash

#declare -a vsize=$(seq 1000 5000 21000)


rm -f output_vsizefix1K.txt
touch output_vsizefix1K.txt

#mkdir -p openmp


for num_threads in $(seq 1 1 24); do

    gcc -DSTREAM_ARRAY_SIZE=100000 -O3 -openmp stream.c -o stream.x

    export OMP_NUM_THREADS=$num_threads

    ./stream.x | grep  Triad | cut -f 2 -d: | sed 's/$/    '$num_threads'/' >> output_vsizefix1K.txt

done