#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 图的邻接表
unordered_map<int, vector<int>> graph;

// 深度优先搜索函数
int dfs(int node, int visited, int n) {
    if (visited == (1 << n) - 1) { // 所有顶点已访问
        return 1;
    }

    int count = 0;
    for (int neighbor : graph[node]) {
        if (!(visited & (1 << (neighbor - 1)))) { // 如果邻居未访问
            count += dfs(neighbor, visited | (1 << (neighbor - 1)), n);
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    // 读入图的边
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 从顶点1出发，初始仅访问了顶点1
    cout << dfs(1, 1 << 0, n) << endl;

    return 0;
}
