# Report: Pipeline and Offsets

Every details about the code can be found in the folder code/.

- ex01.c
- script_vectsizefix.sh

The program allocates a vector of 100K elements and performs the operation

A[i] = s*A[i + offset],

where the offset can be +1, 0, -1. The idea is to compute the number of operations per second that the processor is able to perform in each of the three cases.In the first two cases, when the offset = +1, 0, the pipeline is working well, while when the offset is −1 the pipeline is not anymore performed and therefore the number of operations per second drop about 20%. This can be clearly seen in the following figure.

![Fifure 1](pipeline.jpg)

