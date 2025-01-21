#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> q;  // 用于标记是否已访问过的位置
vector<string> a;       // 用于存储二维地图

void find(int x, int y) {
    if (x < 0 || x >= a.size() || y < 0 || y >= a[0].size() || q[x][y] == 1) return;  // 边界检查和已访问判断
    q[x][y] = 1;  // 标记当前位置已访问

    // 递归四个方向
    if (x + 1 < a.size() && a[x + 1][y] == a[x][y]) find(x + 1, y);  // 向下
    if (y - 1 >= 0 && a[x][y - 1] == a[x][y]) find(x, y - 1);        // 向左
    if (y + 1 < a[0].size() && a[x][y + 1] == a[x][y]) find(x, y + 1);  // 向右
    if (x - 1 >= 0 && a[x - 1][y] == a[x][y]) find(x - 1, y);        // 向上
}

int main() {
    int n, m;
    cin >> n >> m;
    a.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> ans(m, 0);
    
    for (int k = 0; k < m; k++) {
        q.assign(n, vector<int>(n, 0));  // 每次查询之前初始化q
        int x, y;
        cin >> x >> y;
        x--;  // 将1-based转换为0-based
        y--;  // 将1-based转换为0-based
        find(x, y);
        
        // 计算查询位置周围连通的区域大小
        int region_size = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a[0].size(); j++) {
                if (q[i][j] == 1) {
                    region_size++;
                }
            }
        }
        ans[k] = region_size;
    }
    
    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}

