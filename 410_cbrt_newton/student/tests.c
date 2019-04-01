#include <stdlib.h>
#include <time.h>
#include "student_code.h"
#include <math.h>
#include "CTester/CTester.h"

void test_cuberoot_ret() {
	set_test_metadata("cuberoot", _("test the function cuberoot"), 1);

	srand(time(NULL));
	double x1 = 0.5 + rand()%1000;
	double x2 = pow(1+rand()%100,3);
	double x3 = 0.0;
	double x4 = -x1;
	
	double ans1 = pow(x1,1.0/3.0);
	double ans2 = pow(x2,1.0/3.0);
	double ans3 = 0.0;
	double ans4 = -ans1;

	double studentans1;
	double studentans2;
	double studentans3;
	double studentans4;


	SANDBOX_BEGIN;
	studentans1 = cuberoot(x1);
	studentans2 = cuberoot(x2);
	studentans3 = cuberoot(x3);
	studentans4 = cuberoot(x4);
	SANDBOX_END;

	CU_ASSERT_EQUAL( fabs(ans1-studentans1)<1e-5, true);
	CU_ASSERT_EQUAL( fabs(ans2-studentans2)<1e-5, true);
	CU_ASSERT_EQUAL( fabs(ans3-studentans3)<1e-5, true);
	CU_ASSERT_EQUAL( fabs(ans4-studentans4)<1e-5, true);

	if ( fabs(ans1-studentans1) >= 1e-3 ){
		char *errtpl = _("cuberoot returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans1, ans1);
		push_info_msg(errmsg);
	}
	if ( fabs(ans2-studentans2) >= 1e-3 ){
		char *errtpl = _("cuberoot returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans2, ans2);
		push_info_msg(errmsg);
	}
	if ( fabs(ans3-studentans3) >= 1e-3 ){
		char *errtpl = _("cuberoot returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans3, ans3);
		push_info_msg(errmsg);
	}
	if ( fabs(ans4-studentans4) >= 1e-3 ){
		char *errtpl = _("cuberoot returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans4, ans4);
		push_info_msg(errmsg);
	}
}

int main(int argc,char** argv)
{
	BAN_FUNCS();
	RUN(test_cuberoot_ret);
}

