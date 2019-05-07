#include <iostream>
#include <string>

using namespace std;

class Reg
{
public:
static const string& get_reg_name()
{
	static string s_reg("Reg");
	cout << "The string address is " << &s_reg << '\n';
	return s_reg;
} 
};

void output_reg_name(); // plt，因为当前可执行单元中没有它的定义，需要链接时做决定

int main()
{
	output_reg_name();
	cout << Reg::get_reg_name();
}

// 可执行单元中引用名字，如果该名字在当前可执行单元中没有定义，则是plt/got。
