#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "student_code.h"
#include "CTester/CTester.h"

void test_fahrenheit_ret() {
	set_test_metadata("fahrenheit", _("test the function fahrenheit"), 1);

	srand(time(NULL));
	double c = 1.0 * (-100 + rand() % 1000);
	double ans = 9.0/5.0*c+32.0;

	double studentans;

	SANDBOX_BEGIN;
	studentans = fahrenheit(c);
	SANDBOX_END;

	CU_ASSERT_EQUAL(fabs(studentans-ans)<0.001,true );
	
	if (fabs(ans-studentans)> 0.001) {
		char *errtpl = _("fahrenheit returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans, ans);
		push_info_msg(errmsg);
	}
}

int main(int argc,char** argv)
{
	BAN_FUNCS();
	RUN(test_fahrenheit_ret);
}

