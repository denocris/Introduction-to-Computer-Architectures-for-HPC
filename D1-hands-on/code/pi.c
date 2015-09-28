// pi.c :Montecarlo integration to determine pi
#include <stdio.h>
#include <stdlib.h>
// if you don ' t have drand48 uncomment the following two lines 10
// #define drand48 1.0/RANDMAXrand
// #define srand48 srand
#define seed 68111 // seed for number generator
main (int argc, char ** argv) {

   if (argc<2)
	{
	printf(" Usage: %s (number) \n",argv[0]);
	return 1;
	}
    int max =atoi(argv[1]);
    int i , pi = 0 ;
    double x , y , area ;
    FILE  *output ; // save data in pond.dat
    output = fopen ("pond.dat" , "w") ;
    srand48 ( seed ) ; // seed the number generator
    for ( i = 1 ; i<= max ; i++)
    {
        x = drand48()*2- 1; // creates floats between
        y = drand48()*2- 1; // 1 and
        if ((x*x + y*y)<1) pi++; // stone hit the pond
        area = 4*(double)pi/ i ; // calculate area
    }
    fprintf ( output,"%i\t%f\n",i,area ) ;
    printf ( "data stored in pond.dat \n" ) ;
    fclose (output) ;
}
