#include<stdio.h>
#include<stdlib.h>

unsigned long int sum( unsigned int n )
{ 
	unsigned long int f = 1; 
	for (unsigned int i = 1; i <= n; i++ )
		f *= i;
      
	return f;	
}
