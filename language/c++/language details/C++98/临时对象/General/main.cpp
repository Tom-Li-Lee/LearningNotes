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
     Point () :_x(0){ cout << "Point ctor is called\n";}
     Point(int x):_x(x) {cout << "The ctor with 1 parameter is called\n";}
     Point(const Point& p) : _x(p._x) {cout << "Point copy ctor is called\n";}
     Point& operator = (const Point& p) { _x = p._x; cout << "Point copy assignment is called\n"; return *this; }
     Point& operator + (const Point& p) {_x += p._x; return *this;}
     virtual ~Point() {cout<<"Point dtor is called\n";}
     void setX(int x) {_x = x;}
     int getX() const {return _x;}
    protected:
     int _x;
};


int test (int  i)
{
	return i+1;
}
void fun2( Point p)
{
	cout << p.getX();
}

 Point fun(int i)
{
	return i;
}

class X {
        int i;
public:
        X(int I=0):i(I) {}
        void modify(){i++;}
};

X f5() {
        return X();
}

const X f6() {
        return X();
}

void f7(X& x) {
        x.modify();
}

int main() {
        f5() = X(1);
        f5().modify();
        int a = 9;
        Point p;
        (Point)a + p;
        return 0;
}





