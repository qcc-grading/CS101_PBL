#include <stdlib.h>
#include <time.h>
#include "student_code.h"
#include <math.h>
#include "CTester/CTester.h"


int gcdtest( int a, int b )
{
	int r0 = a;
	int r1 = b;
	int r2;
	while (r1)
	{
		r2 = r0 % r1;
		r0 = r1;
		r1 = r2;
	}
	return r0 >= 0 ? r0 : -r0;
}

void test_gcd_ret() {
	set_test_metadata("gcd", _("test the function gcd"), 1);

	srand(time(NULL));
	int x1 = 1 + rand()%1000;
	int x2 = 1 + rand()%100;
	int x3 = 0;
	
	int ans1 = gcdtest(x1,x2);
	int ans2 = gcdtest(x2,x3);
	int ans3 = gcdtest(-x1,-x2);

	int studentans1;
	int studentans2;
	int studentans3;


	SANDBOX_BEGIN;
	studentans1 = gcd(x1,x2);
	studentans2 = gcd(x2,x3);
	studentans3 = gcd(-x1,-x2);
	SANDBOX_END;

	CU_ASSERT_EQUAL( ans1, studentans1 );
	CU_ASSERT_EQUAL( ans2, studentans2 );
	CU_ASSERT_EQUAL( ans3, studentans3 );

	if ( ans1 != studentans1 ){
		char *errtpl = _("gcd returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans1, ans1);
		push_info_msg(errmsg);
	}
	if ( ans2 != studentans2 ){
		char *errtpl = _("gcd returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans2, ans2);
		push_info_msg(errmsg);
	}
	if ( ans3 != studentans3 ){
		char *errtpl = _("gcd returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans3, ans3);
		push_info_msg(errmsg);
	}
}

int main(int argc,char** argv)
{
	BAN_FUNCS();
	RUN(test_gcd_ret);
}

