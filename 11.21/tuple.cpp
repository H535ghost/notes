#include <iostream>
#include <tuple>
#include <string>

int main() {
    int x = 10;
    double y = 20.5;
    std::string z = "hello";

    // 使用 std::make_tuple
    auto t1 = std::make_tuple(x, y, z);
    std::cout << std::get<0>(t1) << ", " << std::get<1>(t1) << ", " << std::get<2>(t1) << std::endl;
    // 输出: 10, 20.5, hello
    // t1 中的元素是 x, y, z 的副本

    // 使用 std::forward_as_tuple
    auto t2 = std::forward_as_tuple(x, y, z);
    std::cout << std::get<0>(t2) << ", " << std::get<1>(t2) << ", " << std::get<2>(t2) << std::endl;
    // 输出: 10, 20.5, hello
    // t2 中的元素是 x, y, z 的引用

    // 修改原始变量
    x = 100;
    y = 200.5;
    z = "world";

    // 再次输出 t1 和 t2
    std::cout << "After modification:" << std::endl;
    std::cout << std::get<0>(t1) << ", " << std::get<1>(t1) << ", " << std::get<2>(t1) << std::endl;
    // 输出: 10, 20.5, hello
    // t1 未受影响，因为它包含的是副本

    std::cout << std::get<0>(t2) << ", " << std::get<1>(t2) << ", " << std::get<2>(t2) << std::endl;
    // 输出: 100, 200.5, world
    // t2 受影响，因为它包含的是引用

    return 0;
}