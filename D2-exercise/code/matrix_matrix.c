#include <stdio.h>
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

int main()
{
  // matrices
  double *A;
  double *B;
  double *C; // C = A*B

  // needed for loops
  unsigned int i, j, k;

  // memory allocations
  unsigned int N=1024; // matrix dimension
  size_t size = (N*N)*sizeof(double);
  
  A = (double *) malloc(size);
  B = (double *) malloc(size);
  C = (double *) malloc(size);

  // initialize the entries of the matrices

  for (i=0; i<N*N; ++i)
    {
      A[i] = (double)i;
      B[i] = (double)i;
      C[i] = 0.0;
    }

  // unefficient matrix matrix multiplication
  double t0 = seconds();  

  for (i=0; i<N; ++i)
    for (j=0; j<N; ++j)
      for (k=0; k<N; ++k)
	C[i*N + j] += A[i*N + k]*B[k*N + j];

  double t1 = seconds();

  fprintf(stdout, "Elapsed time: %6.5f\n", t1-t0);
  fprintf(stdout, "C(3,5)  : %6.5f\n", C[3*N+5]);
  fprintf(stdout, "C(120,9): %6.5f\n", C[120*N+9]);
  fprintf(stdout, "C(34,77): %6.5f\n", C[34*N+77]);

  free(A);
  free(B);
  free(C);
	
  return 0;

}
