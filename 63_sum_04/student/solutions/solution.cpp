#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int sum( int n )
{ 	
	int s = 0; 
	for (int i = 1; i <= 2*n-1; i+=2 )
		s += i;
      
	return s;
}

int main()
{
	int n;

	cout << "Enter non-negative integers n (finish with ctrl-d)\n";
	while ( cin >> n )
		if ( n == 1 )
			cout << "1 = " << sum(n) << endl;
		else if ( n == 2 )
			cout << "1 + 3 = " << sum(n) << endl;
		else if ( n == 3 )
			cout << "1 + 3 + 5 = " << sum(n) << endl;
		else
			cout << "1 + 3 + ... +  " << 2*n-1 << " = " << sum(n) << endl;
	
	return 0;
}
