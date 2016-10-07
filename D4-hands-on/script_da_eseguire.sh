#!/bin/bash

#declare -a vsize=$(seq 1000 5000 21000)


rm -f output_openmp16Th.txt
touch output_openmp16Th.txt

#mkdir -p openmp


export OMP_NUM_THREADS=16

for vect_size in $(seq 10000 50000 6000000); do

    gcc -DSTREAM_ARRAY_SIZE=$vect_size -O3 -openmp stream.c -o stream.x

    ./stream.x | grep  Triad | cut -f 2 -d: | sed 's/$/    '$vect_size'/' >> output_openmp16Th.txt

done