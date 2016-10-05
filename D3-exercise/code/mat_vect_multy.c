#include "mat_vect_multy.h"

#include <stdio.h>
#include <stdlib.h>

void multiply_mat_vect(matrix_t *mat, vector_t *v_in, vector_t *v_out)
{

  int i;
  int j;
  for (i = 0; i < mat->row; i++)
  {
  v_out->data[i]=0;
    for (j = 0; j < mat->col; j++)
    {
      v_out -> data[i] += mat->data[i*mat->col+j]*v_in->data[j];

    }
  }
}
