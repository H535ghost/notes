#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100005;
vector<pair<int, int>> tree[MAXN];
vector<long long> dist(MAXN, -1);

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &edge : tree[u]) {
            int v = edge.first;
            int length = edge.second;
            if (dist[v] == -1) {
                dist[v] = dist[u] + length;
                q.push(v);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].emplace_back(b, c);
        tree[b].emplace_back(a, c);
    }

    int Q, K;
    cin >> Q >> K;

    bfs(K);

    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        long long result = dist[x] + dist[y];
        cout << result << endl;
    }

    return 0;
}