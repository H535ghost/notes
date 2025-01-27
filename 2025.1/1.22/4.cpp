#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define M 99999999
int main()
#define int long long
{
    int m, x, y, t;
    double a, b, c;
    long long ans = M, min = M;
    cin >> m >> x >> y;
    vector<vector<int>> q(m, vector<int>(3, 0));
     c=static_cast<double>(x)/y;
    for (int i = 0; i < m; i++)
    {
        cin >> q[i][0] >> q[i][1] >> q[i][2];
    }
    for (int i = 0; i < m - 1; i++)
    {
        a=static_cast<double>(q[i][0])/q[i][1];
        for (int j = i + 1; j < m; j++)
        {
            b=static_cast<double>(q[j][0])/q[j][1];
            if (q[i][0] * y - q[i][1] * x == 0)
            {
                ans = q[i][2];
            }
            else
            {
                if ( ( (a-c)*(b-c))<0&&q[j][0] * y - q[j][1] * x != 0)
                {
                    double k = static_cast<double>(q[i][0] * y - q[i][1] * x) / (q[j][1] * x - q[j][0] * y);
                    int p = (q[i][0] * y - q[i][1] * x) / (q[j][1] * x - q[j][0] * y);
                    for (t = 1; t < (q[j][1] * x - q[j][0] * y); t++)
                    {
                        if (p * t == k * t)
                            break;
                    }
                    ans = t * (q[i][2] + k * q[j][2]);
                    
                }
            }
        }
        if (ans < min) min = ans;
    }
    if (min == M)
        cout << -1;
    else
    {
        cout << min;
    }
}