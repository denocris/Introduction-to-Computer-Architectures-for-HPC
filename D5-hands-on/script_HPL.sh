#!/bin/bash
#PBS -l nodes=1:ppn=24
#PBS -l walltime=00:10:00

cd $PBS_O_WORKDIR

rm -f HPL.dat
mkdir hpl_data

module load openmpi
module load openblas/0.2.14/gnu/4.8.3
module load gnu

Nmatrix=(57856 65536)
Nblock=(128 256)


export OMP_NUM_THREADS=1

for N in ${Nmatrix[@]};
do
    for Nblock in ${Nblock};
    do
    FILE="xhpl.openblas $Ns $NBs"
    awk -v Ns="$Ns" '/NumNs/{gsub(/NumNs/, Ns )};{print}' HPL.dat.orig | awk  -v NBs="$NBs" '/NumNBs/{gsub(/NumNBs/, NBs )};{print}' > HPL.dat
    mpirun -np 24 /lustre/mhpc/eas/hpl/bin/xhpl.openblas | tee results/$FILE

    done
done