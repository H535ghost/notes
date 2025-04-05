#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, x;
    cin >> n;
    vi a(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x <= n) {
            a[x]++;
        }
    }

    cout << a[3] << endl;
    sort(a.begin(), a.end());
    vi b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            b[i] += a[j];
        }
        cout << b[i] << endl;
    }

    return 0;
}