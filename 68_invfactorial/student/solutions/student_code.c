#include<stdio.h>
#include<stdlib.h>

double invfactorial( unsigned int n )
{
	double f = 1;
	for (unsigned int i =1; i <=n; i++)
		f *= 1.0/i;
	return f; 
}
