#!/bin/bash

#declare -a vsize=$(seq 1000 5000 21000)


num_thrs=20

rm -f h3c_T$num_thrs.txt
touch h3c_T$num_thrs.txt

#mkdir -p openmp


export OMP_NUM_THREADS=$num_thrs

for vect_size in $(seq 10000 50000 4000000); do

    gcc -DSTREAM_ARRAY_SIZE=$vect_size -O3 -openmp stream.c -o stream.x

    ./stream.x | grep  Triad | cut -f 2 -d: | sed 's/$/    '$vect_size'/' >> h3c_T$num_thrs.txt

done