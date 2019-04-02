#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

unsigned long int factorial( unsigned int n )
{ 	
	unsigned long int f = 1; 
	for (unsigned int i = 1; i <= n; i++ )
		f *= i;

	return f;
}

int main()
{
	int n;

	cout << "Enter non-negative integers n (finish with ctrl-d)\n";
	while ( cin >> n )
		cout <<  n << "! = " << factorial(n) << endl;
	
	return 0;
}
