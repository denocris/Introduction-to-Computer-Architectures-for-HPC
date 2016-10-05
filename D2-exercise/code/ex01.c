/*
 * Copyright (C) 2001-2013 The Abdus Salam, International Centre of Theoretical Physics (ICTP)
 *
 * This file is distributed under the terms of the GNU General Public License.
 * See http://www.gnu.org/copyleft/gpl.txt
 *
 * The code was developed for the hands-on session of M1.2 - HPC Master SISSA/ICTP
 * The example is extracted from:
 * "Introduction to High Performance Computing for Scientists and Engineers",
 * by Georg Hager and Gerhard Wellein
 *
 * Author: Ivan Girotto
 * Last update: Sept-2015
 *
 */

#include <stdlib.h>
#include <stdio.h>

#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>


//#define LOOP_SIZE 10
#define VECTOR_SIZE 10000000

double seconds(){

/* Return the second elapsed since Epoch (00:00:00 UTC, January 1, 1970) */
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
  return sec;
}

void dummy(double * temp){
  (* temp) = 4.0;
}


// The funcion compute(...) return the elapsed time needed to complete
// the vetor upgrade. The number of operation are stored into the
// variable n_op
double compute( double * vector, double scalar, size_t size, int offset, size_t * n_op ){

  double elaps_time1;
  elaps_time1 = seconds();
  int count, i;

  for( count = 0; count < size; count++ ){
    for( i = 0; i < VECTOR_SIZE; i++){

    vector[i] = scalar * vector[i + offset];
  }

    // leave this dummy check to avoid compiler optimization between the two loops
    //if( vector[VECTOR_SIZE/2] < 0 ) dummy(&vector[VECTOR_SIZE/2]);
    if( vector[size/2] < 0 ) dummy(&vector[size/2]);
}

// compute the number of operations performed
  *n_op = VECTOR_SIZE*size;



  double elaps_time2;
  elaps_time2 = seconds();

  double elaps_time;
  elaps_time = elaps_time2 - elaps_time1;

  return elaps_time;

}

int main(int argc, char * argv[]){


  size_t size = atoi(argv[1]);
  size_t n_op=0;

  double *v;
  double scalar=2;

  v = (double *)malloc(VECTOR_SIZE*sizeof(double));
  //double v[size]

  double time_p1;
  time_p1 = compute(v,scalar,size,1,&n_op);
  double nFLOPS_p1=(double)n_op/(double)time_p1;

  double time_0;
  time_0 = compute(v,scalar,size,0,&n_op);
  double nFLOPS_0=(double)n_op/(double)time_0;

  double time_m1;
  time_m1 = compute(v,scalar,size,-1,&n_op);
  double nFLOPS_m1=(double)n_op/(double)time_m1;

  printf("%e    %e    %e    %zu\n",nFLOPS_p1,nFLOPS_0,nFLOPS_m1,n_op);

  free(v);

}
