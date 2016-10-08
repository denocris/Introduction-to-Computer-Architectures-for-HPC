#!/bin/bash

#declare -a vsize=$(seq 1000 5000 21000)


vect_size=$1


rm -f h3c_v2_$vect_size.txt
touch h3c_v2_$vect_size.txt

#mkdir -p openmp


for num_threads in $(seq 1 1 24); do

    gcc -DSTREAM_ARRAY_SIZE=$(($vect_size*100000)) -O3 -fopenmp stream.c -o stream.x

    export OMP_NUM_THREADS=$num_threads

    ./stream.x | grep  Triad | cut -f 2 -d: | sed 's/$/    '$num_threads'/' >> h3c_v2_$vect_size.txt

done

rm script_nodo.sh.*