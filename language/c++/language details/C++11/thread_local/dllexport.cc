#include <iostream>

struct Point
{
int x, y;
Point() {std::cout << this << " Point ctor is called.\n";}
~Point() {std::cout << this << " Point dtor is called.\n";}
};

static thread_local Point x;
thread_local int error_no = 1;

Point g;

extern "C"
{
	int* get_local_error_no() { return &error_no; }
	void set_local_error_no(int value) { error_no = value; }
	Point* get_local_point() { return &x;}
}
