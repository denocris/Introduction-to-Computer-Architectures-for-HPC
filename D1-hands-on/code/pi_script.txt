#!/bin/bash

for p in (1,2,4,8,16,24); do

echo mpirun -np $p time parallel_pi 10000 >> time_strong.txt


done

