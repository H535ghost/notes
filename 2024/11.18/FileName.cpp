#include <tuple>
#include <iostream>
# include <string>
int main(int n, char** args)
{
    // ֱ�ӳ�ʼ����
    std::tuple<int, double, std::string> mtuple(1, 2.0, "3a");
    // ʹ��`std::make_tuple`�������г�ʼ����
    auto mtuple2 = std::make_tuple(11, 22.0, "3aa");
    // ʹ��`std::tie`���нṹ���󶨵ĳ�ʼ����
    int a;
    double b;
    std::string s;
    std::tie(a, b, s) = std::make_tuple(111, 222.0, "3aaa");
    // ʹ��`std::forward_as_tuple`���д����ͳ�ʼ����
    auto mtuple3 = std::forward_as_tuple(1111, 2222.0, "3aaaa");

    // ʹ�� `std::get` ��������������Ԫ�أ�
    std::cout << "ʹ�� `std::get` ��������������Ԫ�أ�" << std::endl;
    int oa = std::get<0>(mtuple);
    double ob = std::get<1>(mtuple);
    std::string os = std::get<2>(mtuple);
    std::cout << "oa=" << oa << ",ob=" << ob << ",os=" << os << std::endl;

    std::cout << "ʹ�� std::tie ���нṹ���󶨣��� tuple ��Ա�󶨵�ָ���ı�����" << std::endl;
    std::cout << "a=" << a << ",b=" << b << ",s=" << s << std::endl;

    std::cout << "ʹ�ýṹ���󶨣�C++17����" << std::endl;
    // ע�⣬std::forward_as_tuple�ĳ�ʼ����ʽ���޷�ʹ�ýṹ���󶨷���Ԫ�صġ�
    auto [intVal, doubleVal, strVal] = mtuple2;
    std::cout << "intVal=" << intVal << ",doubleVal=" << doubleVal << ",strVal=" << strVal << std::endl;

    return 0;
}
