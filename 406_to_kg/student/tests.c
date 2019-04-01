#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "student_code.h"
#include "CTester/CTester.h"

void test_kilograms_ret() {
	set_test_metadata("kilograms", _("test the function kilograms"), 1);

	srand(time(NULL));
	double lbs = rand() % 100000;
	double ans = 2.2*lbs;

	double studentans;

	SANDBOX_BEGIN;
	studentans = kilograms(lbs);
	SANDBOX_END;

	CU_ASSERT_EQUAL(fabs(studentans-ans)<0.001,true );
	
	if (fabs(ans-studentans)> 0.001) {
		char *errtpl = _("kilograms returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans, ans);
		push_info_msg(errmsg);
	}
}

int main(int argc,char** argv)
{
	BAN_FUNCS();
	RUN(test_kilograms_ret);
}

