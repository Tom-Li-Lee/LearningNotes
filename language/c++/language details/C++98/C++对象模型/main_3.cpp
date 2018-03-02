/*
 * main.cpp
 *
 *  Created on: 2011-2-21
 *      Author: tli
 */
#include <iostream>
#include <stdio.h>
using std::cout;

class Point2d
{
    public:
     Point2d ():_x(0),_y(0) { cout << "Point2d ctor is called\n";}
     Point2d(int x, int y):_x(x),_y(y) {cout << "The Point2d ctor with 2 parameter is called\n";}
     Point2d(const Point2d& p) : _x(p._x),_y(p._y) {cout << "Point2d copy ctor is called\n";}
     Point2d& operator = (const Point2d& p) { _x = p._x; _y = p._y; cout << "Point2d copy assignment is called\n"; return *this; }
     ~Point2d() {cout<<"Point2d dtor is called\n";}
    protected:
     int _x, _y;
};

class Point3d : public Point2d
{
public:
	Point3d():_z(0) { cout << "Point3d ctor is called\n";}
	Point3d(int x, int y, int z):Point2d(x,y),_z(z) {cout << "The Point3d ctor with 3 parameter is called\n";}
	virtual ~Point3d() {cout<<"Point3d dtor is called\n";}
protected:
	int _z;
};

int main()
{
	Point2d *ptr1 = new Point3d();
	Point3d *ptr2 = (Point3d*)ptr1;
	printf("%p, %p\n", ptr1, ptr2);
	delete ptr1;
}
