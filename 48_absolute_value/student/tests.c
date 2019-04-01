#include <stdlib.h>
#include <time.h>
#include "student_code.h"
#include "CTester/CTester.h"

void test_absvalue_ret() {
	set_test_metadata("absvalue", _("test the function absvalue"), 1);

	srand(time(NULL));
	double x = 37.2 + rand()%1000;
	double studentans1;
	double studentans2;
	double studentans3;


	SANDBOX_BEGIN;
	studentans1 = absvalue(x);
	studentans2 = absvalue(-x);
	studentans3 = absvalue(0);
	SANDBOX_END;

	CU_ASSERT_EQUAL(studentans1, x);
	CU_ASSERT_EQUAL(studentans2, x);
	CU_ASSERT_EQUAL(studentans3, 0);
	if (x != studentans1 ){
		char *errtpl = _("absvalue returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans1, x);
		push_info_msg(errmsg);
	}
	if ( x != studentans2 ){
		char *errtpl = _("absvalue returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans2, -x);
		push_info_msg(errmsg);
	}
	if ( 0 != studentans3 ){
		char *errtpl = _("absvalue returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans3, 0);
		push_info_msg(errmsg);
	}
}

int main(int argc,char** argv)
{
	BAN_FUNCS();
	RUN(test_absvalue_ret);
}

