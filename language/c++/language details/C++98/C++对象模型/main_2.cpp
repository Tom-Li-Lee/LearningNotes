/*
 * main.cpp
 *
 *  Created on: 2010-12-27
 *      Author: tli
 */

#include <iostream>
#include <stdio.h>
using namespace std;
class point
{
public:
	point() { cout << "The default ctor of point is called\n";}
	point (int data):data3(data) { cout << "The ctor of point with 1 parameter is called\n"; }
	point(const point& p) { cout << "The copy ctor of point is called\n";}
	 virtual ~point() {cout << "The dtor of point is called\n";}
	point& operator = (const point& p) {data3 = p.data3; cout << "The copy assignment of point is called\n"; return *this;}
	void fun() {cout << "AA";}
	int data3;
};

class point2d : virtual public point
{
public:
	point2d() { cout << "The default ctor of point2d is called\n";}
	point2d(const point2d& p) { cout << "The copy ctor of point2d is called\n";}
	 ~point2d() {cout << "The dtor of point2d is called\n";}
	point2d& operator = (const point2d& p) { point::operator =(p); cout << "The copy assignment of point2d is called\n"; return *this;}
	//int data;
};



class CException
{
    public:
    CException() { printf("%s, %p\n", "Default Ctor is called", this);}
    CException(const CException& a) { printf("%s, %p, %p\n", "Default Copy Ctor is called", &a, this); }
    virtual ~CException() { printf("%s, %p\n", "Default Dtor is called", this);}
};

class A : public CException, public point
{
public:
	A() { cout << "The default ctor of A is called\n";}
	virtual void fun() {cout << "virtual funtion of A\n";}
};



/*void fun( point& ptr)
{
	point2d& p = dynamic_cast< point2d&>(ptr);
	cout << "fun is called\n";
}

*/




class Pure
{
	virtual void fun()=0;
};
class Pure2 :public Pure
{
	virtual void fun2()=0;
};
class C : public Pure2
{
public:
	void fun() {}
	void fun2() {}
};


int main()
{
	//A a;


	point* ptr = new point2d();
	point2d* p = dynamic_cast<point2d*>(ptr);
    p->data3 = 10;
    ptr->fun();
	printf("%p, %p\n", ptr, p);



	//ptr->~point();
	//delete [] ptr;
	// fun(*ptr);
	 delete ptr;
}
