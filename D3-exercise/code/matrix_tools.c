#include "matrix_tools.h"

void allocate_m(matrix_t *mat, unsigned int m, unsigned int n)
{
  mat->row=m;
  mat->col=n;

  mat->data = (double *)malloc(n*m*sizeof(double));
}


void assign_zero_m(matrix_t *mat)
{
  int i;
  //int j;

  for (i = 0; i < (mat->row*mat->col); i++)
      {
        mat->data[i]=0;
        //printf("M[%e]\n", mat->data[i]);
      }
}


void assign_ij(const unsigned int i, const unsigned int j,
               const double elem, matrix_t *mat)
{
  mat -> data[i*mat->col + j]= elem;
  //printf("M[%d,%d] = %e\n",i,j,elem);
}

double get_ij(const unsigned int i, const unsigned int j, matrix_t *mat)
{
  return mat -> data[i*mat->col + j];

}

void print_m(matrix_t *mat)
{

int i,j;
  for(i=0; i < mat->row; i++){
    for(j=0; j< mat->col; j++){

    printf("mat(%d,%d)=%e, ", i,j,mat->data[i*mat->col + j]);

    }
    printf("\n");
  }
}

void assign_increasing(matrix_t *mat)
{
  int i,j;
    for(i=0; i < mat->row; i++){
      for(j=0; j< mat->col; j++){

        assign_ij(i,j,mat->col*i+j,mat);

      }
    }
}

void matrix_transpose(matrix_t *mat,matrix_t *matT)
{
  int i,j;
    for(i=0; i < mat->row; i++){
      for(j=0; j< mat->col; j++){

        double entry = get_ij(i,j,mat);

        assign_ij(j,i,entry,matT);

      }
    }
}



void deallocate_m(matrix_t *mat)
{
  free(mat->data);
  mat->row=0;
  mat->col=0;
}
