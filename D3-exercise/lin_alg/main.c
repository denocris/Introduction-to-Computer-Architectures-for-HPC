#include "matrix_tools.h"
#include "vector_tools.h"
#include "mat_vect_multy.h"
#include "solver.h"
#include <assert.h>

int main()
{
  printf("-------------------------------------------------------------------------- \n");
  //printf("This code implements the Conjugate Gradient Method \n to solve the linear system A x = b and find out the vector x\n");

  // We want to solve A x = b.

  matrix_t A; // is the matrix A
  matrix_t AT; // is the vector b
  //vector_t my_vect_out;

// In this example our matrix A will be 2 x 2
  int dim = 3; // matrix row
  //int c = 3; // matrix column

// We allocate space for our objects
  allocate_m(&A,dim,dim);
  allocate_m(&AT,dim,dim);

  //allocate_v(&my_vect_out,r);
  assign_zero_m(&A);
  assign_zero_m(&AT);


// Construct the matrix

int i,j;
  for(i=0; i < A.row; i++){
    for(j=0; j< A.col; j++){

      assign_ij(i,j,A.col*i+j,&A);

    }
  }

print_m(&A);
deallocate_m(&A);
  /*assign_ij(0,0,4,&my_mat);
  assign_ij(0,1,1,&my_mat);
  assign_ij(1,0,1,&my_mat);
  assign_ij(1,1,3,&my_mat);

  printf("The matrix A is:\n");
  printf("------------------- \n");
  printf("%e   ",my_mat.data[0]);
  printf("%e\n",my_mat.data[1]);
  printf("%e   ",my_mat.data[2]);
  printf("%e\n",my_mat.data[3]);
  printf("------------------- \n");

// Construct the vector
  assign_i(0,1,&my_vect_b);
  assign_i(1,2,&my_vect_b);

  int i;
  printf("The vector b is:\n");
  for (i = 0; i < my_vect_b.size; i++)
  {
    printf("%e\n",my_vect_b.data[i]);
  }
  printf("------------------- \n");

  //multiply_mat_vect(&my_mat,&my_vect_b,&my_vect_out);

  vector_t x_sol = conj_grad_method(&my_mat,&my_vect_b);

  printf("The solution x of our system A x = b is:\n");
  for (i = 0; i < my_vect_b.size; i++)
  {
    printf("%e\n",x_sol.data[i]);
  }
  printf("------------------- \n");

  deallocate_m(&my_mat);
  deallocate_v(&my_vect_b);
  //deallocate_v(&my_vect_out);

  printf("The program is finished! Enjoy! \n");*/
}
