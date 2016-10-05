#ifndef __myexec_matrix_tools_h_
#define __myexec_matrix_tools_h_

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    size_t row, col;
    double * data;
} matrix_t;


void allocate_m(matrix_t *mat, unsigned int m, unsigned int n);

void assign_zero_m(matrix_t *mat);

void assign_ij(const unsigned int i, const unsigned int j,
               const double elem, matrix_t *mat);

void deallocate_m(matrix_t *mat);

void print_m(matrix_t *mat);

void assign_increasing(matrix_t *mat);

double get_ij(const unsigned int i, const unsigned int j, matrix_t *mat);

void matrix_transpose(matrix_t *mat,matrix_t *matT);


#endif
