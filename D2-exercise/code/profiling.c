#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

double seconds(void)
{
  struct timeval tmp;
    
  gettimeofday(&tmp, (struct timezone *)0);
  return tmp.tv_sec + ((double)tmp.tv_usec)/10e6;
}

void square (double * vec,
	     size_t dim)
{
  unsigned int i;
  for (i=0; i<dim; ++i)
    (double)i*i;
}


void root (double * vec,
	   size_t dim)
{
  unsigned int i;

  for (i=0; i<dim; ++i)
    sqrt((double)i);
}

void sum (double * vec,
	  size_t dim)
{
  unsigned int i;
  for (i=0; i<dim; ++i)
    (double)i + i;
}

int main()
{
  // array
  double *a;

  // memory allocations
  unsigned int N=50000000; // vector dimension
  
  a = (double *) malloc( N*sizeof(double) );

  // initialization
  /* unsigned int i; */
  /* for (i=0; i<N; ++i) */
  /*   a[i] = (double)i; */

  double t0 = seconds();

   square(a,N);

  //  root(a,N);
   //    sum(a, N);
  double t1 = seconds();


  fprintf(stdout, "Elapsed time: %6.5f\n", t1-t0);

  free(a);
	
  return 0;

}
