/*
 * CppUnitUtility.h
 *
 *  Created on: 2011-6-1
 *      Author: tli
 */

#ifndef CPPUNITUTILITY_H_
#define CPPUNITUTILITY_H_

#include <string>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/extensions/RepeatedTestRun.h>
#include <cppunit/extensions/ExceptionTestCaseDecorator.h>

#define CPPUNIT_TEST_SUITE_ADD_TEST( test )  newsuite->addTest(test);

#define CPPUNIT_TEST_ONCE(MethodName,Run)  REAPTED_CPPUNIT_TEST(MethodName, 1, Run)

#define REAPTED_CPPUNIT_TEST(MethodName, Times, Run)  \
	CPPUNIT_TEST_SUITE_ADD_TEST(new CPPUNIT_NS::RepeatedTestRun( new CPPUNIT_NS::TestCaller<TestClassName> \
			(newsuite->getName()+"."+ #MethodName,&TestClassName::MethodName),Times, Run))

#define MAKE_SUITE_BEGAIN(CLASS_NAME)       \
private: \
	typedef CLASS_NAME TestClassName; \
public: \
	static CPPUNIT_NS::Test* suite() \
	{      \
	    CPPUNIT_NS::TestSuite* newsuite = new CPPUNIT_NS::TestSuite(#CLASS_NAME);


#define MAKE_SUITE_END  \
	return newsuite; \
	}

#define REAPTED_CPPUNIT_TEST_EXCEPTION(MethodName, ExceptionType, Times, Run) \
		CPPUNIT_TEST_SUITE_ADD_TEST( new CPPUNIT_NS::RepeatedTestRun( \
			new CPPUNIT_NS::ExceptionTestCaseDecorator<ExceptionType>( \
			new CPPUNIT_NS::TestCaller<TestClassName>(newsuite->getName()+"."+ #MethodName,&TestClassName::MethodName)), Times, Run ))


#define CPPUNIT_TEST_EXCEPTION_ONCE(MethodName,ExceptionType,Run) REAPTED_CPPUNIT_TEST_EXCEPTION(MethodName, ExceptionType, 1, Run)

#define MAKE_SUITE_SUB_BEGAIN(SuperClass, SubClass) \
		MAKE_SUITE_BEGAIN(SubClass) \
		CPPUNIT_TEST_SUITE_ADD_TEST(SuperClass::suite())



#endif /* CPPUNITUTILITY_H_ */
