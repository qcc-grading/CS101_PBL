#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int addone( int i )
{
@	@addone@@
}
int main(int argc,char** argv)
{
	srand(time(NULL));
	int i = rand();
	if (addone(i)==i+1){
		cout<<"Success";
	}
	else cout<<"Fail";
	return 0;
}