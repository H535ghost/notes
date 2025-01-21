#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int m, n;
    cin >> n >> m;
    int k = 0;
    vector<string> a(m), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - m+1; i++)
    {
        for (int j = 0; j < n - m+1; j++)
        {
            k = 0;
                for (int x = 0; x < m; x++)
                {
                    for (int y = 0; y < m; y++)
                    {
                        
                        if (b[i + x][j + y] != a[x][y])
                        {
                            k = -1;
                            break;
                        }
                        
                    }
                    if (k == -1)
                        break;
                }
                if (k == 0)
                    break;
            }
            if (k == 0)
                break;
        }
    if (k == 0)
        cout << "Yes"<<endl;
    else
    {
        cout << "No"<<endl;
    }
}