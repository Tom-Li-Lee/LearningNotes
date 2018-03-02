#include <iostream>
namespace LDQ_TEST
{
 //函数模板定义
 template< typename T >
 T sum( T, int );

 //T == double的显式特化
 template<> double sum< double >( double, int );

 //普通（非模板）函数
 double sum( double, double );
 template< typename T >
 T sum( T t )
 {
  std::cout <<"调用函数模板" <<std::endl;
  return t;
 }

 template<>
 double sum<double>( double dval )
 {
  std::cout <<"调用模板特化函数" <<std::endl;
  return dval;
 }

 double sum( double dval1 )
 {
  std::cout <<"调用普通函数" <<std::endl;
  return dval1;
 }

}

template< typename T >
T LDQ_TEST::sum( T t, int ival )
{
 std::cout <<"调用函数模板" <<std::endl;
 return t;
}

template<>
double
LDQ_TEST::sum<double>( double dval, int ival )
{
 std::cout <<"调用模板特化函数" <<std::endl;
 return dval;
}

double
LDQ_TEST::sum( double dval1, double dval2 )
{
 std::cout <<"调用普通函数" <<std::endl;
 return dval1;
}


/*


*/

int main()
{
double dval = 3;

LDQ_TEST::sum( dval );  //调用普通函数

double dvals = 3;
int  ival = 2;

LDQ_TEST::sum( dvals, ival );  //调用模板特化函数
LDQ_TEST::sum( dvals, dval );  //调用普通函数
LDQ_TEST::sum( ival, ival );  //调用函数模板
}
