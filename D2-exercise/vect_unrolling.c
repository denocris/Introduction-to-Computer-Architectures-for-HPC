
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

void vector_add(float *a, float *b, float *c, int dim)
{
    int i;

    for (i = 0; i < dim; ++i) {
        c[i] = a[i] + b[i];
    }
}

void vector_add_unroll8(const float * __restrict a, const float * __restrict b,
                        float * __restrict c, int dim)
{
    int i,remainder;

    remainder = dim % 8; // entries that exceed dim % 8.

    // deal with remainder
    for (i = 0; i < remainder; i++) {
        // printf("Remainder %d\n",i);
        c[i] = a[i] + b[i];
    }

    // loop over 8 entries at a time.
    for ( i = i; i < dim; i+=8) {
        // printf("Unroll from %d to %d\n",i,i+7);
        c[i] = a[i] + b[i];
        c[i+1] = a[i+1] + b[i+1];
        c[i+2] = a[i+2] + b[i+2];
        c[i+3] = a[i+3] + b[i+3];
        c[i+4] = a[i+4] + b[i+4];
        c[i+5] = a[i+5] + b[i+5];
        c[i+6] = a[i+6] + b[i+6];
        c[i+7] = a[i+7] + b[i+7];
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

    a=(float*)malloc(dim*sizeof(float));
    b=(float*)malloc(dim*sizeof(float));
    c=(float*)malloc(dim*sizeof(float));

    /* fill vectors */
    for (i=0; i < dim; ++i) {
        a[i] = i;
        b[i] = dim - i;
    }
    /* warm up cache */
    vector_add(a,b,c,dim);
    vector_add(a,b,c,dim);

    /* run vector_add on CPU and measure time */
    secs = seconds();
    vector_add(a,b,c,dim);
    printf("%f\t", seconds()-secs);

    /* run 8x unroll version and measure time */
    secs = seconds();
    // call the vector_add_unroll8 function
    vector_add_unroll8(a,b,c,dim);
    // print the time
    printf("%f\n", seconds()-secs);


    free(a);
    free(b);
    free(c);
    return 0;
}
