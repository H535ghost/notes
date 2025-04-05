#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    unordered_map<int, int> freq;
    for (int x : A) {
        freq[x]++;
    }

    vector<int> cnt;
    for (auto& p : freq) {
        cnt.push_back(p.second);
    }
    sort(cnt.begin(), cnt.end());

    int m = cnt.size();
    vector<long long> pre(m + 1, 0);
    for (int i = 0; i < m; ++i) {
        pre[i + 1] = pre[i] + cnt[i];
    }

    for (int K = 1; K <= N; ++K) {
        int left = 0, right = N / K;
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            auto pos = upper_bound(cnt.begin(), cnt.end(), mid) - cnt.begin();
            long long sum_min = pre[pos] + 1LL * mid * (m - pos);
            if (sum_min >= 1LL * K * mid) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        printf("%d ", ans);
    }
    printf("\n");
    return 0;
}