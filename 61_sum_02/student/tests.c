#include <stdlib.h>
#include <time.h>
#include "student_code.h"
#include <math.h>
#include "CTester/CTester.h"


int sumofsquarestest( int n )
{
	int s = 0;
	for (int i = 0; i <= n; i++ )
		s += i*i;

	return s;
}

void test_sumofsquares_ret() {
	set_test_metadata("sumofsquares", _("test the function sumofsquares"), 1);

	srand(time(NULL));
	int n1 = 5 + rand()%10;
	int n2 = 20 + rand()%10;
	int n3 = 0;
	
	int ans1 = sumofsquarestest(n1);
	int ans2 = sumofsquarestest(n2);
	int ans3 = sumofsquarestest(n3);

	int studentans1;
	int studentans2;
	int studentans3;


	SANDBOX_BEGIN;
	studentans1 = sumofsquares(n1);
	studentans2 = sumofsquares(n2);
	studentans3 = sumofsquares(n3);
	SANDBOX_END;

	CU_ASSERT_EQUAL( ans1, studentans1 );
	CU_ASSERT_EQUAL( ans2, studentans2 );
	CU_ASSERT_EQUAL( ans3, studentans3 );

	if ( ans1 != studentans1 ){
		char *errtpl = _("sumofsquares returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans1, ans1);
		push_info_msg(errmsg);
	}
	if ( ans2 != studentans2 ){
		char *errtpl = _("sumofsquares returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans2, ans2);
		push_info_msg(errmsg);
	}
	if ( ans3 != studentans3 ){
		char *errtpl = _("sumofsquares returns the wrong value: you returned %d for %d");
		char errmsg[strlen(errtpl+30)];
		sprintf(errmsg, errtpl, studentans3, ans3);
		push_info_msg(errmsg);
	}
}

int main(int argc,char** argv)
{
	BAN_FUNCS();
	RUN(test_sumofsquares_ret);
}

