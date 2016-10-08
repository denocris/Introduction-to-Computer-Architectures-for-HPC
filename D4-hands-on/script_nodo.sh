#!/bin/bash

#PBS -l nodes=1:ppn=24
#PBS -l walltime=00:30:00


#(module loaded in ./bashrc)

module load openmpi/1.8.8/gnu/4.8.3


cd $PBS_O_WORKDIR

#./script_da_eseguire.sh 6
#./script_da_eseguire.sh 11
#./script_da_eseguire.sh 16
#./script_da_eseguire.sh 21

./script_vsizefix.sh 40
./script_vsizefix.sh 50
./script_vsizefix.sh 60
./script_vsizefix.sh 100
./script_vsizefix.sh 150
./script_vsizefix.sh 500
./script_vsizefix.sh 1000

