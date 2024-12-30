#include <iostream>
using namespace std;

int main() {
    long long n, a, b;
    cin >> n;  // 读取测试用例的数量

    for (long long test = 0; test < n; test++) {
        cin >> a >> b;  // 分别读取集合A和集合B的大小

        long long sumA = 0, prodB = 1, x;
        
        // 计算集合A的元素总和
        for (long long i = 0; i < a; i++) {
            cin >> x;
            sumA += x;
        }

        // 计算集合B的元素乘积
        for (long long i = 0; i < b; i++) {
            cin >> x;
            prodB *= x;
        }

        // 判断是否相等
        if (sumA == prodB) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
