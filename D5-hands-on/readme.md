Run HPL benchmark using MKL multithread library
===========================================================


steps: 

- Get the HPL package from netlib::  wget http://www.netlib.org/benchmark/hpl/hpl-2.1.tar.gz 

- Compile the package against MKL library

- check input file 

- check output file 

- run on different numbers of core increasing size 

- try to plot scalability and see if scalability is fine.. 

- try to identify the best combination (N and Nb ) in term of performance
