#include <iostream>
using namespace std;
int main()
{
	cout<<"Type your positive integer:";
    int n=0;
    int s=0;
    cin>>n;
    for(int i=1;i<n;++i){
        s=s+i;
        cout<<i<<"+";
    }
    s=s+n;
    cout<<n<<"="<<s;
	return 0;
}