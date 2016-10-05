#ifndef __myexec_print_h_
#define __myexec_print_h_

#include <stdio.h>
#include <stdlib.h>


typedef struct{
    size_t size;
    double * data;
} vector_t;


void allocate_v(vector_t *vect, unsigned int k);

void assign_zero_v(vector_t *vect);

void assign_i(const unsigned int i,
               const double elem, vector_t *vect);

void v1_equal_v2(vector_t *vect1,vector_t *vect2);

void sum_two_vectors(vector_t* v1,vector_t* v2,vector_t* v_sum,double coeff);

void diff_two_vectors(vector_t* v1,vector_t* v2,vector_t* v_diff,double coeff);

double scalar_prod(vector_t* v1,vector_t* v2);

void deallocate_v(vector_t *vect);



#endif
