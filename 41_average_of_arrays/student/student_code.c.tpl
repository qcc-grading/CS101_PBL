#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
double avg(int a[], int n)
@@avgarrayn@@
double answer(int a[],int n){
	int s=0;
	for(int i=0;i<n;++i)
		s=s+a[i];
	return double(s)/n;
}
int main(int argc,char** argv)
{
	srand(time(NULL));
	int n=rand()%10+1;  // 1<=n<=10
	int *a=new int[n];
	for(int i=0;i<n;++i) a[i]=rand()%100; // 0<=a[i]<100
	double d=answer(a,n)-avg(a,n);
	double err=0.0001;
	if( d<err && d>-err){
		cout<<"Success";
	}
	else cout<<"Fail";
	delete a[];
	return 0;
}