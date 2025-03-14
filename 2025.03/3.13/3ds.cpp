#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    long long total = 0;
    for (int num : a) {
        total += num;
    }

    vector<bool> covered(N + 1, false);
    long long smashed = 0;

    for (int x = N; x >= 1; --x) {
        long long sum = 0;
        for (int i = x; i <= N; i += x) {
            if (!covered[i]) {
                sum += a[i - 1];
            }
        }
        if (sum < 0) {
            smashed += sum;
            for (int i = x; i <= N; i += x) {
                covered[i] = true;
            }
        }
    }

    cout << total - smashed << endl;

    return 0;
}