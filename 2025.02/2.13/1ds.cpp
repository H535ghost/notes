#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int S, T;
    cin >> S >> T;

    vector<vector<int>> dist(N + 1, vector<int>(3, -1));
    queue<pair<int, int>> q;

    dist[S][0] = 0;
    q.emplace(S, 0);

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int u = front.first;
        int r = front.second;

        if (u == T && r == 0) {
            cout << dist[u][r] / 3 << "\n";
            return 0;
        }

        for (int v : adj[u]) {
            int nr = (r + 1) % 3;
            if (dist[v][nr] == -1) {
                dist[v][nr] = dist[u][r] + 1;
                q.emplace(v, nr);
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}