#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
vector<int> G[MAXN];
int in[MAXN], out[MAXN];

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    
    // 读取边并构建邻接表
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    // 非递归DFS计算in和out时间
    stack<tuple<int, int, bool>> st; // (节点, 父节点, 是否已访问)
    st.emplace(1, -1, false);
    int time = 0;
    
    while (!st.empty()) {
        auto [u, p, visited] = st.top();
        st.pop();
        
        if (!visited) {
            in[u] = ++time;
            // 重新压入栈，标记为已访问
            st.emplace(u, p, true);
            // 收集子节点（排除父节点） 
            vector<int> children;
            for (int v : G[u]) {
                if (v != p) {
                    children.push_back(v);
                }
            }
            // 逆序压栈以保证处理顺序正确
            reverse(children.begin(), children.end());
            for (int v : children) {
                st.emplace(v, u, false);
            }
        } else {
            out[u] = time;
        }
    }
    
    // 处理操作并更新差分数组
    vector<long long> diff(N + 2, 0);
    for (int q = 0; q < Q; ++q) {
        int p, x;
        scanf("%d %d", &p, &x);
        int l = in[p];
        int r = out[p];
        diff[l] += x;
        if (r + 1 <= N) {
            diff[r + 1] -= x;
        }
    }
    
    // 计算前缀和得到每个in-time位置的总值
    vector<long long> sum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        sum[i] = sum[i - 1] + diff[i];
    }
    
    // 输出每个节点的结果
    for (int u = 1; u <= N; ++u) {
        printf("%lld%c", sum[in[u]], " \n"[u == N]);
    }
    
    return 0;
}