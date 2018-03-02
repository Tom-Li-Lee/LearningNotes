//It will be memory leak as below:
#include <iostream>
#include <stdio.h>
using namespace std;
class Base
{
    public:
     Base () {cout<<"Base ctor is called\n";}
     void* operator new (size_t s) { cout << "Base new is called\n"; return ::operator new(s);}
     void operator delete (void* p) { cout << "Base delete is called\n"; return ::operator delete(p);}
      virtual ~Base() {cout<<"Base dtor is called\n";}
     int _counter;
     int _float;
};
class Point
{
    public:
     Point () {cout<<"Point ctor is called\n";}
     virtual ~Point() {cout<<"Point dtor is called\n";}
     int _x;
     int _y;
};
class Derived : public Base, public Point
{
    public:
     Derived () {cout<<"Derived ctor is called\n";}
     //void* operator new (size_t s) { cout << "Derived new is called\n"; return ::operator new(s);}
     //void operator delete (void* p) { cout << "Derieved delete is called\n"; return ::operator delete(p);}
     virtual ~Derived() {cout<<"Derived dtor is called\n";}
     int more;
};
int main()
{
	Base * p = new Derived();
	delete p;

    // *ptr = p;
    /*p->_counter = 0;
    p->_float = 1;
    p->_x = 2;
    p->_y = 3;
    p->more = 4;
    printf("%d,%d,%d,%d,%d", *((int*)p+1),*((int*)p+2),*((int*)p+4),*((int*)p+5),*((int*)p+6));*/
  //  printf("%d,%d,%d", *((int*)p+1),*((int*)p+2),*((int*)p+3));
  //  printf("%p,%p, %d\n", p, ptr, *((int*)(p)-1));

}
