#!/bin/bash
#PBS -l nodes=1:ppn=24
#PBS -l walltime=0:05:00

module load gnu
cd $PBS_O_WORKDIR

min=10000
max=1000000
stride=10000

# min=10
# max=100
# stride=10

OPTFLAG=-O1
gcc ex02.c $OPTFLAG -o ex02

for (( i = 0; i < 100; i++ )); do
    (
    for (( dim = $min; dim <= $max; dim+=$stride )); do
        times="$(./ex02 $dim)"
        echo $dim $times
    done
    ) > results$OPTFLAG/$i
    echo $i
done
