#include<stdio.h>
#include<stdlib.h>

int gcd( int a, int b)
{ 
	int r0 = a;
    int r1 = b;
    int r2;
    
    while (r1 )
    {
    	r2 = r0 % r1;
        r0 = r1;
        r1 = r2;
    }
    
    return r0 >= 0 ? r0: -r0;
}
