#!/bin/bash
#PBS -l nodes=1:ppn=24
#PBS -l walltime=1000

cd $PBS_O_WORKDIR

rm -f HPL.dat
mkdir hpl_data

module purge
module load openmpi
module load openblas/0.2.14/gnu/4.8.3
module load gnu

#NumNs=(57856 65536)
#NumNBs=(128 256)

NumNs=(81920)
NumNBs=(176)

export OMP_NUM_THREADS=1

for Ns in ${NumNs[@]};
do
    for NBs in ${NumNBs[@]};
    do
        FILE="xhpl.openblas $Ns $NBs"
        awk -v Ns="$Ns" '/NumNs/{gsub(/NumNs/, Ns )};{print}' HPL.dat.orig | awk  -v NBs="$NBs" '/NumNBs/{gsub(/NumNBs/, NBs )};{print}' > HPL.dat
        mpirun -np 24 /lustre/mhpc/eas/hpl/bin/xhpl.openblas | tee hpl_data/$FILE
    done
done