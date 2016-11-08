#!/bin/bash

echo "-------------------------------------"



#for loop_size in $(seq 100 100 10000); do # for 100K
#for loop_size in $(seq 10 10 1000); do # for 1000K
for loop_size in $(seq 1 1 100); do # for 10000K


./ex01.x $loop_size >> data_vs10M.txt

done

echo "-------------------------------------"