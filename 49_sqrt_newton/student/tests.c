#include <stdlib.h>
#include <time.h>
#include "student_code.h"
#include <math.h>
#include "CTester/CTester.h"

void test_squareroot_ret() {
	set_test_metadata("squareroot", _("test the function squareroot"), 1);

	srand(time(NULL));
	double x1 = 0.5 + rand()%1000;
	double x2 = pow(1+rand()%100,2);
	double x3 = 0.0;
	
	double ans1 = sqrt(x1);
	double ans2 = sqrt(x2);
	double ans3 = 0.0;

	double studentans1;
	double studentans2;
	double studentans3;


	SANDBOX_BEGIN;
	studentans1 = squareroot(x1);
	studentans2 = squareroot(x2);
	studentans3 = squareroot(x3);
	SANDBOX_END;

	CU_ASSERT_EQUAL( fabs(ans1-studentans1)<1e-5, true);
	CU_ASSERT_EQUAL( fabs(ans2-studentans2)<1e-5, true);
	CU_ASSERT_EQUAL( fabs(ans3-studentans3)<1e-5, true);

	if ( fabs(ans1-studentans1) >= 1e-3 ){
		char *errtpl = _("squareroot returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans1, ans1);
		push_info_msg(errmsg);
	}
	if ( fabs(ans2-studentans2) >= 1e-3 ){
		char *errtpl = _("squareroot returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans2, ans2);
		push_info_msg(errmsg);
	}
	if ( fabs(ans3-studentans3) >= 1e-3 ){
		char *errtpl = _("squareroot returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans3, ans3);
		push_info_msg(errmsg);
	}
}

int main(int argc,char** argv)
{
	BAN_FUNCS();
	RUN(test_squareroot_ret);
}

