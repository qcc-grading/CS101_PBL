#include <stdlib.h>
#include <time.h>
#include "student_code.h"
#include <math.h>
#include "CTester/CTester.h"


double suminvsquarestest( int n )
{
	double s = 0;
	for (int i = 1; i <= n; i++ )
		s += 1.0/(i*i);

	return s;
}

void test_suminvsquares_ret() {
	set_test_metadata("suminvsquares", _("test the function suminvsquares"), 1);

	srand(time(NULL));
	int n1 = 5 + rand()%10;
	int n2 = 20 + rand()%100;
	
	double ans1 = suminvsquarestest(n1);
	double ans2 = suminvsquarestest(n2);

	double studentans1;
	double studentans2;


	SANDBOX_BEGIN;
	studentans1 = suminvsquares(n1);
	studentans2 = suminvsquares(n2);
	SANDBOX_END;

	CU_ASSERT_EQUAL( fabs(ans1-studentans1) < 1e-5, true );
	CU_ASSERT_EQUAL( fabs(ans2-studentans2) < 1e-5, true );

	if ( fabs(ans1-studentans1) >= 1e-5 ){
		char *errtpl = _("suminvsquares returns the wrong value: you returned %lf for %lf");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans1, ans1);
		push_info_msg(errmsg);
	}
	if ( fabs(ans2-studentans2) >= 1e-5 ){
		char *errtpl = _("suminvsquares returns the wrong value: you returned %lf for %lf");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans2, ans2);
		push_info_msg(errmsg);
	}
}

int main(int argc,char** argv)
{
	BAN_FUNCS();
	RUN(test_suminvsquares_ret);
}

