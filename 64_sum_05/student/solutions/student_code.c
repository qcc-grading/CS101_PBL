#include<stdio.h>
#include<stdlib.h>

double sumharmonic( int n )
{ 
	double s = 0; 
	for (int i = 1; i <= n; i++ )
		s += 1.0/i;
      
	return s;	
}
