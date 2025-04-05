#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
int main()
{   double k=0,d=1;
    long long ans = 0,bre=0;
    long long tol = 0, br = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> a(5, vector<int>(5, 0));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> a[i][j];
            if (i != 3)
                tol += a[i][j] * (i + 1);
            if (i == 3)
                tol += a[i][j];
            if (i == 4)
                br += a[i][j];
        }
    }
    tol =tol*10;
    br = br*100;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            
            if (j == 0)
            {
                if (i != 3)
                    ans += a[i][j] * (i + 1)*10;
                if (i == 3)
                    ans += a[i][j]*10;
            }
            if (j == 1)
            {
                if (i != 3)
                    ans += a[i][j] * (i + 1)*10;
                if (i == 3)
                    ans += a[i][j]*10;
            }
            if (j == 2)
            {
                if (i != 3)
                    ans += a[i][j] * (i + 1)*8;
                if (i == 3)
                    ans += a[i][j]*8;
            }
            if (j == 3)
            {
                if (i != 3)
                    ans += a[i][j] * (i + 1)*5;
                if (i == 3)
                    ans += a[i][j]*5;
            }
        }
    }
    bre+=a[4][0]*100;
    bre+=a[4][1]*75;
    bre+=a[4][2]*40;
    bre+=a[4][3]*30;
    k=100*d*ans/tol+d*bre/br;
    int y=k;
    int z=(k-y)*100000;
    cout<<y<<"."<<z<<"%";
}