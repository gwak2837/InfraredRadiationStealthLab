#include "StdAfx.h"
#include "tester_example.h"
#include "timecount.h"
#include "elementsearch.h"
#include "elementsearch2.h"
#include "elementsearch3.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(tester_example);

tester_example::tester_example(void)
{
	resetlog();
}

tester_example::~tester_example(void)
{
	
}

void tester_example::setUp()
{
	timeStart();
}

void tester_example::tearDown()
{
	timeEnd();
	writelog_console();
}

bool result_test(vector<element_self>& src, vector<element_self>& trg, vector<int>& result)
{
	int i;

	for(i = 0; i < trg.size() ; i++){
		
		if (trg[i].eid == result[i]){
		}
		else {
			break;
		}
	}
	if (i == trg.size()) return true;

	else return false;
}

void tester_example::testmethod1(char* strsrc, char* strdst)
{
	geometry src;
	geometry dst;

	fin::fin_geo(strsrc, src);
	fin::fin_geo(strdst, dst);

	vector<int> result;

	search_nearElement(src.eself_vec, dst.eself_vec, result);
	bool checkvalid;
	if(result_test(src.eself_vec, dst.eself_vec, result)) {
		checkvalid = true;
	}
	else {
		checkvalid = false;
	}
	CPPUNIT_ASSERT(checkvalid);
}

void tester_example::testmethod2(char* strsrc, char* strdst)
{
	geometry src;
	geometry dst;

	fin::fin_geo(strsrc, src);
	fin::fin_geo(strdst, dst);

	vector<int> result;

	search_nearElement2(src.eself_vec, dst.eself_vec, result);
	bool checkvalid;
	if(result_test(src.eself_vec, dst.eself_vec, result)) {
		checkvalid = true;
	}
	else {
		checkvalid = false;
	}
	CPPUNIT_ASSERT(checkvalid);
}

void tester_example::testmethod3(char* strsrc, char* strdst)
{
	geometry src;
	geometry dst;

	fin::fin_geo(strsrc, src);
	fin::fin_geo(strdst, dst);

	vector<int> result;

	search_nearElement3(src.eself_vec, dst.eself_vec, result, src.part_vec, dst.part_vec);
	bool checkvalid;
	if(result_test(src.eself_vec, dst.eself_vec, result)) {
		checkvalid = true;
	}
	else {
		checkvalid = false;
	}
	CPPUNIT_ASSERT(checkvalid);
}

void tester_example::testcase_01()
{
	testmethod1("testgeo/src_01.geo", "testgeo/src_01.geo");
}

void tester_example::testcase_02()
{
	testmethod1("testgeo/src_02.geo", "testgeo/src_02.geo");
}

void tester_example::testcase_03()
{
	testmethod1("testgeo/src_03.geo", "testgeo/src_03.geo");
}

void tester_example::testcase_04()
{
	testmethod1("testgeo/src_04.geo", "testgeo/src_04.geo");
}

void tester_example::testcase_05()
{
	testmethod1("testgeo/src_01.geo", "testgeo/dst_scaled_01.geo");
}

void tester_example::testcase_06()
{
	testmethod1("testgeo/src_02.geo", "testgeo/dst_scaled_02.geo");
}

void tester_example::testcase_07()
{
	testmethod1("testgeo/src_03.geo", "testgeo/dst_scaled_03.geo");
}

void tester_example::testcase_08()
{
	testmethod1("testgeo/src_04.geo", "testgeo/dst_scaled_04.geo");
}
void tester_example::testcase_09()
{
	testmethod2("testgeo/src_01.geo", "testgeo/src_01.geo");
}

void tester_example::testcase_10()
{
	testmethod2("testgeo/src_02.geo", "testgeo/src_02.geo");
}

void tester_example::testcase_11()
{
	testmethod2("testgeo/src_03.geo", "testgeo/src_03.geo");
}

void tester_example::testcase_12()
{
	testmethod2("testgeo/src_04.geo", "testgeo/src_04.geo");
}

void tester_example::testcase_13()
{
	testmethod2("testgeo/src_01.geo", "testgeo/dst_scaled_01.geo");
}

void tester_example::testcase_14()
{
	testmethod2("testgeo/src_02.geo", "testgeo/dst_scaled_02.geo");
}

void tester_example::testcase_15()
{
	testmethod2("testgeo/src_03.geo", "testgeo/dst_scaled_03.geo");
}

void tester_example::testcase_16()
{
	testmethod2("testgeo/src_04.geo", "testgeo/dst_scaled_04.geo");
}

void tester_example::testcase_17()
{
	testmethod3("testgeo/src_01.geo", "testgeo/src_01.geo");
}

void tester_example::testcase_18()
{
	testmethod3("testgeo/src_02.geo", "testgeo/src_02.geo");
}

void tester_example::testcase_19()
{
	testmethod3("testgeo/src_03.geo", "testgeo/src_03.geo");
}

void tester_example::testcase_20()
{
	testmethod3("testgeo/src_04.geo", "testgeo/src_04.geo");
}

void tester_example::testcase_21()
{
	testmethod3("testgeo/src_01.geo", "testgeo/dst_scaled_01.geo");
}

void tester_example::testcase_22()
{
	testmethod3("testgeo/src_02.geo", "testgeo/dst_scaled_02.geo");
}

void tester_example::testcase_23()
{
	testmethod3("testgeo/src_03.geo", "testgeo/dst_scaled_03.geo");
}

void tester_example::testcase_24()
{
	testmethod3("testgeo/src_04.geo", "testgeo/dst_scaled_04.geo");
}