#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "student_code.h"
#include "CTester/CTester.h"

void test_miles_ret() {
	set_test_metadata("miles", _("test the function miles"), 1);

	srand(time(NULL));
	double km = 13 + 1.0 * rand();
	double ans = km/1.609;

	double studentans;

	SANDBOX_BEGIN;
	studentans = miles(km);
	SANDBOX_END;

	CU_ASSERT_EQUAL(fabs(studentans-ans)<0.001,true );
	
	if (fabs(ans-studentans)> 0.001) {
		char *errtpl = _("miles returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans, ans);
		push_info_msg(errmsg);
	}
}

int main(int argc,char** argv)
{
	BAN_FUNCS();
	RUN(test_miles_ret);
}

