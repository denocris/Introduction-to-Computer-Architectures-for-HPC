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

#define LOOP_SIZE 100
#define VECTOR_SIZE 1000000

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
double compute( double * vector,
		double scalar,
		size_t size,
		int offset,
		size_t * n_op ){

  int count, i;

  for( count = 0; count < LOOP_SIZE; count++ ){
      
    // add the loop over the vector elements to compute A(i) = scalar * A(i+offset)

    // leave this dummy check to avoid compiler optimization between the two loops
    if( vector[VECTOR_SIZE/2] < 0 ) dummy(&vector[VECTOR_SIZE/2]);
    
  }
  
  // compute the number of operations performed

  return /*the elapsed time */;

}

int main(int argc, char * argv[]){

  // allocate and initialize the vector 
     
  // Call the function compute(..) and print the value of the number of operation executed per second 
  // Repeat such task for offset 0, 1, -1

  return 0;

}
