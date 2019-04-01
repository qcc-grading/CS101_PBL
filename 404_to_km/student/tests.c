#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "student_code.h"
#include "CTester/CTester.h"

void test_kilometers_ret() {
	set_test_metadata("kilometers", _("test the function kilometers"), 1);

	srand(time(NULL));
	double mi = 13 + 1.0 * rand();
	double ans = mi*1.609;

	double studentans;

	SANDBOX_BEGIN;
	studentans = kilometers(mi);
	SANDBOX_END;

	CU_ASSERT_EQUAL(fabs(studentans-ans)<0.001,true );
	
	if (fabs(ans-studentans)> 0.001) {
		char *errtpl = _("kilometers returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans, ans);
		push_info_msg(errmsg);
	}
}

int main(int argc,char** argv)
{
	BAN_FUNCS();
	RUN(test_kilometers_ret);
}

