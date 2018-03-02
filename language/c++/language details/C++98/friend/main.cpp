/*
 * main.cpp
 *
 *  Created on: 2010-12-30
 *      Author: tli
 */
#include <iostream>


class Point2d
{
public:
	Point2d():_x(0),_y(0){}
	friend bool compare(const Point2d& a, const Point2d &b);
protected:
	int _x,_y;
};

class Point3d:public Point2d
{
public:
	Point3d():_z(0){}
	friend bool compare(const Point3d& a, const Point3d &b);
protected:
	int _z;
};
class Point4d:public Point3d
{
public:
	Point4d():_w(0){}
	friend bool compare(const Point4d& a, const Point4d &b);
protected:
	int _w;
};
bool compare(const Point2d& a, const Point2d &b)
{
	int sum1 = a._x + a._y;
	int sum2 = b._x + b._y;
	return sum1<sum2;
}
bool compare(const Point3d& a, const Point3d &b)
{
	int sum1 = a._x + a._y + a._z;
	int sum2 = b._x + b._y + b._z;
	return sum1<sum2;
}
bool compare(const Point4d& a, const Point4d &b)
{
	int sum1 = a._x + a._y + a._z + a._w;
	int sum2 = b._x + b._y + b._z + b._w;
	return sum1<sum2;
}
int main()
{

}
