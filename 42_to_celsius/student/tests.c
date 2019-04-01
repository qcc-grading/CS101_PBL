#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "student_code.h"
#include "CTester/CTester.h"

void test_celsius_ret() {
	set_test_metadata("celsius", _("test the function celsius"), 1);

	srand(time(NULL));
	double f = 1.0 * (-100 + rand() % 1000);
	double ans = 5.0/9.0*(f-32.0);

	double studentans;

	SANDBOX_BEGIN;
	studentans = celsius(f);
	SANDBOX_END;

	CU_ASSERT_EQUAL(fabs(studentans-ans)<0.001,true );
	
	if (fabs(ans-studentans)> 0.001) {
		char *errtpl = _("celsius returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans, ans);
		push_info_msg(errmsg);
	}
}

int main(int argc,char** argv)
{
	BAN_FUNCS();
	RUN(test_celsius_ret);
}

