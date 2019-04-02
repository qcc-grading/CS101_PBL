#include<stdio.h>
#include<stdlib.h>

int sumofcubes( int n )
{ 
	int s = 0; 
	for (int i = 0; i <= n; i++ )
		s += i*i*i;
      
	return s;	
}
