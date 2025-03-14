#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    long long prefix_sum = 1;

    for (int i = 1; i <= n; ++i) {
        dp[i] += prefix_sum;
        prefix_sum = (prefix_sum + dp[i]) % MOD;
        if (i >= n) {
            prefix_sum = (prefix_sum - dp[i - n] + MOD) % MOD;
        }
        
    }

    cout << dp[n] << endl;

    return 0;
}