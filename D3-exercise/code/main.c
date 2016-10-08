#include "matrix_tools.h"


#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

double seconds(){

/* Return the second elapsed since Epoch (00:00:00 UTC, January 1, 1970) */
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
  return sec;
}


void slow_transpose(double *A, double *AT, size_t dim){

    int i,j;
    double elaps_t_i;
    double elaps_t_f;
    double elaps_time;

    elaps_t_i = seconds();

    for(i=0; i < dim; i++)
      for(j=0; j < dim; j++)
        AT[i*dim + j]=A[j*dim + i];

    elaps_t_f = seconds();

    elaps_time = elaps_t_f - elaps_t_i;
    printf("%e\n",elaps_time);

    //print_m(&AT);

}


void fast_transpose(double *A, double *AT,size_t dim,size_t block_size){



    size_t i,j;
    size_t bi,bj;


    //assign_increasing(&A);



    double elaps_t_i;
    double elaps_t_f;
    double elaps_time;

    elaps_t_i = seconds();

    for(i=0; i < dim; i+=block_size)
      for(j=0; j < dim; j+=block_size)
        for(bi = i; bi < i+block_size; ++bi)
         for(bj = j; bj < j+block_size; ++bj){
           AT[bi + bj*dim] = A[bi*dim + bj];
          }

    elaps_t_f = seconds();

    //print_m(&AT);

    elaps_time = elaps_t_f - elaps_t_i;
    printf("%e\n",elaps_time);
}



int main(){

  double *A;
  double *AT;
  size_t dim, block_size;
  int i;

  dim = 16384;
  block_size = 256;

  A = (double*)malloc(dim*dim*sizeof(double));
  AT = (double*)malloc(dim*dim*sizeof(double));

  for(i = 0; i < dim*dim; i++)
    A[i]=i*2.;




  //printf_m(&A);

  slow_transpose(A,AT,dim);

  //printf("A[3,2]=%f, AT[2,3]=%f\n",A[3*dim +2],AT[2*dim + 3]);

  fast_transpose(A,AT,dim,block_size);

  //printf("A[3,2]=%f, AT[2,3]=%f\n",A[3*dim +2],AT[2*dim + 3]);




}
