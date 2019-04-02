#include<stdio.h>
#include<stdlib.h>

double sumharmonic( int n )
{ 
	double s = 0;
	double sign = 1.0;
	for (int i = 1; i <= n; i++ )
	{
		s += sign/i;
		sign *= -1;
    }
	return s;	
}
