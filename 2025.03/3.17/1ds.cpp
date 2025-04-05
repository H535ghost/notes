#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int main() {
    ll H, W;
    int N;
    cin >> H >> W >> N;

    ll total = (H - 2) * (W - 2);
    map<pair<int, int>, int> count_map;

    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;

        int x_start = max(1, a - 2);
        int x_end = min(a, (int)(H - 2));
        if (x_start > x_end) continue;

        int y_start = max(1, b - 2);
        int y_end = min(b, (int)(W - 2));
        if (y_start > y_end) continue;

        for (int x = x_start; x <= x_end; ++x) {
            for (int y = y_start; y <= y_end; ++y) {
                count_map[{x, y}]++;
            }
        }
    }

    ll ans[10] = {0};
    for (auto &entry : count_map) {
        int j = entry.second;
        if (j >= 0 && j <= 9) {
            ans[j]++;
        }
    }

    ans[0] = total;
    for (int j = 1; j <= 9; ++j) {
        ans[0] -= ans[j];
    }

    for (int j = 0; j < 10; ++j) {
        cout << ans[j] << endl;
    }

    return 0;
}