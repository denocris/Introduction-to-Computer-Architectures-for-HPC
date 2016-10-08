# Report of Day 4: Stream Benchmark

The analysis that follows was done using the c3e cluster. In the following plot we study the bandwidth of a node, testing it with an increasing vector (array) size for a different numebr of swich-on threads, from 1 to 21. For each series (representad by different colors) we can see that when the size of the vector exceeds the L3 cache capability (around 2.2*MB), then it begins to be stored in the RAM memory. Indeed, the triad (MB/s) considerably drops. 

When we have a lots of threads available, the bandwidth is high and decreases if we decrease the number of threads.

![Figure_1](fixthr.jpg)




![Figure_2](fixvsize.jpg)

