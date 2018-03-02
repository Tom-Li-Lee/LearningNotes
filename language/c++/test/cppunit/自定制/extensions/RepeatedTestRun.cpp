/*
 * CppUnitTestSuiteDecorator.cpp
 *
 *  Created on: 2011-6-1
 *      Author: ThinkPad
 */

#include "RepeatedTestRun.h"
CPPUNIT_NS_BEGIN

RepeatedTestRun::RepeatedTestRun(Test* ptr,  int times, bool run):RepeatedTest(ptr,times) {
	this -> is_run = run;
}

RepeatedTestRun::~RepeatedTestRun() {
}


void RepeatedTestRun::setRun(bool run)
{
	this->is_run = run;
}

void RepeatedTestRun::run(TestResult *result)
{
	if(this->m_test == NULL || !this -> is_run)
		return;
	RepeatedTest::run(result);
}

CPPUNIT_NS_END
