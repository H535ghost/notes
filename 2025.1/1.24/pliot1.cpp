#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 6000;
vector<int> happiness(MAXN);
vector<int> tree[MAXN];
int dp[MAXN][2];
bool has_parent[MAXN];

void dfs(int u) {
    dp[u][0] = 0; // 不参加宴会
    dp[u][1] = happiness[u]; // 参加宴会

    for (int v : tree[u]) {
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> happiness[i];
    }

    for (int i = 1; i < n; i++) {
        int l, k;
        cin >> l >> k;
        tree[k].push_back(l);
        has_parent[l] = true;
    }

    int root = 1;
    while (has_parent[root]) root++;

    dfs(root);

    cout << max(dp[root][0], dp[root][1]) << endl;

    return 0;
}