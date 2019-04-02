#include <stdlib.h>
#include <time.h>
#include "student_code.h"
#include <math.h>
#include "CTester/CTester.h"


double powertest( double x, unsigned int n )
{
	
	double f = 1;
	for (unsigned int i = 1; i <= n; i++ )
		f *= x;

	return f;
}

void test_power_ret() {
	set_test_metadata("power", _("test the function power"), 1);

	srand(time(NULL));
	double x = 3+rand()%20;
	unsigned int n1 = 1 + rand()%10;
	unsigned int n2 = 2 + rand()%10;
	unsigned int n3 = 0;
	
	double ans1 = powertest(x,n1);
	double ans2 = powertest(x,n2);
	double ans3 = powertest(x,n3);
	double ans4 = powertest(0,0);

	double studentans1;
	double studentans2;
	double studentans3;
	double studentans4;


	SANDBOX_BEGIN;
	studentans1 = power(x,n1);
	studentans2 = power(x,n2);
	studentans3 = power(x,n3);
	studentans4 = power(0,0);
	SANDBOX_END;

	CU_ASSERT_EQUAL( ans1, studentans1 );
	CU_ASSERT_EQUAL( ans2, studentans2 );
	CU_ASSERT_EQUAL( ans3, studentans3 );
	CU_ASSERT_EQUAL( ans4, studentans4 );

	if ( ans1 != studentans1 ){
		char *errtpl = _("power returns the wrong value: you returned %lf for %lf");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans1, ans1);
		push_info_msg(errmsg);
	}
	if ( ans2 != studentans2 ){
		char *errtpl = _("power returns the wrong value: you returned %lf for %lf");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans2, ans2);
		push_info_msg(errmsg);
	}
	if ( ans3 != studentans3 ){
		char *errtpl = _("power returns the wrong value: you returned %lf for %lf");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans3, ans3);
		push_info_msg(errmsg);
	}
	if ( ans4 != studentans4 ){
		char *errtpl = _("power returns the wrong value: you returned %lf for %lf");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans4, ans4);
		push_info_msg(errmsg);
	}
}

int main(int argc,char** argv)
{
	BAN_FUNCS();
	RUN(test_power_ret);
}

