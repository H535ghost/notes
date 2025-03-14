#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.rbegin(), a.rend());
    
    int k = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= i + 1) {
            k = i;
        } else {
            break;
        }
    }
    
    if (k == -1) {
        if (a[0] % 2 == 1) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    } else {
        bool cond = false;
        if (k + 1 < n && a[k + 1] >= k + 1) {
            cond = true;
        }
        if (cond) {
            cout << (k % 2 == 0 ? "First" : "Second") << endl;
        }else {
            int d = a[k] - (k + 1);
            if ((k % 2) == (d % 2)) {
                cout << (k % 2 == 0 ? "Second" : "First") << endl;
            } else {
                cout << (k % 2 == 0 ? "First" : "Second") << endl;
            }
        }
    }
    return 0;
}