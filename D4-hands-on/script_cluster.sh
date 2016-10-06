#!/bin/bash

#declare -a vsize=$(seq 1000 5000 21000)

PBS -l nodes=1:ppn=24
PBS -l walltime=01:00:00

#cd /P1.2_seed/D4-hands-on

rm output.txt
touch output.txt



for vect_size in $(seq 5000 10000 30000); do

    gcc -DSTREAM_ARRAY_SIZE=$vect_size -O3 -openmp stream.c -o stream.x

    ./stream.x | grep  Triad | cut -f 2 -d: | sed 's/$/    '$vect_size'/' >> output.txt

done