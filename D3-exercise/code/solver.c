#include "solver.h"

double compute_alpha(matrix_t* mat, vector_t* r0, vector_t* p0)
{
  vector_t Ap0;

  double num = 0;
  double den = 0;

  double alpha = 0;

  allocate_v(&Ap0,p0->size);
  assign_zero_v(&Ap0);
  multiply_mat_vect(mat, p0, &Ap0);

  num = scalar_prod(r0,r0);
  den = scalar_prod(p0,&Ap0);

  alpha = num / den;

  deallocate_v(&Ap0);
  //printf("num = %e\n", num);
  //printf("den = %e\n", den);

  //printf("alpha = %e\n", alpha);
  return alpha;

}


vector_t conj_grad_method(matrix_t* mat, vector_t* b)
{

  vector_t r0;
  vector_t p0;
  vector_t x0;
  vector_t x_solution;
  vector_t Ax0;
  vector_t Ap0;
  vector_t r_old;


  allocate_v(&r0,mat->row);
  allocate_v(&x_solution,mat->row);
  allocate_v(&x0,mat->row);
  allocate_v(&p0,mat->row);
  allocate_v(&r_old,mat->row);
  allocate_v(&Ax0,mat->row);
  allocate_v(&Ap0,mat->row);


  assign_zero_v(&x_solution);

// Construct the ansatz vector x0

  assign_i(0,2,&x0);
  assign_i(1,1,&x0);

  multiply_mat_vect(mat, &x0, &Ax0);

// Let's start

  int i;
  for (i = 0; i < mat->row; i++){

    r0.data[i] = b->data[i] - Ax0.data[i];

    p0.data[i] = r0.data[i];

    x_solution.data[i] = x0.data[i];

  }


// In this for the method is implemented

  int k;
  for (k = 0; k < mat->row; k++){

    multiply_mat_vect(mat, &p0, &Ap0);

    double alpha = compute_alpha(mat,&r0,&p0);

    v1_equal_v2(&r_old,&r0);

    sum_two_vectors(&x_solution,&p0,&x_solution,alpha);  // x_{k+1} = x_{k} + alpha_k * p_{k}

    diff_two_vectors(&r0,&Ap0,&r0,alpha); // r_{k+1} = r_{k} - alpha_k * A p_{k}

    double rr_small = scalar_prod(&r0,&r0);

    if (rr_small < 0.000000001){break;}

    double beta = scalar_prod(&r0,&r0) / scalar_prod(&r_old,&r_old);

    sum_two_vectors(&r0,&p0,&p0,beta); // p_{k+1} = r_{k+1} + beta_k * p_{k}


// Old version:

/*
    int j;
    for (j = 0; j < x0.size; j++)
        {

          //double elem_x;
          //elem_x = x_solution.data[j] + alpha*p0.data[j];
          //assign_i(j,elem_x,&x_solution);

          //double elem_r;
          //elem_r = r0.data[j] - alpha*Ap0.data[j];
          //assign_i(j,elem_r,&r0);

        }*/

    /*int j;
    for (j = 0; j < x0.size; j++)
            {

          double elem_p;
          elem_p = r0.data[j] + beta*p0.data[j];
          assign_i(j,elem_p,&p0);

        }*/

  }

  return x_solution;

}
