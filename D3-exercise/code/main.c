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


void naife_transpose(int dim){

    matrix_t A; // is the matrix A
    matrix_t AT;

    //int dim = 4;

  // We allocate space for our objects
    allocate_m(&A,dim,dim);
    allocate_m(&AT,dim,dim);

    //allocate_v(&my_vect_out,r);
    assign_zero_m(&A);
    assign_zero_m(&AT);


  // Construct the matrix

    assign_increasing(&A);
    //print_m(&A);

    double elaps_t_i;
    double elaps_t_f;
    double elaps_time;

    elaps_t_i = seconds();
    matrix_transpose(&A,&AT);
    elaps_t_f = seconds();

    elaps_time = elaps_t_f - elaps_t_i;
    printf("%e\n",elaps_time);

    //print_m(&AT);

    deallocate_m(&A);
    deallocate_m(&AT);
}

void fast_transpose(int dim, int block_size){



    matrix_t A; // is the matrix A
    matrix_t AT;

    //int dim = 4;

  // We allocate space for our objects
    allocate_m(&A,dim,dim);
    allocate_m(&AT,dim,dim);

    //allocate_v(&my_vect_out,r);
    assign_zero_m(&A);
    assign_zero_m(&AT);


  // Construct the matrix

    assign_increasing(&A);
    //print_m(&A);

    int num_bloks=2;
    int l,m;
    //int block_size=2;

    matrix_t buff;
    allocate_m(&buff,2,2);
    assign_zero_m(&buff);

    double elaps_t_i;
    double elaps_t_f;
    double elaps_time;

    elaps_t_i = seconds();

    for(l=0; l < num_bloks; l++){
      for(m=0; m < num_bloks; m++){

        int i,j;
        for(i=0; i < block_size; i++){
          for(j=0; j < block_size; j++){
            double entry;
            entry = get_ij(l*block_size +i,m*block_size+j,&A);
            assign_ij(i,j,entry,&buff);
          }
        }

        for(i=0; i < block_size; i++){
          for(j=0; j < block_size; j++){
            double entry;
            entry = get_ij(i,j,&buff);
            //printf("_________________________ OK2");
            assign_ij(m*block_size+j,l*block_size +i,entry,&AT);

          }
        }


    }
}

    elaps_t_f = seconds();

    //print_m(&AT);

    elaps_time = elaps_t_f - elaps_t_i;
    printf("%e\n",elaps_time);



    deallocate_m(&A);
    deallocate_m(&AT);
    deallocate_m(&buff);
}


int main(){
  //printf("-------------------------------------------------------------------------- \n");

  naife_transpose();

  fast_transpose();
}
