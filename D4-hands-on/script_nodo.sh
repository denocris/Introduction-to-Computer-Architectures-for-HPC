#!/bin/bash

#PBS -l nodes=1:ppn=24
#PBS -l walltime=00:30:00


#(module loaded in ./bashrc)

module load openmpi/1.8.8/gnu/4.8.3


cd $PBS_O_WORKDIR

./script_da_eseguire.sh
#./script_vsizefix.sh