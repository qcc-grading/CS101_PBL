#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

double power( double x, int n )
{ 	
	int absn = (n >= 0? n : -n);
	double f = 1; 
	for (int i = 1; i <= absn; i++ )
		f *= x;
	if ( n < 0 )
		f = 1.0/f;

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
