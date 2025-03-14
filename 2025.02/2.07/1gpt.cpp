#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 2e5 + 10;

long long fact[MAX], inv_fact[MAX];

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    inv_fact[MAX-1] = power(fact[MAX-1], MOD-2);
    for (int i = MAX-2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i+1] * (i+1)) % MOD;
    }
}

long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return (fact[n] * inv_fact[k] % MOD) * inv_fact[n-k] % MOD;
}

int main() {
    precompute();
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    long long total = comb(H + W - 2, H - 1);
    long long forbidden = 0;

    for (int i = 1; i <= B; i++) {
        long long way1 = comb(H - A + i - 2, i - 1);
        long long way2 = comb(A + W - i - 1, A - 1);
        forbidden = (forbidden + way1 * way2 % MOD) % MOD;
    }

    long long result = (total - forbidden + MOD) % MOD;
    cout << result << endl;

    return 0;
}

