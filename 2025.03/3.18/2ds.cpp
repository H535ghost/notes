#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int p, q, c;
        cin >> p >> q >> c;
        adj[p].emplace_back(q, c);
        adj[q].emplace_back(p, c);
    }

    deque<tuple<int, int, int>> dq; // k, u, c_prev
    unordered_map<int, unordered_map<int, int>> dist;

    // 初始化起点1的所有可能公司
    for (const auto& edge : adj[1]) {
        int c = edge.second;
        if (!dist[1].count(c)) {
            dist[1][c] = 0;
            dq.emplace_front(0, 1, c);
        }
    }

    // 特判起点等于终点
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    int ans = -1;
    while (!dq.empty()) {
        auto [k, u, c_prev] = dq.front();
        dq.pop_front();

        if (u == N) {
            ans = k + 1;
            break;
        }

        // 当前状态不是最优的，跳过
        if (dist[u][c_prev] < k) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int c_current = edge.second;
            int new_k = k + (c_prev != c_current ? 1 : 0);

            if (!dist[v].count(c_current) || new_k < dist[v][c_current]) {
                dist[v][c_current] = new_k;
                if (c_prev == c_current) {
                    dq.emplace_front(new_k, v, c_current);
                } else {
                    dq.emplace_back(new_k, v, c_current);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}