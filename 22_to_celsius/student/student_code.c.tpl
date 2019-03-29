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
	double s[]={42.1,35.8,9.1,83.4};
	double i = rand()%4;
	double d=answer(i)-celsius(i);
	double err=0.0001;
	if( d<err && d>-err){
		cout<<"Success";
	}
	else cout<<"Fail";
	return 0;
}