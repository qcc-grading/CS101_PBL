#include<stdio.h>
#include<stdlib.h>

double power( double x, unsigned int n )
{ 	
	double f = 1; 
	for (unsigned int i = 1; i <= n; i++ )
		f *= x;

	return f;
}