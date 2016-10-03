#!/bin/bash

echo "-------------------------------------"

moves=10000000

/usr/bin/time ./serial_pi $moves >> time_serial.txt 2>&1

for p in {1,2,4,8,16,24}; do

echo $p

/usr/bin/time mpirun -np $p parallel_pi $moves >> time_weak.txt 2>&1

done

echo "-------------------------------------"

