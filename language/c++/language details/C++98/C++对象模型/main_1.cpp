/*
 * main.cpp
 *
 *  Created on: 2010-12-24
 *      Author: tli
 */
#include <iostream>
#include <stdio.h>
using namespace std;



class point
{
public:
	point() { cout << "The default ctor of point is called\n";}
	point(const point& p) { cout << "The copy ctor of point is called\n";}
	virtual ~point() {cout << "The dtor of point is called\n";}
	point& operator = (const point& p) {data3 = p.data3; cout << "The copy assignment of point is called\n"; return *this;}
	int data3;
};

class CException : virtual public point
{
    public:
    CException() { printf("%s, %p\n", "Default Ctor is called", this);}
    CException(const CException& a) { printf("%s, %p, %p\n", "Default Copy Ctor is called", &a, this); }
    ~CException() { printf("%s, %p\n", "Default Dtor is called", this);}
    CException& operator = (const CException& p) {point::operator =(p); data = p.data; cout << "The copy assignment of CException is called\n"; return *this;}
    int data;
};
class point3d :  public CException
{
public:
	point3d() {cout << "The default ctor of point3d is called\n";}
	point3d(const point3d& p) { cout << "The copy ctor of point3d is called\n";}
	virtual ~point3d() {cout << "The dtor of point3d is called\n";}
	point3d& operator = (const point3d& p)  {CException::operator =(p); data2 =p.data2; cout << "The copy assignment of point3d is called\n"; return *this;}
    int data2;
};
int main()
{

	point3d a;
	a.data = 10 ;
	a.data3 = 50;
	a.data2= 100;
	printf("%d, %d, %d\n", *((int*)&a+1), *((int*)&a+2),*((int*)&a+4));
	point3d b;
	b = a;
	printf("%d, %d, %d\n", *((int*)&b+1), *((int*)&b+2),*((int*)&b+4));
	return 0;
}
