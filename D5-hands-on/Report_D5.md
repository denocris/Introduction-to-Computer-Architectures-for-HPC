# Report of Day 4: Stream Benchmark

The analysis that follows was done using the c3e cluster. In the following plot we study the bandwidth of a node, testing it with an increasing vector (array) size for a different numebr of swich-on threads, from 1 to 21. For each series (representad by different colors) we can see that when the size of the vector exceeds the L3 cache capability (around 2.2*MB), then it begins to be stored in the RAM memory. Indeed, the triad (MB/s) considerably drops. 

When we have a lots of threads available, the bandwidth is high and decreases if we decrease the number of threads.

![Figure_1](fixthr.jpg)


In the second figure, the vector (array) size is kept fixed and we tested the bandwithd against the number of threads. The best vector size seems to be 10^6 (green dots). The blue dots, which corresponds to a smaller vector size (10^5), have a worse bandwith. This could be related to the fact the the vector is too small in size and an increase of threads could only mess up the process. If now we take the red dots we can observe that, since the size of our vector is huge (beyond the cache capability), the increasing of the threads do not visibly benefits the bandwitdh.

![Figure_2](fixvsize.jpg)

Every details about the code can be found in the folder code/.

