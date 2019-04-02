#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

double sumaltharmonic( int n )
{ 	
	double s = 0; 
	double sign = 1.0;
	for (int i = 1; i <= n; i++ )
	{
		s += sign/i;
     	sign *= -1;
    }

	return s;
}

int main()
{
	int n;

	cout << "Enter non-negative integers n (finish with ctrl-d)\n";
	while ( cin >> n )
		if ( n == 1 )
			cout << "1/1 = " << sumaltharmonic(n) << endl;
		else if ( n == 2 )
			cout << "1 - 1/2 = " << sumaltharmonic(n) << endl;
		else if ( n == 3 )
			cout << "1 - 1/2 + 1/3 = " << sumaltharmonic(n) << endl;
		else
			cout << "1 - 1/2 + ... +/-  1/" << n << " = " << sumaltharmonic(n) << endl;
	
	return 0;
}
