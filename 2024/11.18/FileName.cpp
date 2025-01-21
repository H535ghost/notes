#include <tuple>
#include <iostream>
# include <string>
int main(int n, char** args)
{
    // 直接初始化：
    std::tuple<int, double, std::string> mtuple(1, 2.0, "3a");
    // 使用`std::make_tuple`函数进行初始化：
    auto mtuple2 = std::make_tuple(11, 22.0, "3aa");
    // 使用`std::tie`进行结构化绑定的初始化：
    int a;
    double b;
    std::string s;
    std::tie(a, b, s) = std::make_tuple(111, 222.0, "3aaa");
    // 使用`std::forward_as_tuple`进行创建和初始化：
    auto mtuple3 = std::forward_as_tuple(1111, 2222.0, "3aaaa");

    // 使用 `std::get` 函数按索引访问元素：
    std::cout << "使用 `std::get` 函数按索引访问元素：" << std::endl;
    int oa = std::get<0>(mtuple);
    double ob = std::get<1>(mtuple);
    std::string os = std::get<2>(mtuple);
    std::cout << "oa=" << oa << ",ob=" << ob << ",os=" << os << std::endl;

    std::cout << "使用 std::tie 进行结构化绑定，将 tuple 成员绑定到指定的变量：" << std::endl;
    std::cout << "a=" << a << ",b=" << b << ",s=" << s << std::endl;

    std::cout << "使用结构化绑定（C++17）：" << std::endl;
    // 注意，std::forward_as_tuple的初始化方式是无法使用结构化绑定访问元素的。
    auto [intVal, doubleVal, strVal] = mtuple2;
    std::cout << "intVal=" << intVal << ",doubleVal=" << doubleVal << ",strVal=" << strVal << std::endl;

    return 0;
}
