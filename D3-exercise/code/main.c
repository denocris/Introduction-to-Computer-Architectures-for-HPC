#include "matrix_tools.h"
#include "vector_tools.h"
#include "mat_vect_multy.h"
#include "solver.h"
#include <assert.h>


void naife_transpose(){

    matrix_t A; // is the matrix A
    matrix_t AT;

    int dim = 4;

  // We allocate space for our objects
    allocate_m(&A,dim,dim);
    allocate_m(&AT,dim,dim);

    //allocate_v(&my_vect_out,r);
    assign_zero_m(&A);
    assign_zero_m(&AT);


  // Construct the matrix

    assign_increasing(&A);
    //print_m(&A);

    matrix_transpose(&A,&AT);
    print_m(&AT);

    deallocate_m(&A);
    deallocate_m(&AT);
}

void fast_transpose(){



    matrix_t A; // is the matrix A
    matrix_t AT;

    int dim = 4;

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
    int block_size=2;

    matrix_t buff;
    allocate_m(&buff,2,2);
    assign_zero_m(&buff);



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
    printf("Ciaooooooooooooooooooo\n");
    print_m(&AT);



    deallocate_m(&A);
    deallocate_m(&AT);
    deallocate_m(&buff);
}


int main(){
  printf("-------------------------------------------------------------------------- \n");

  naife_transpose();

  fast_transpose();
}
