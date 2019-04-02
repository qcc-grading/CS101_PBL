#include<stdio.h>
#include<stdlib.h>

int sumofsquares( int n )
{ 
	int s = 0; 
	for (int i = 0; i <= n; i++ )
		s += i*i;
      
	return s;	
}
