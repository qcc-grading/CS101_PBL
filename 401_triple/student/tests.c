#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "student_code.h"
#include "CTester/CTester.h"

void test_triple_ret() {
	set_test_metadata("triple", _("test the function triple"), 1);

	srand(time(NULL));
	double x = 1.0 * (-1000 + rand() % 1000);
	double ans = 3*x;

	double studentans;

	SANDBOX_BEGIN;
	studentans = triple(x);
	SANDBOX_END;

	CU_ASSERT_EQUAL(fabs(studentans-ans)<0.001,true );
	
	if (fabs(ans-studentans)> 0.001) {
		char *errtpl = _("triple returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans, ans);
		push_info_msg(errmsg);
	}
}

int main(int argc,char** argv)
{
	BAN_FUNCS();
	RUN(test_triple_ret);
}

