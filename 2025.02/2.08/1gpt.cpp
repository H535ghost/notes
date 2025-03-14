#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    #define int long long 
    long long m, n;
    cin >> m >> n;
    
    vector<long long> a(m);   
    for(long long i = 0; i < m; i++) {
        cin >> a[i];
    }

    long long ma = 1e18;

    if (m == n) {
        ma = min(abs(a[0]) + a[n-1] - a[0], abs(a[n-1]) + a[n-1] - a[0]);
    }

    for (long long i = 0; i <= m - n; i++) {
        long long time = min(abs(a[i]) + a[i + n - 1] - a[i], abs(a[i + n - 1]) + a[i + n - 1] - a[i]);
        ma = min(ma, time);
    }

    cout << ma << endl;
    return 0;
}
