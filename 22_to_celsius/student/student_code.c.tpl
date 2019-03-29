#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
double celsius(double f)
@@celsius@@

double answer(double f){
	return 5.0/9*(f-32);
}
int main(int argc,char** argv)
{
	srand(time(NULL));
	double i = rand();
	double d=answer(i)-celsius(i);
	double err=0.0001;
	if( d<err && d>-err){
		cout<<"Success";
	}
	else cout<<"Fail";
	return 0;
}