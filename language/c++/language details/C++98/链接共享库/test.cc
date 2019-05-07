#include <iostream>
#include <string>

using namespace std;

class Reg
{
public:
static const string& get_reg_name();
};

const string& Reg::get_reg_name() 
{
	static string s_reg("Reg");
	cout << "The string address is " << &s_reg << '\n';
	return s_reg;
} 


void fun()  
{
	cout << "fun!\n";
}

void output_reg_name()
{
	fun(); // plt， 留给链接时决定
	cout << Reg::get_reg_name(); // plt，留给链接时决定
}

// -fPIC: 动态链接库中引用名字，无论它在当前动态链接库中是否定义，都是plt/got。
