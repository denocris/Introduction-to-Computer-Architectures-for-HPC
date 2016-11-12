#!/bin/bash
#PBS -l nodes=1:ppn=24
#PBS -l walltime=00:30:00

cd $PBS_O_WORKDIR

rm -f HPL.dat
mkdir hpl_data

module load openmpi
module load openblas/0.2.14/gnu/4.8.3
module load gnu

#Nmatrix=(57856 65536)
#Nblock=(128 256)

Nmatrix=(1024 4096)
Nblock=(32 128)


export OMP_NUM_THREADS=1

for N in ${Nmatrix[@]};
do
    for Nbls in ${Nblock};
    do
    FILE="xhpl.openblas $N $Nbls"
    awk -v N="$N" '/Nmatrix/{gsub(/Nmatrix/, N )};{print}' HPL.dat.orig | awk  -v Nbls="$Nbls" '/Nblock/{gsub(/Nblock/, Nbls )};{print}' > HPL.dat
    mpirun -np 24 /lustre/mhpc/eas/hpl/bin/xhpl.openblas | tee hpl_data/$FILE

    done
done