#!/bin/bash

#declare -a vsize=$(seq 1000 5000 21000)


rm -f output_openmp10Thr.txt
touch output_openmp10Thr.txt

#mkdir -p openmp



for vect_size in $(seq 10000 50000 6000000); do

    gcc -DSTREAM_ARRAY_SIZE=$vect_size -O3 -openmp stream.c -o stream.x

    export OMP_NUM_THREADS=10

    ./stream.x | grep  Triad | cut -f 2 -d: | sed 's/$/    '$vect_size'/' >> output_openmp10Thr.txt

done