/*
 * main.cpp
 *
 *  Created on: 2010-12-23
 *      Author: tli
 */

#include <iostream>
#include <ostream>
#include <stdio.h>

enum weekday { MONDAY, THURSDAY, WEDDAY ,THIRDAY};
weekday& operator++ (weekday& s)
{
	switch (s) {
	case MONDAY: {
		s = THURSDAY;
		return s;
	}
	case THURSDAY : {
		s = WEDDAY;
		return s;
	}
	case WEDDAY : {
		s = THIRDAY;
		return s;
	}
	case THIRDAY : {
		s = MONDAY;
		return s;
	}
	}
}
weekday operator++ (weekday& s, int)
{
	weekday old_value;
	switch (s) {
	case MONDAY: {
		old_value = s;
		s = THURSDAY;
		return old_value;
	}
	case THURSDAY : {
		old_value = s;
		s = WEDDAY;
		return old_value;
	}
	case WEDDAY : {
		old_value = s;
		s = THIRDAY;
		return old_value;
	}
	case THIRDAY : {
		old_value = s;
		s = MONDAY;
		return old_value;
	}
	}
}

int main()
{
	weekday today = THURSDAY;
	weekday tommorrow = ++today;
	switch (tommorrow){
	case WEDDAY: {
	  std::cout << "It is right!\n";
	}
	}
	
	return 0;
}

