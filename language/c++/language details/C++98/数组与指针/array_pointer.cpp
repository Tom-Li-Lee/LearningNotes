/* The following code example is taken from the book
 * "C++ Templates - The Complete Guide"
 * by David Vandevoorde and Nicolai M. Josuttis, Addison-Wesley, 2002
 *
 * (C) Copyright David Vandevoorde and Nicolai M. Josuttis 2002.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <typeinfo>
#include <iostream>
#include <stdio.h>
using std::cout;
class Point
{
    public:
     Point ():_x(0) { cout << "Point ctor is called\n";}
     Point(int x):_x(x) {cout << "The ctor with 1 parameter is called\n";}
     Point(const Point& p) : _x(p._x) {cout << "Point copy ctor is called\n";}
     Point& operator = (const Point& p) { _x = p._x; cout << "Point copy assignment is called\n"; return *this; }
     virtual ~Point() {cout<<"Point dtor is called\n";}
     int _x;
};

struct Line
{
	Point a[5];
	Line() { cout << "Line ctor is called\n";}
	Line(const Line& p):a(p.a){cout << "Line copy ctor is called\n";}
	//Line& operator = (const Line& cp) {a = cp.a; cout << "Line assignment operator is called\n";return *this;}
};

void print_array (int (*ar)[3][4])
{

}
/*
int main()
{
	int a3[2][3][4];
	int a2[3][4];
	int (*pa2)[3][4];
	pa2 = a3;
	pa2 = &a3[0];
	pa2 = &a3[1];
	print_array(a3);
	print_array(pa2);
	Line l;
	Line ll ;
	ll = l;
}
*/


template <typename T>
void ref (T const& x)
{
    std::cout << "x in ref(T const&): "  
              << typeid(x).name() << '\n';
   // x[0] = 8;  // Can't modify, const
}

template <typename T>
void nonref (T x)
{
    std::cout << "x in nonref(T):     "
              << typeid(x).name() << '\n';
    x[0] = 8;
}

int main()
{

	int ar[5] = {1,2,3,4,5};
    ref(ar);
    nonref(ar);
    std::cout << ar[0];
}

/*
void ref (int (&x)[5])
{
	std::cout << "x in nonref(T):     "
	              << typeid(x).name() << '\n';
	std::cout << sizeof(x) << '\n';
}

void nonref (int x[])
{
    std::cout << "x in ref(T const&): "
              << typeid(x).name() << '\n';
	std::cout << sizeof(x) << '\n';
}*/




