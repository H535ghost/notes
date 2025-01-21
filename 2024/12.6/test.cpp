#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; // 测试用例数量
    cin >> n;

    while (n--) {
        int k;
        cin >> k; 
        vector<vector<int>> a(k - 1, vector<int>(2, 0)); 
        int count = 0, x;
        for (int i = 0; i <(k * (k - 1)) / 2 - 1; i++) {
            cin >> x;
            bool found = false;
            for (int j = 0; j < count; j++) {
                if (x == a[j][0]) {
                    a[j][1]++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                a[count][0] = x;
                a[count][1] = 1;
                count++;
            }
        }
        for (int i = k - 1; i > 0; i--) {
            int max = -1, d = -1;
            for (int j = 0; j < count; j++) {
                if (a[j][0] > max) {
                    max = a[j][0];
                    d = j;
                }
            }

            if (d != -1 && a[d][1] != i) {
                if (i == 1) {
                    cout << "Infinite" << endl;
                } else {
                    cout << a[d][0] << endl;
                }
                break;
            }
            a[d][0] = 0;
        }

      
    }
    return 0;
}

