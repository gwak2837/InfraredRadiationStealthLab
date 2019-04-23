#pragma once
#include <cppunit/extensions/HelperMacros.h>

class tester_example : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(tester_example); // declares that out Fiture's test suite
	CPPUNIT_TEST(testcase_01); //테스트 함수 등록, adds a test to our test suite. The test is implemented by a method named testConstructor()
	CPPUNIT_TEST(testcase_02);
	CPPUNIT_TEST(testcase_03);
	CPPUNIT_TEST(testcase_04);
	CPPUNIT_TEST(testcase_05);
	CPPUNIT_TEST(testcase_06);
	CPPUNIT_TEST(testcase_07);
	CPPUNIT_TEST(testcase_08);
	CPPUNIT_TEST(testcase_09);
	CPPUNIT_TEST(testcase_10);
	CPPUNIT_TEST(testcase_11);
	CPPUNIT_TEST(testcase_12);
	CPPUNIT_TEST(testcase_13);
	CPPUNIT_TEST(testcase_14);
	CPPUNIT_TEST(testcase_15);
	CPPUNIT_TEST(testcase_16);
	CPPUNIT_TEST(testcase_17);
	CPPUNIT_TEST(testcase_18);
	CPPUNIT_TEST(testcase_19);
	CPPUNIT_TEST(testcase_20);
	CPPUNIT_TEST(testcase_21);
	CPPUNIT_TEST(testcase_22);
	CPPUNIT_TEST(testcase_23);
	CPPUNIT_TEST(testcase_24);
	CPPUNIT_TEST_SUITE_END();
public:
	tester_example(void);
	virtual ~tester_example(void);
	void setUp(); // setUp some fixture
	void tearDown(); // tearDown some fixture
public:
	void testmethod1(char* strsrc, char* strdst);
	void testmethod2(char* strsrc, char* strdst);
	void testmethod3(char* strsrc, char* strdst);
public:
	void testcase_01();//테스트 함수 정의
	void testcase_02();
	void testcase_03();
	void testcase_04();
	void testcase_05();
	void testcase_06();
	void testcase_07();
	void testcase_08();
	void testcase_09();
	void testcase_10();
	void testcase_11();
	void testcase_12();
	void testcase_13();
	void testcase_14();
	void testcase_15();
	void testcase_16();
	void testcase_17();
	void testcase_18();
	void testcase_19();
	void testcase_20();
	void testcase_21();
	void testcase_22();
	void testcase_23();
	void testcase_24();
};
