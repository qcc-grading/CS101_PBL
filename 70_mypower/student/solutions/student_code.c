#include<stdio.h>
#include<stdlib.h>

double power( double x, int n )
{ 	
	int absn = (n >= 0? n : -n);
	double f = 1; 
	for (int i = 1; i <= absn; i++ )
		f *= x;
	if ( n < 0 )
		f = 1.0/f;

	return f;
}
