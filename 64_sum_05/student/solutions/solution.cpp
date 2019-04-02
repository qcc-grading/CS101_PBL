#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

double sumharmonic( int n )
{ 	
	double s = 0; 
	for (int i = 1; i <= n; i++ )
		s += 1.0/i;
      
	return s;
}

int main()
{
	int n;

	cout << "Enter non-negative integers n (finish with ctrl-d)\n";
	while ( cin >> n )
		if ( n == 1 )
			cout << "1/1 = " << sumharmonic(n) << endl;
		else if ( n == 2 )
			cout << "1+ 1/2 = " << sumharmonic(n) << endl;
		else if ( n == 3 )
			cout << "1 + 1/2 + 1/3 = " << sumharmonic(n) << endl;
		else
			cout << "1 + 1/2 + ... +  1/" << n << " = " << sumharmonic(n) << endl;
	
	return 0;
}
