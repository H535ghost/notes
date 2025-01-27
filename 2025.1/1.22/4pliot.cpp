#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 99999999
int main() {
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    // dp[i][j][k] 表示使用前 i 种化学品，生成 j 克 A 和 k 克 B 所需的最小金额
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(401, vector<int>(401, INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= 400; ++j) {
            for (int k = 0; k <= 400; ++k) {
                if (dp[i][j][k] != INF) {
                    // 不购买第 i 种化学品
                    dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
                    // 购买第 i 种化学品
                    if (j + a[i] <= 400 && k + b[i] <= 400) {
                        dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
                    }
                }
            }
        }
    }

    int result = INF;
    for (int j = 1; j <= 400; ++j) {
        for (int k = 1; k <= 400; ++k) {
            if (j * Mb == k * Ma) {
                result = min(result, dp[N][j][k]);
            }
        }
    }

    if (result == INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}