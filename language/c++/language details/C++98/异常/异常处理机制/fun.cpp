#include <iostream>
#include <stdio.h>
using namespace std;
class CException
{
    public:
    CException() { printf("%s, %p\n", "Default Ctor is called", this);}
    CException(const CException& a) { printf("%s, %p, %p\n", "Default Copy Ctor is called", &a, this); }
    ~CException() { printf("%s, %p\n", "Default Dtor is called", this);}
};
void fun2()
{
    CException a, b;
    throw a;
    cout << "Never in here \n";
}
void fun3()
{
    CException a;
    try
    {
        fun2();
    }
    catch(CException p)
    {
         throw;
    }
    cout << "Never in here \n";
}
int main()
{
    try
    {
        fun3();
    }
    catch(CException &p)
    {
        cout << "Handled\n";
    }
    cout<<"Main is called finished\n";
}
