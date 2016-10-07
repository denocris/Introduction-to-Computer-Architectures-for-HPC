D4 hands-on
------------

Learn how to use hwloc/numactl commands
=======================================

1. Test all the commands presented in the slides and be familiar with them.
2. Compile and run the omp_101.c code and understand correctly how to change the number of threads.  
3. Modify it to make it run longer and try to assign it on different threads by means of numactl/hwloc commands.



Run stream benchmark to test different performance when wrongly assigned the processor
==========================================================================================

Download the stream benchmark (https://www.cs.virginia.edu/stream/), compile it and familiarize with it. The compile flags are :code:`-DSTREAM_ARRAY_SIZE=400000000 -O3 -xHost -mcmodel=medium -openmp`. Tested compiler is :code:`icc`.

Tasks:

1. Estimate the overall bandwidth of one node of ulysess 
2. Estimate the bandwidth of one single core of ulysess 
3. Compare the bandwith of one single core reading from memory associated to the socket against one core reading from memory associated with the other socket 
4. Do it for all threads available in one socket and make a plot of the results 
5. Summarize all the results in a short report and commit it to your github account 


Run IMPI benchmark (ping-pong) to measure latency among MPI processes assigned on different cores 
======================================================================================================

Run intel MPI ping-pong benchmark. This benchmark measures the latency and bandwidth between cores.

Task:

1. Compare the results you get running the tests for cores in the same socket, and for cores on different sockets. (Use hwloc to specifiy how the processes should be bound to cores, sockets, etc...).

 


