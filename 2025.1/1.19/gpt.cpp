#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> q; 
vector<string> a; 
void find(int x, int y) {
    if (x + 1 < a.size() && a[x + 1][y] != a[x][y] && q[x + 1][y] == 0) {
        q[x + 1][y] = 1;
        find(x + 1, y);
    }
    if (y - 1 >= 0 && a[x][y - 1] != a[x][y] && q[x][y - 1] == 0) {
        q[x][y - 1] = 1;
        find(x, y - 1);
    }
    if (y + 1 < a[0].size() && a[x][y + 1] != a[x][y] && q[x][y + 1] == 0) {
        q[x][y + 1] = 1;
        find(x, y + 1);
    }
    if (x - 1 >= 0 && a[x - 1][y] != a[x][y] && q[x - 1][y] == 0) {
        q[x - 1][y] = 1;
        find(x - 1, y);
    }
}
int main() {
    int n, m;
    cin >> n >> m;

    a.resize(n);
    q.resize(n, vector<int>(n, 0)); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans(m, 0);
    int x, y, t, z;
    for (int k = 0; k < m; k++) {
        cin >> x >> y;
        x--; y--; 
        find(x, y);
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (q[i][j] == 1) count++;
            }
        }
        ans[k] = count;
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
