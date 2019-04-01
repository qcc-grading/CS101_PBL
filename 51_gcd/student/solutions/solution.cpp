#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int gcd( int a, int b )
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
    
    return r0 > 0 ? r0 : -r0;

}

int main()
{
	int a, b;

	cout << "Enter pairs of integers (finish with ctrl-d)\n";
	while ( cin >> a >> b )
		cout << "gcd(" << a << ", " << b << ") = " << gcd(a,b) << endl;
	
	
	return 0;
}
