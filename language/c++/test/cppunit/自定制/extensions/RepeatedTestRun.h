/*
 * CppUnitTestDecorator.h
 *
 *  Created on: 2011-6-1
 *      Author: ThinkPad
 */

#ifndef CppUnitTestSuiteDecorator_H_
#define CppUnitTestSuiteDecorator_H_

#include <cppunit/extensions/RepeatedTest.h>

CPPUNIT_NS_BEGIN


class TestResult;
class Test;

class RepeatedTestRun: public RepeatedTest {
public:
	~RepeatedTestRun();
	RepeatedTestRun(Test* ptr,  int times = 1, bool run = true);
	void run( TestResult *result );
	void setRun(bool run);
private:
	bool is_run;
};

CPPUNIT_NS_END
#endif /* CppUnitTestDecorator_H_ */
