#include <iostream>
using namespace std;

class Solution {
public:
    int smallestValue(int n) {
        int ans = n, k = n;
        while (true) {
            int original = n;  // 保存原始值
            ans = 0;
            for (int i = 2; i <= n; i++) {
                while (n % i == 0) {
                    n = n / i;
                    ans += i;
                }
            }
            // 如果在一次循环中没有任何变化，则说明已经是质数或者已经没有分解的可能
            if (n == 1) break;
            if (ans == original) break;  // 如果没有任何更新，退出循环
        }
        return ans;
    }
};

Solution a;

int main() {
    int n;
    cin >> n;
    cout << a.smallestValue(n) << endl;
    return 0;
}

