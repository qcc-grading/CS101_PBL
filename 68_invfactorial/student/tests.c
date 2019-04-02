#include <stdlib.h>
#include <time.h>
#include "student_code.h"
#include <math.h>
#include "CTester/CTester.h"


double invfactorialtest( unsigned int n )
{
	double f = 1;
	for (unsigned int i = 1; i <= n; i++ )
		f *= 1.0/i;

	return f;
}

void test_invfactorial_ret() {
	set_test_metadata("invfactorial", _("test the function invfactorial"), 1);

	srand(time(NULL));
	unsigned int n1 = 1 + rand()%10;
	unsigned int n2 = 2 + rand()%10;
	unsigned int n3 = 0;
	
	double ans1 = invfactorialtest(n1);
	double ans2 = invfactorialtest(n2);
	double ans3 = invfactorialtest(n3);

	double studentans1;
	double studentans2;
	double studentans3;


	SANDBOX_BEGIN;
	studentans1 = invfactorial(n1);
	studentans2 = invfactorial(n2);
	studentans3 = invfactorial(n3);
	SANDBOX_END;

	CU_ASSERT_EQUAL( ans1, studentans1 );
	CU_ASSERT_EQUAL( ans2, studentans2 );
	CU_ASSERT_EQUAL( ans3, studentans3 );

	if ( ans1 != studentans1 ){
		char *errtpl = _("invfactorial returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans1, ans1);
		push_info_msg(errmsg);
	}
	if ( ans2 != studentans2 ){
		char *errtpl = _("invfactorial returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans2, ans2);
		push_info_msg(errmsg);
	}
	if ( ans3 != studentans3 ){
		char *errtpl = _("invfactorial returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans3, ans3);
		push_info_msg(errmsg);
	}
}

int main(int argc,char** argv)
{
	BAN_FUNCS();
	RUN(test_invfactorial_ret);
}

