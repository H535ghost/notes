#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MOD = 1e9 + 7;

// 获取N的所有因子并排序
vector<int> getFactors(int N) {
    vector<int> factors;
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            factors.push_back(i);
            if (i != N / i) factors.push_back(N / i);
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}

int countSequences(int N, int K) {
    vector<int> factors = getFactors(N);
    int m = factors.size(); // 因子个数
    vector<vector<int>> dp(K, vector<int>(m, 0));

    // 初始化：长度为1的序列，每个因子单独作为一个序列
    for (int j = 0; j < m; ++j) dp[0][j] = 1;

    // 计算dp
    for (int i = 1; i < K; ++i) {
        vector<int> prefix_sum(m, 0);
        prefix_sum[0] = dp[i - 1][0];

        // 计算前缀和
        for (int j = 1; j < m; ++j) {
            prefix_sum[j] = (prefix_sum[j - 1] + dp[i - 1][j]) % MOD;
        }

        // 计算dp[i][j]
        for (int j = 0; j < m; ++j) {
            // 找到最大的 k，使得 factors[k] * factors[j] <= N
            int limit = N / factors[j];  // 最大允许的前一个元素
            int idx = upper_bound(factors.begin(), factors.end(), limit) - factors.begin() - 1;
            dp[i][j] = prefix_sum[idx]; // 从符合条件的前缀和中累加
        }
    }

    // 计算最终答案
    int result = 0;
    for (int j = 0; j < m; ++j) {
        result = (result + dp[K - 1][j]) % MOD;
    }
    
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << countSequences(N, K) << endl;
    return 0;
}
