#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int main() {
    int m, n;
    cin >> m >> n;

    vector<long long> a(m), b(n);
    for (int i = 0; i < m; ++i) cin >> a[i];
    for (int j = 0; j < n; ++j) cin >> b[j];

    // 排序
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // 计算 sum_x
    long long sum_x = 0;
    for (int i = 1; i < m; ++i) {
        long long diff = (a[i] - a[i - 1]) % MOD;
        long long cnt = (long long)i * (m - i) % MOD;
        sum_x = (sum_x + diff * cnt) % MOD;
    }

    // 计算 sum_y
    long long sum_y = 0;
    for (int j = 1; j < n; ++j) {
        long long diff = (b[j] - b[j - 1]) % MOD;
        long long cnt = (long long)j * (n - j) % MOD;
        sum_y = (sum_y + diff * cnt) % MOD;
    }

    // 计算总面积并取模
    long long total_area = (sum_x * sum_y) % MOD;
    cout << total_area << endl;

    return 0;
}