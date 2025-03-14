#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define M 1000000007
long long modInverse(long long a, long long m) {
    long long m0 = m, x0 = 0, x1 = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        long long q = a / m;
        long long t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}
long long c(long long a, long long b) {
    if (a < b || b < 0) return 0;  
    long long res = 1;
    for (long long i = 1; i <= b; ++i) {
        res = res * (a - i + 1) % M;
        res = res * modInverse(i, M) % M;  
    }
    return res;
}

int main() {
    long long m, n;
    cin >> m >> n;
    
    for (long long i = 1; i <= n; ++i) {
        long long ans = c(m - n + 1, i) * c(n - 1, i - 1) % M;
        cout << ans << endl;
    }

    return 0;
}
