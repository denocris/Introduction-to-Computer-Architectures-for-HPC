# Report of Day 4: Stream Benchmark

The analysis that follows was done using the c3e cluster. In the following plot we study the bandwidth of a node, testing it with an increasing vector (array) size for a different numebr of swich-on threads, from 1 to 21. For each series (representad by different colors) we can see that when the size of the vector exceeds the L3 cache capability (around 2.2*MB), then it begins to be stored in the RAM memory. Indeed, the triad (MB/s) considerably drops. 

When we have a lots of threads available, the bandwidth is high and decreases if we decrease the number of threads.

![Figure_1](fixthr.jpg)


In the second figure, the vector (array) size is kept fixed and we tested the bandwithd against the number of threads. The best vector size seems to be 10^6 (green dots). The blue dots, which corresponds to a smaller vector size (10^5), have a worse bandwith. This could be related to the fact the the vector is too small in size and an increase of threads could only mess up the process. If now we take the red dots we can observe that, since the size of our vector is huge (beyond the cache capability), the increasing of the threads do not visibly benefits the bandwitdh.

![Figure_2](fixvsize.jpg)

Every details about the code can be found in the folder code/.



# Report of Day 4: PingPong Benchmark

The idea is to measure the latency (for small bites) and the bandwitdh (for large bites). 

This benchmark was done between two processors on the master node of Ulysses. 
The command used was mpirun -np 2 ./IMB-MPI1 PingPong


```
PingPong

---------------------------------------------------
 Benchmarking PingPong 
 processes = 2 
---------------------------------------------------
bytes #repetitions      t[usec]   Mbytes/sec
0         1000         0.35         0.00
1         1000         0.35         2.75
2         1000         0.35         5.47
4         1000         0.35        10.79
8         1000         0.35        21.93
16        1000         0.39        38.82
32        1000         0.39        78.46
64        1000         0.52       117.27
128       1000         0.52       234.27
256       1000         0.53       462.82
512       1000         0.57       863.41
1024      1000         0.68      1425.69
2048      1000         0.89      2188.33
4096      1000         1.26      3102.44
8192      1000         1.95      4011.51
16384     1000         3.67      4262.64
32768     1000         5.62      5561.44
65536      640         9.67      6461.47
131072     320        17.27      7237.80
262144     160        31.32      7982.50
524288      80        59.98      8336.09
1048576     40       242.14      4129.88
2097152     20       539.00      3710.58
4194304     10       978.10      4089.56


All processes entering MPI_Finalize ```



This benchmark was done between two processors on different sockets on the master node . The command used was mpirun --map-by socket -np 2 ./IMB-MPI1 PingPong

```
List of Benchmarks to run:

PingPong

---------------------------------------------------
Benchmarking PingPong 
processes = 2 
---------------------------------------------------
bytes #repetitions      t[usec]   Mbytes/sec
0         1000         0.69         0.00
1         1000         0.71         1.35
2         1000         0.70         2.71
4         1000         0.71         5.40
8         1000         0.69        10.98
16        1000         0.73        20.86
32        1000         0.73        42.09
64        1000         1.15        53.17
128       1000         1.18       103.49
256       1000         1.20       204.13
512       1000         1.32       371.01
1024      1000         1.48       658.10
2048      1000         1.85      1056.35
4096      1000         2.44      1598.59
8192      1000         4.27      1831.13
16384     1000         7.24      2158.17
32768     1000        11.66      2679.31
65536      640        20.58      3036.38
131072     320        37.52      3331.26
262144     160        72.21      3462.00
524288      80       141.99      3521.44
1048576     40       312.25      3202.55
2097152     20       579.08      3453.77
4194304     10      1068.35      3744.08


All processes entering MPI_Finalize
```

This benchmark was done on a Ulysses's node.

```
List of Benchmarks to run:

PingPong

---------------------------------------------------
Benchmarking PingPong 
processes = 2 
---------------------------------------------------
bytes #repetitions      t[usec]   Mbytes/sec
0         1000         0.29         0.00
1         1000         0.30         3.17
2         1000         0.28         6.79
4         1000         0.29        13.13
8         1000         0.30        25.43
16        1000         0.33        46.66
32        1000         0.34        90.68
64        1000         0.44       139.05
128       1000         0.44       277.43
256       1000         0.43       565.90
512       1000         0.48      1023.49
1024      1000         0.57      1699.94
2048      1000         0.77      2538.19
4096      1000         1.07      3635.23
8192      1000         1.58      4956.96
16384     1000         3.05      5122.00
32768     1000         4.54      6886.38
65536      640         7.33      8532.38
131072     320        13.47      9278.66
262144     160        25.32      9873.02
524288      80        48.45     10319.68
1048576     40       115.54      8655.19
2097152     20       203.97      9805.22
4194304     10       473.50      8447.74


All processes entering MPI_Finalize
```

This benchmark was done between two processors on different sockets on a Ulysses's node.

```
List of Benchmarks to run:

PingPong

---------------------------------------------------
 Benchmarking PingPong 
 processes = 2 
---------------------------------------------------
bytes #repetitions      t[usec]   Mbytes/sec
0         1000         0.49         0.00
1         1000         0.49         1.96
2         1000         0.49         3.92
4         1000         0.47         8.13
8         1000         0.48        15.79
16        1000         0.81        18.88
32        1000         0.82        37.08
64        1000         0.84        73.05
128       1000         0.87       140.87
256       1000         0.86       283.38
512       1000         0.92       528.45
1024      1000         1.13       861.50
2048      1000         1.48      1318.74
4096      1000         2.17      1801.83
8192      1000         3.73      2094.47
16384     1000         6.02      2594.87
32768     1000         9.94      3143.70
65536      640        17.99      3474.66
131072     320        33.00      3787.69
262144     160        64.88      3853.55
524288      80       128.30      3897.10
1048576     40       256.82      3893.71
2097152     20       472.30      4234.59
4194304     10       893.60      4476.25


All processes entering MPI_Finalize
```







