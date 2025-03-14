#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    vector<long long> s(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        s[i] = s[i - 1] + a[i - 1];
    }

    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
        long long target = s[i] - K;
        if (target < 0) continue;
        // 在s[0..i-1]中找到最大的j，使得s[j] <= target
        auto it = upper_bound(s.begin(), s.begin() + i, target);
        int j_max = it - s.begin() - 1;
        if (j_max >= 0) {
            ans += j_max + 1;
        }
    }

    cout << ans << endl;

    return 0;
}