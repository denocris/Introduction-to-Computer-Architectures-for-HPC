INFO
========================================================================

We will be benchmarks for this session on the Cosint machine. 
We will be working in groups of 4 people.

To login 
::

  ssh mhpcXX@hpc.c3e.cosint.it

where the XX stands for the number of your group, specified in the following table.

Each group will run on a dedicated node. 
To run on the computing node:
::

  qsub -I -l nodes=$NODE:ppn=24 -l walltime=8:0:0 -N $GROUP

the available resources are assigned as follows:

+---------+----------+---------+----------------------+
|  GROUP  |  NODE    |	USER   |  MEMBERS             |
+=========+==========+=========+======================+
| group1  |  b11     |  mhpc01 | lvallata, sparonuz   |
+---------+----------+---------+----------------------+
| group2  |  b12     |	mhpc02 | raversa, ndemo       | 
+---------+----------+---------+----------------------+
| group3  |  b13     |	mhpc03 | igirardi, mowais     |
+---------+----------+---------+----------------------+
| group4  |  b14     |	mhpc04 | jcarmona, aando      |
+---------+----------+---------+----------------------+
| group5  |  b15     |	mhpc05 | mbrenesn, pdicerbo   |
+---------+----------+---------+----------------------+ 
| group6  |  b17     |	mhpc06 | ansuini, plabus      |
+---------+----------+---------+----------------------+



Take a look at the various files needed to complete this lab session:
::

  ls /lustre/mhpc/eas/bin/
  ls /lustre/mhpc/eas/hpl/
  ls /lustre/mhpc/eas/hpcg/

Playing with HPL
========================================================================
::

  cd /lustre/mhpc/$USER
  cp -a /lustre/mhpc/eas/hpl/ .
  cd hpl

Take a look at "wrap.sh" and "run.sh".

In the "bin" directory several version of HPL can be found, each one compiled against a different BLAS implementation.
What "wrap.sh" does, can be actually easily done manually (load the needed modules into the environment).
Use "module avail" in order to figure out the proper modules that need to be loaded for each version.

"run.sh" will run HPL in parallel, invocking first, and killing at the end, a daemon program which takes care of recording the power consumption of the various CPUs/cores during the run of the program (mpirun ... HPL).
The daemon program collects the data and saves it into a log file named "SOMETHING.msr.log". "SOMETHING" depends on the path and the node/prefix options.
By default the path is the current directory ($PWD) and the prefix is the name of the executable wrapped (xhpl.mkl-gnu, xhpl.openblas, ...), hence, the resulting filename will be for example:
::

  /lustre/mhpc/mhpc00/hpl/xhpl.openblas.msr.log

Two input files for HPL are given as reference:

- HPL.dat.ok: best performing dataset on the given hardware (10-15 minutes);
- HPL.dat.test: smaller problem that can be used for testing runs (10 seconds).

Note that the input file MUST be named HPL.dat, and be available in the directory where HPL is run.

This file must be parsed using the "msr_filter" utility, as:
::

  /lustre/mhpc/eas/bin/msr_filter -i xhpl.openblas.msr.log


A more compact output can be obtained using:
::
  
  /lustre/mhpc/eas/bin/msr_filter -i xhpl.openblas.msr.log | /lustre/mhpc/eas/bin/msr_compact.pl

The wrapper "filter.sh" takes care of doing this automatically, for example:
::

  [mhpc00@b13 hpl]$ ls -1  *.msr.log*
  xhpl.mkl-gnu.msr.log
  xhpl.openblas.msr.log

  [mhpc00@b16 hpl]$ ./filter.sh *.msr.log
  filein=xhpl.mkl-gnu.msr.log fileout=$filein.report summary=$filein.summary
  filein=xhpl.openblas.msr.log fileout=$filein.report summary=$filein.summary

  [mhpc00@b13 hpl]$ ls -1  *.msr.log*
  xhpl.mkl-gnu.msr.log
  xhpl.mkl-gnu.msr.log.report
  xhpl.mkl-gnu.msr.log.summary
  xhpl.openblas.msr.log
  xhpl.openblas.msr.log.report
  xhpl.openblas.msr.log.summary

The data available either in the "report" or "summary" files must be later used for the plots.

Assignment
-------------------------------
Each group is expected to:

- run few tests with HPL on a single node to familiarize with the various scripts and data files;
- produce a plot reporting the performance of HPL compiled against ATLAS (xhpl.atlas) and MKL (xhpl.mkl-gnu) using the most efficient data set;
- produce a plot reporting the power consumption for the 2 implementations, at least by TOTAL, possibly discerning CORE, UNCORE and DRAM consumptions;
- produce a plot reporting the energy efficiency as GFLOPS/J ((GFLOPS/total energy) or (GFLOPS/(average power * walltime))).
- produce a plot reporting the energy efficiency as GFLOPS/W ((GFLOPS/average power) or (GFLOPS/(total energy / walltime))).

Playing with HPL and DVFS
========================================================================

Purpose of this exercise is to see the difference in energy efficiency of the best performing HPL implementation/dataset when the frequency of the processors is changed.

Look at the following scripts, you will need them later on:
::

  /lustre/mhpc/eas/bin/governor.sh
  /lustre/mhpc/eas/bin/frequency.sh

the following script can give you an idea of what can be done with the above:
::

  /lustre/mhpc/eas/bin/freq_wrap.sh

These are the commands that must be executed in order to perform this exercise:

# change governor
::

  /lustre/mhpc/eas/bin/governor.sh list
  /lustre/mhpc/eas/bin/governor.sh avail
  sudo /lustre/mhpc/eas/bin/governor.sh set userspace

# change frequency
::

  /lustre/mhpc/eas/bin/frequency.sh list
  /lustre/mhpc/eas/bin/frequency.sh avail
  sudo /lustre/mhpc/eas/bin/frequency.sh set 1900000

# do your stuff

# change frequency

# do your stuff

# reset governor
::

  sudo /lustre/mhpc/eas/bin/governor.sh set ondemand


NOTE: in order to MODIFY the frequency and governor parameters ("set" subcommand), the scripts must be invoked using sudo (run with superuser's privileges)

This is another example for altering the current governor and frequency using directly "cpufreq-set":
::

  seq 0 23 | xargs -t -i sudo cpufreq-set -r -c {} -g userspace
  cpufreq-info | egrep '^analyzing|may decide which speed to use'

  seq 0 23 | xargs -t -i sudo cpufreq-set -r -c {} -f 2.70GHz
  cpufreq-info | egrep '^analyzing|current CPU frequency'

In order to speed up the tests, use only 2.7, 2.4, 1.8, 1.2 GHz, and optionally 2.701 GHz (label used for "Turbo Boost", 2.95-3.50GHz).

Assignment
-------------------------------
Each group is expected to:

- run the best HPL implementation/dataset from the previous exercise (either atlas or mkl) for each supported frequency;
- produce a plot reporting the performance of the benchmark run at each frequency;
- produce a plot reporting the power consumption at each frequency;
- produce a plot reporting the energy efficiency at each frequency (both GLOFPS/W and GFLOPS/J).


Playing with HPCG and DVFS
========================================================================
::

  cd /lustre/mhpc/$USER
  cp -a /lustre/mhpc/eas/hpcg/ .
  cd hpcg

Wrapper scripts can be adapted from the previous exercises.

In this exercise the students are supposed to repeat the previous exercise, using the HPCG benchmark instead of HPL.

Assignment
-------------------------------
Each group is expected to:

- run HPCG for each supported frequency;
- produce a plot reporting the performance of the benchmark run at each frequency;
- produce a plot reporting the power consumption at each frequency;
- produce a plot reporting the energy efficiency at each frequency (both GLOFPS/W and GFLOPS/J).

