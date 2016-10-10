# Report: weak and strong scalability

We have seen the weak and strong scalability. We tested a simple mote-carlo code to compute pi, both in a serial manner and a parallel one. The task was to establish when is worthwhile to parallelize a code. I wrote two bash script to implement the weak and strong approach and extract the elapse time of the execution. These are:

- pi_scrip_w.txt
- pi_scrip_s.txt

In the first figure we can see weak and strong scalability.

![Figure 1](weak_strong.jpg)


In the following plot it is shown the speedup. We can appreciate that if our code has few moves (10^6 − 10^7 ) then is not convenient to parallelize it. Otherwise, if the code has a great number of moves (say ≥ 10^8) then it is worthwhile to parallelize it.

![Figure 2](speedup.jpg)

In this third plot the efficiency (speedup/processors) is represented against the number of processors. The different lines are related to different number of moves in our computation. 

![Figure 3](eff.jpg)

Every details about the code can be found in the folder code/.