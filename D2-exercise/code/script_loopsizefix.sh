#!/bin/bash

echo "-------------------------------------"

declare -i vect_size=1000

for i in $(seq 1 100); do

echo $vect_size

./ex01_l.x $vect_size >> data_ls100.txt
vect_size=$vect_size*2
done

echo "-------------------------------------"