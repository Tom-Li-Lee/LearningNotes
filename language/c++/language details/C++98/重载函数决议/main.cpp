#include <iostream>
namespace LDQ_TEST
{
 //����ģ�嶨��
 template< typename T >
 T sum( T, int );

 //T == double����ʽ�ػ�
 template<> double sum< double >( double, int );

 //��ͨ����ģ�壩����
 double sum( double, double );
 template< typename T >
 T sum( T t )
 {
  std::cout <<"���ú���ģ��" <<std::endl;
  return t;
 }

 template<>
 double sum<double>( double dval )
 {
  std::cout <<"����ģ���ػ�����" <<std::endl;
  return dval;
 }

 double sum( double dval1 )
 {
  std::cout <<"������ͨ����" <<std::endl;
  return dval1;
 }

}

template< typename T >
T LDQ_TEST::sum( T t, int ival )
{
 std::cout <<"���ú���ģ��" <<std::endl;
 return t;
}

template<>
double
LDQ_TEST::sum<double>( double dval, int ival )
{
 std::cout <<"����ģ���ػ�����" <<std::endl;
 return dval;
}

double
LDQ_TEST::sum( double dval1, double dval2 )
{
 std::cout <<"������ͨ����" <<std::endl;
 return dval1;
}


/*


*/

int main()
{
double dval = 3;

LDQ_TEST::sum( dval );  //������ͨ����

double dvals = 3;
int  ival = 2;

LDQ_TEST::sum( dvals, ival );  //����ģ���ػ�����
LDQ_TEST::sum( dvals, dval );  //������ͨ����
LDQ_TEST::sum( ival, ival );  //���ú���ģ��
}
