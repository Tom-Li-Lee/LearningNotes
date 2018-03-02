/*
 * MyTest.h
 *
 *  Created on: 2011-6-1
 *      Author: tomli
 */

#ifndef MYTEST_H_
#define MYTEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacrosCustomized.h>
#include <stdexcept>

class MyTest : public CPPUNIT_NS::TestFixture {
public:
	MyTest();
	void equalZero();
	void throwException();
	void setUp() {}
	void tearDown() {}

	~MyTest();

	MAKE_SUITE_BEGAIN(MyTest)
	CPPUNIT_TEST_ONCE(equalZero,true)
	REAPTED_CPPUNIT_TEST_EXCEPTION(throwException,std::invalid_argument,3,true)
	MAKE_SUITE_END
};

class MyTestSub : public MyTest
{
	MAKE_SUITE_SUB_BEGAIN(MyTest,MyTestSub)
	CPPUNIT_TEST_EXCEPTION_ONCE(notequalZero,CPPUNIT_NS::Exception,true)
	MAKE_SUITE_END
public:
	MyTestSub() {}
	void notequalZero() {throw CPPUNIT_NS::Exception();}
	~MyTestSub() {}
};

#endif /* MYTEST_H_ */
