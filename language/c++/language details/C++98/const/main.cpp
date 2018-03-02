/*
 * main.cpp
 *
 *  Created on: 2011-2-21
 *      Author: tli
 */
#include <iostream>
#include <stdio.h>
#include <bits/stl_tree.h>
#include <bits/stl_map.h>
using std::cout;

class Point2d
{
    public:
     Point2d ():_x(0),_y(0) { cout << "Point2d ctor is called\n";}
     Point2d(int x, int y):_x(x),_y(y) {cout << "The Point2d ctor with 2 parameter is called\n";}
     int getX() const { cout << "Point2d getX const is called\n"; return _x;}
     int getX()  { cout << "Point2d getX  is called\n"; return _x;}
    protected:
     int _x, _y;
};
class Line
{
public:
	Line():p() {}
	int GetX() const {return p.getX();}
	int GetX()  {return p.getX();}
private:
	Point2d p;
};

int main()
{
	Line a;
	a.GetX();
}