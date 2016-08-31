#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <mpi.h>
#define USE MPI
#define SEED 35791246
int main ( int argc , char *argv[ ] )
{
    int niter =0;
    double x, y ;
    int i , j , count=0, mycount ; // # of points in the 1st quadrant of unit circle
    double z ;
    double pi ;
    int myid , numprocs , proc ;
    MPI_Status status;
    int master =0;
    int tag = 123;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    if ( argc <=1) {
        fprintf (stderr , " Usage : monte_pi_mpi number_of_iterations \n" ) ;
        MPI_Finalize() ;
        exit(-1) ;
    }

    sscanf(argv [1], "%d",&niter ) ; // 1st argument i s the number of iterations/
// initialize random numbers /
    srand48(SEED*myid) ; // seed the number generator
    mycount=0;
    for ( i =0; i<niter ; i++) {
        x = drand48()*2 -1 ;
        y = drand48()*2 -1 ;
        z = x*x + y*y ;
        if (z<=1) mycount++;
    }
    if (myid ==0) {   //if I am the master process gather results from others


        count = mycount ;
        for ( proc=1; proc<numprocs ; proc++) {
            MPI_Recv(&mycount,1,MPI_REAL,proc,tag,MPI_COMM_WORLD,&status ) ;
            count +=mycount ;
        }
        pi=( double ) count /(niter*numprocs )*4 ;
        printf ( "\n # of trials = %d , estimate of pi is %g \n" , niter*numprocs , pi ) ;
    }
    else {   // for a l l the slave processes send results to the master /
        printf ( " Processor %d sending results = %d to master process \n" ,myid , mycount) ;
        MPI_Send(&mycount , 1 ,MPI_REAL, master , tag ,MPI_COMM_WORLD) ;
    }

    MPI_Finalize() ; // let MPI finish up /

}


