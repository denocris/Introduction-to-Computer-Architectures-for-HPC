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
./script_vsizefix.sh 1
./script_vsizefix.sh 3
./script_vsizefix.sh 5
./script_vsizefix.sh 7
./script_vsizefix.sh 10
./script_vsizefix.sh 13
./script_vsizefix.sh 15
./script_vsizefix.sh 17
./script_vsizefix.sh 20
./script_vsizefix.sh 25
./script_vsizefix.sh 30
