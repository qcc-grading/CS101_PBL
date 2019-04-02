#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int sumofsquares( int n )
{ 	
	int s = 0; 
	for (int i = 0; i <= n; i++ )
		s += i*i;
      
	return s;
}

int main()
{
	int n;

	cout << "Enter non-negative integers n (finish with ctrl-d)\n";
	while ( cin >> n )
		if ( n == 0 )
			cout << "0^2 = " << sumofsquares(n) << endl;
		else if ( n == 1 )
			cout << "0^2 + 1^2 = " << sumofsquares(n) << endl;
		else if ( n == 2 )
			cout << "0^2 + 1^2 + 2^2 = " << sumofsquares(n) << endl;
		else if ( n == 3 )
			cout << "0^2 + 1^2 + 2^2 + 3^2 = " << sumofsquares(n) << endl;
		else
			cout << "0^2 + 1^2 + 2^2 + ... +  " << n << "^2 = " << sumofsquares(n) << endl;
	
	return 0;
}