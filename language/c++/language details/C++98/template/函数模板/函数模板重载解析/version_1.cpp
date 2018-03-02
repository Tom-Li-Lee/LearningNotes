/*
 * main.cpp
 *
 *  Created on: 2010-12-30
 *      Author: tli
 */
#include <iostream>
#include <string.h>

class Point
{
public:
	Point() :_x(0){std::cout << "Default ctor is called\n";}
	Point(int x):_x(x) {}
	Point(const Point& p):_x(p._x) {std::cout << "Copy ctor is called\n";}
	bool operator < (const Point &p) const {return (_x < p._x);}
protected:
	int _x;
};


/**General template T*
 *
 */
template <typename T>
T* max(T* a, T* b)
{
	std::cout << "General template T* is called\n";
	return (*a)<(*b)?b:a;
}

/** General template const T&
 *
 */
template <typename T>
const T& max(const T& a,  const T& b)
{
	std::cout << "General template const T& is called\n";
	return (a<b)?b:a;
}

/** Specializtion version for general template T*
 *
 */
template <>
const char* max(const char* a, const char* b)
{
	std::cout << "Specialization template const char* is called\n";
	return (strcmp(a,b)>0)?a:b;
}

/** Specializtion version for general template T*
 *
 */
template <>
char* max(char* a, char* b)
{
	std::cout << "Specialization template char* is called\n";
	return (strcmp(a,b)>0)?a:b;
}
int main()
{
   char arr1[] = "LI";
   char arr2[] = "li";
   int a = 10, b = 5;
   max(1, 2);
   const int* p1 = &a;
   const int* p2 = &b;
   max(p1,p2);
   max(arr1,arr2);
   max("LI","li");
   Point a1(3),a2(4);
   max(a1,a2);
}
