#include <stdlib.h>
#include <time.h>
#include "student_code.h"
#include <math.h>
#include "CTester/CTester.h"


unsigned long int factorialtest( unsigned int n )
{
	unsigned long int f = 1;
	for (unsigned int i = 1; i <= n; i++ )
		f *= i;

	return f;
}

void test_factorial_ret() {
	set_test_metadata("factorial", _("test the function factorial"), 1);

	srand(time(NULL));
	unsigned int n1 = 1 + rand()%10;
	unsigned int n2 = 2 + rand()%10;
	unsigned int n3 = 0;
	
	long int ans1 = factorialtest(n1);
	long int ans2 = factorialtest(n2);
	long int ans3 = factorialtest(n3);

	unsigned int studentans1;
	unsigned int studentans2;
	unsigned int studentans3;


	SANDBOX_BEGIN;
	studentans1 = factorial(n1);
	studentans2 = factorial(n2);
	studentans3 = factorial(n3);
	SANDBOX_END;

	CU_ASSERT_EQUAL( ans1, studentans1 );
	CU_ASSERT_EQUAL( ans2, studentans2 );
	CU_ASSERT_EQUAL( ans3, studentans3 );

	if ( ans1 != studentans1 ){
		char *errtpl = _("factorial returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans1, ans1);
		push_info_msg(errmsg);
	}
	if ( ans2 != studentans2 ){
		char *errtpl = _("factorial returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans2, ans2);
		push_info_msg(errmsg);
	}
	if ( ans3 != studentans3 ){
		char *errtpl = _("factorial returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans3, ans3);
		push_info_msg(errmsg);
	}
}

int main(int argc,char** argv)
{
	BAN_FUNCS();
	RUN(test_factorial_ret);
}

