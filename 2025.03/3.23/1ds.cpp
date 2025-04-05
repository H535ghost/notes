#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; ++i) {
        cin >> L[i];
    }
    sort(L.begin(), L.end());
    
    int ans = 0;
    for (int k = 2; k < N; ++k) {
        int i = 0, j = k - 1;
        while (i < j) {
            if (L[i] + L[j] > L[k]) {
                ans += j - i;
                j--;
            } else {
                i++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}