#ifndef __myexec_solver_h_
#define __myexec_solver_h_

#include "vector_tools.h"
#include "matrix_tools.h"
#include "mat_vect_multy.h"

#include <stdio.h>
#include <stdlib.h>

double compute_alpha(matrix_t* mat, vector_t* r0, vector_t* p0);
vector_t conj_grad_method(matrix_t* mat, vector_t* b);

#endif
