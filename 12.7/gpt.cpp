#include <iostream>
#include <vector>
#include <array>
#include <algorithm> 
#include <cstdio>
#include <climits>
using namespace std;
#define A "Accepted"
#define R "Rejected"
#define G "Running"
#define N 999999999999
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);  
    long long re; int p;
    int n;
    scanf("%d", &n); 
    while (n--) {
        int a, time, num;
        scanf("%d %d %d", &a, &time, &num);  
        vector<array<int, 3>> n(num, {0, 0, 0});
        for (int i = 0; i < num; i++) {
            int x, t;
            char s[10];
            scanf("%d %d %s", &t, &x, s);  
            n[i][0] = x - 1;  
            n[i][1] = t;
            if (s[0] == 'R') {
                n[i][2] = -1;
            } else if (s[0] == 'A') {
                n[i][2] = 0;
            } else if (s[0] == 'G') {
                n[i][2] = 1;
            }
        }
        vector<array<long long, 2>> ans(a, {N, N});
        for (int i = 0; i < num; i++) {
            if (n[i][2] > -1) {
                if (ans[n[i][0]][n[i][2]] > n[i][1]) {
                     re = n[i][1];
                    for (int j = 0; j < num; j++) {
                        if (n[j][0] == n[i][0] && n[j][2] == -1 && n[j][1] < n[i][1]) {
                            re += 20;
                        }
                    }
                    if (ans[n[i][0]][n[i][2]] > re) {
                        ans[n[i][0]][n[i][2]] = re;
                    }
                }
            }
        }
        vector<long long> k(a, -1), l(a, N);
        long long max = 0, min_value = N;  
        int count = 0, d = 0;
        for (int i = 0; i < a; i++) {
            if (ans[i][0] != N) {
                count++;
                k[i] = std::min(ans[i][0], ans[i][1]);  
            }
            if (ans[i][0] == N && ans[i][1] != N) {
                l[i] = ans[i][1];
            }
        }
        for (int i = 0; i < a; i++) {
            if (ans[i][0] != N) {
                max += std::min(ans[i][0], ans[i][1]);  
            }
        }
        sort(l.begin(), l.end());
        for (int i = 1; i <= a; i++) {
            if (i <= count) {
                printf("-1 ");
            } else {
                if (i == count) {
                    printf("%d ", max);p=-1;
                } else {
                    p++;
                    if (l[p] == N) {
                        printf("-1 ");
                    } else {
                        max += l[p];
                        printf("%d ", max);
                    }
                }
            }
        }
        printf("\n");
    }
}



