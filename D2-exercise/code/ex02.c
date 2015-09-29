/*
 * Copyright (C) 2001-2013 The Abdus Salam, International Centre of Theoretical Physics (ICTP)
 *
 * This file is distributed under the terms of the GNU General Public License. 
 * See http://www.gnu.org/copyleft/gpl.txt 
 *
 * The code was developed for the exercise session of M1.2 - HPC Master SISSA/ICTP
 *
 * Author: Ivan Girotto
 * Last update: Sept-2015
 * 
 */
 
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

double seconds(){

/* Return the second elapsed since Epoch (00:00:00 UTC, January 1, 1970) */
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
  return sec;
}

/* implement a simple vector addition: C = A + B */

void vector_add_noopt(float *a, float *b, float *c, int dim)
{
    int i;

    for (i = 0; i < dim; ++i) {
        c[i] = a[i] + b[i];
    }
}

void vector_add_unroll8(const float * __restrict a, const float * __restrict b,
                        float * __restrict c, int dim)
{
    int i,pre;

#if defined(__GNUC__) && !defined(__INTEL_COMPILER)
    const float *x = __builtin_assume_aligned(a,64);
    const float *y = __builtin_assume_aligned(b,64);
    float *z = __builtin_assume_aligned(c,64);
    printf("assume aligned\n");
#else
    const float *x = a;
    const float *y = b;
    float *z = c;
    printf("standard declaration\n");
#endif

    pre = dim & 8; // entries that exceed dim & 8.

    // loop over 8 entries at a time.

    }
}

int main(int argc, char **argv)
{
    double secs;
    float *a, *b, *c;
    int dim,i,flag;

    if (argc < 2) {
        printf("usage: %s <dim>\n", argv[0]);
        return 1;
    }

    dim = atoi(argv[1]);

    if (dim < 1) {
        printf("usage: %s <dim>, with dim > 0\n", argv[0]);
        return 2;
    }

    posix_memalign((void **)&a,64,dim*sizeof(float));
    posix_memalign((void **)&b,64,dim*sizeof(float));
    posix_memalign((void **)&c,64,dim*sizeof(float));

    /* fill vectors */
    for (i=0; i < dim; ++i) {
        a[i] = i;
        b[i] = dim - i;
    }
    /* warm up cache */
    vector_add_noopt(a,b,c,dim);
    vector_add_noopt(a,b,c,dim);

    /* run vector_add_noopt on CPU and measure time */
    
    
    /* check result */
    flag=0;
    for (i=0; i < dim; ++i) {
        if (c[i] != dim) {
            flag=1;
        }
    }
    if (flag != 0) {
        printf("noopt check FAIL\n");
    }

    /* run 8x unroll version and measure time */
    
    // 
    // call the vector_add_unroll8 function
    // print the time
    
    /* check result */
    // check the flags again.

    return 0;
}
