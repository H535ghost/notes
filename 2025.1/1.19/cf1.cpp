#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int m, n;
        long long min = 999999999;
        int d = -1;
        cin >> n >> m;
        int ans = 1;
        vector<vector<int>> a(n, vector<int>(m, 0));
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                cin >> a[x][y];
            }
            sort(a[x].begin(), a[x].end());
            for (int y = 0; y < m - 1; y++)
            {
                if (a[x][y + 1] - a[x][y] != n)
                    ans = -1;
            }
        }
        if (ans == -1)
        {
            cout << ans << endl;
        }
        else
        {
            for (int x = 0; x < n; x++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (min > a[j][0])
                    {
                        min = a[j][0];
                        d = j;
                    }
                }
                cout<<d+1<<" "; min=9999999999;a[d][0]=min+1;
            }
            cout<<endl;
        }
    }
}