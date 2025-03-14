#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

vector<int> children[MAXN]; // 存储树的子节点
ll a[MAXN], b[MAXN];       // 动态规划数组
ll pow2[MAXN];             // 预计算 2 的幂次

// 快速幂函数，计算 base^exponent % mod
ll fast_pow(ll base, ll exponent, ll mod) {
    ll result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

// 深度优先搜索，动态规划计算 a[u] 和 b[u]
void dfs(int u) {
    a[u] = 1; // 选中当前节点 u 的弹珠
    b[u] = 1; // 总配置数（选中或不选中）
    for (int v : children[u]) {
        dfs(v); // 递归处理子节点
        a[u] = a[u] * (a[v] + b[v]) % MOD; // 更新 a[u]
        b[u] = b[u] * (a[v] + b[v]) % MOD; // 更新 b[u]
    }
    // 计算 a[u] 的修正值
    ll product = 1;
    for (int v : children[u]) {
        product = product * b[v] % MOD;
    }
    a[u] = 0;
    for (int v : children[u]) {
        ll term = a[v] * product % MOD;
        term = term * fast_pow(b[v], MOD - 2, MOD) % MOD; // 乘以 b[v] 的逆元
        a[u] = (a[u] + term) % MOD;
    }
    // 考虑选中当前节点 u 的弹珠
    ll select_u = 1;
    for (int v : children[u]) {
        select_u = select_u * b[v] % MOD;
    }
    a[u] = (a[u] + select_u) % MOD;
    // 更新 b[u]
    b[u] = (pow2[children[u].size()] - a[u] + MOD) % MOD;
}

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
        children[p[i]].push_back(i + 1); // 构建树结构
    }

    // 预计算 2 的幂次
    pow2[0] = 1;
    for (int i = 1; i <= N + 1; ++i) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }

    // 从根节点开始动态规划
    dfs(0);

    // 最终答案是根节点的 a[0] 乘以 2^{叶子节点数}
    // 因为每个叶子节点可以选择放或不放弹珠
    int leaf_count = 0;
    for (int i = 0; i <= N; ++i) {
        if (children[i].empty()) {
            leaf_count++;
        }
    }
    ll answer = a[0] * fast_pow(2, leaf_count, MOD) % MOD;
    cout << answer << endl;

    return 0;
}