#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

double power( double x, unsigned int n )
{ 	
	double f = 1; 
	for (unsigned int i = 1; i <= n; i++ )
		f *= x;

	return f;
}

int main()
{
	double x;
	char c;
	int n;

	cout << "Enter x^n with n non-negative (finish with ctrl-d)\n";
	while ( cin >> x >> c >> n )
		cout <<  x << "^" << n << " = " << power(x,n) << endl;
	
	return 0;
}
