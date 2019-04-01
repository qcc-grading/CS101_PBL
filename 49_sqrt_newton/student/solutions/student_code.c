#include<stdio.h>
#include<stdlib.h>

double squareroot(double f)
{
	if ( f == 0 )
		return 0;

	double x = f;
	double x_next =  x - (x*x-f)/(2*x);
	
	while ( x_next-x < -1e-10 || 1e10 < x_next-x  )
	{
		x = x_next;
		x_next = x - (x*x-f)/(2*x);
	}
	return x_next;
}
