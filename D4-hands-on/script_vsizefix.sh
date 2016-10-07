#!/bin/bash

#declare -a vsize=$(seq 1000 5000 21000)


rm -f output_vsizefix1M.txt
touch output_vsizefix1M.txt

mkdir -p openmp


for num_threads in $(seq 1 1 24); do

    export OMP_NUM_THREADS=$num_threads

    gcc -DSTREAM_ARRAY_SIZE=1000000 -O3 -openmp stream.c -o stream.x


    ./stream.x | grep  Triad | cut -f 2 -d: | sed 's/$/    '$num_threads'/' >> output_vsizefix1M.txt

done