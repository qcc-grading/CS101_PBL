#include <iostream>
using namespace std;
int main()
{
	cout<<"Type your integer:";
int i=0;
cin>>i;
if(i>0) cout<<"POSITIVE";
else if (i==0) cout<<"ZERO";
else cout<<"NEGATIVE";
	return 0;
}