#include <iostream>
using namespace std;

#define int long long
const int MOD = 1000000007;

long long dfs(int a, int b, int m, int n, int x, int y) {
    if (x >= m - a + 1 && y <= b) {
        return 0;
    }
    if (x == m && y == n) {
        return 1;
    }

    long long ans = 0;
    if (x < m) {
        ans = (ans + dfs(a, b, m, n, x + 1, y)) % MOD;
    }
    if (y < n) {
        ans = (ans + dfs(a, b, m, n, x, y + 1)) % MOD;
    }

    return ans;
}
int main()

 {
    int m, n, a, b;
    cin >> m >> n >> a >> b;

    cout << dfs(a, b, m, n, 1, 1) << endl;

    return 0;
}
