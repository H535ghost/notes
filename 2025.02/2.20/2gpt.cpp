#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(const vector<vector<long long>>& p, const vector<vector<long long>>& q, long long m, long long n, int ans, const vector<long long>& a, const vector<long long>& b) {
    int k = ans;
    // 遍历树p的邻接节点
    for (long long i : p[m]) {
        // 遍历树q的邻接节点
        for (long long j : q[n]) {
            if (a[i] == b[j] && i != m && j != n) {
                // 如果权值相等且不是同一节点，递归计算最长公共前缀
                ans = max(ans, dfs(p, q, i, j, k + 1, a, b));
            }
        }
    }
    return ans;
}

int main() {
    long long n, m, x, y;
    cin >> n >> m;
    
    // 输入两棵树的权值
    vector<long long> a(m + 1, 0), b(n + 1, 0);  // a 和 b 是从1开始
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int j = 1; j <= n; j++) {
        cin >> b[j];
    }

    // 初始化树的邻接表
    vector<vector<long long>> p(m + 1), q(n + 1);

    // 输入树p的边
    for (int i = 0; i < m - 1; i++) {
        cin >> x >> y;
        p[x].push_back(y);
        p[y].push_back(x);
    }

    // 输入树q的边
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        q[x].push_back(y);
        q[y].push_back(x);
    }

    // 从根结点1开始递归计算两棵树的最长公共前缀路径
    cout << dfs(p, q, 1, 1, 0, a, b) << endl;

    return 0;
}
