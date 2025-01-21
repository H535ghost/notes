#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        k = 0;
        vector<int> a(m, 0);
        for (int j = 0; j < m; j++)
        {
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        for (int j = 0; j < m - 1; j++)
        {
            if (a[j] == a[j + 1])
            {
                for (int x = 0; x < m - 1; x++)
                {
                    if (j == 0 && x == 0)
                    {
                        x = 2;
                    }
                    if (x == j - 1)
                    {
                        if (2 * a[j] > a[j + 2] - a[j - 1])
                        {
                            k = 1;
                            cout << a[j] << " " << a[j] << " " << a[j - 1] << " " << a[j + 2] << endl;
                            break;
                        }
                        x = x + 2;
                    }
                    else
                    {
                        if (2 * a[j] > a[x + 1] - a[x])
                        {
                            k = 1;
                            cout << a[j] << " " << a[j] << " " << a[x] << " " << a[x + 1] << endl;
                            break;
                        }
                    }
                }
                if (k == 1)
                    break;
            }
        }
        if (k == 0)
        {
            cout << "-1" << endl;
        }
    }
}