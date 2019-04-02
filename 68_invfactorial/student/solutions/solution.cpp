#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

double invfactorial( unsigned int n )
{ 	
	double f = 1; 
	for (unsigned int i = 1; i <= n; i++ )
		f *= 1.0/i;

	return f;
}

int main()
{
	int n;

	cout << "Enter non-negative integers n (finish with ctrl-d)\n";
	while ( cin >> n )
		cout <<  "1/" << n << "! = " << invfactorial(n) << endl;
	
	return 0;
}
