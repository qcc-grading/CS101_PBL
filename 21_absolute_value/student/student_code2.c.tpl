#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int absval( int i )
{
@	@absval@@
}
int main(int argc,char** argv)
{
	srand(time(NULL));
	int i = rand();
	while (!i) i = rand();
	int ret1 = 0;
	int ret2 = 0;
	int ret3 = 567;

	ret1 = absval(i);
	ret2 = absval(-i);
	ret3 = absval(0);

	if (ret1==i and ret2==i and ret3==0){
		cout<<"Success";
	}
	else cout<<"Fail";
	return 0;
}


