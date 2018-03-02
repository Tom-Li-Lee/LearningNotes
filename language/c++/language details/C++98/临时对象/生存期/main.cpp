/*
 * main.cpp
 *
 *  Created on: 2010-12-28
 *      Author: TomLi
 */
#include <iostream>
using namespace std;
class Point
{
    public:
     Point ():_x(0) { cout << "Point ctor is called\n";}
     Point(int x):_x(x) {cout << "The ctor with 1 parameter is called\n";}
     Point(const Point& p) : _x(p._x) {cout << "Point copy ctor is called\n";}
     Point& operator = (const Point& p) { _x = p._x; cout << "Point copy assignment is called\n"; return *this; }
     virtual ~Point() {cout<<"Point dtor is called\n";}
     int getX()const  {return _x;}

private:
     int _x;
};
Point fun()
{
	return 5;
}

void fun2(const Point p)
{
	cout << p.getX();
}
class pointref
{
public:
	pointref(const Point& p):ref(p){cout << "pointref ctor is called here\n";}
	void print_point() {cout << ref.getX();}
private:
	const Point& ref;
};
int main()
{
/*	pointref p1(4);
	// 临时对象在这里就被摧毁了，因为上面那个表达式已经求值完毕了
	cout << "Seperator-----\n";
	p1.print_point();*/

	Point p2 = 3;
	p2 = fun();
	cout << "Seperator-----\n";


/*
 * fun2(3);
	cout << "Seperator-----\n";
*/
}
