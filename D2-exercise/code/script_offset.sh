#!/bin/bash
#PBS -l nodes=1:ppn=24
#PBS -l walltime=00:15:00

#module load gnu
#cd $PBS_O_WORKDIR

rm -rf data/*
mkdir -p data

LOOP_SIZE=1000
MIN_VECTOR_SIZE=100
MAX_VECTOR_SIZE=1000000

#LOOP_SIZE=100
#MIN_VECTOR_SIZE=1000
#MAX_VECTOR_SIZE=10000


for (( offset = -1; offset < 2; offset++ ));
do
    for (( i = $MIN_VECTOR_SIZE; i <= $MAX_VECTOR_SIZE ; i=i+i/5 ));
    do
        VECTOR_SIZE=$i
        gcc ex01.c -D LOOP_SIZE=$LOOP_SIZE -D VECTOR_SIZE=$VECTOR_SIZE -D offset=$offset -O2 -o ex01
        MFLOPSCOMPILETIME=$(./ex01)

        gcc ex01.c -D LOOP_SIZE=$LOOP_SIZE -D VECTOR_SIZE=$VECTOR_SIZE -D offset="atoi(argv[1])" -O2 -o ex01
        MFLOPSRUNTIME=$(./ex01 $offset)

            (echo $offset $LOOP_SIZE $VECTOR_SIZE $MFLOPSCOMPILETIME $MFLOPSRUNTIME) | tee -a data/data_offset$offset.dat
    done
done
