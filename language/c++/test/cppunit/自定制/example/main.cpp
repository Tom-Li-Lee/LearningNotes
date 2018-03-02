/*
 * main.cpp
 *
 *  Created on: 2011-6-1
 *      Author: tomli
 */
#include "MyTest.h"
#include <cppunit/ui/text/TextTestRunner.h>
int main()
{

	CppUnit::TextTestRunner t;

	t.addTest(MyTestSub::suite());

	// Start the whole Test run.
	t.run();
}
