#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
long long ex(string a)
{
    if (a == "b")
        return 1 * 1LL;
    if (a == "B")
        return 8 * 1LL;
    if (a == "kib")
        return 1024 * 1LL;
    if (a == "kiB")
        return 1024 * 8 * 1LL;
    if (a == "kb")
        return 1000 * 1LL;
    if (a == "kB")
        return 1000 * 8 * 1LL;
    if (a == "Mb")
        return 1000 * 1000 * 1LL;
    if (a == "MB")
        return 1000 * 1000 * 8 * 1LL;
    if (a == "Mib")
        return 1024 * 1024 * 1LL;
    if (a == "MiB")
        return 1LL * 1024 * 1024 * 8;
    if (a == "Gb")
        return 1LL * 1000 * 1000 * 1000;
    if (a == "GB")
        return 1LL * 1000 * 1000 * 1000 * 8;
    if (a == "Gib")
        return 1LL * 1024 * 1024 * 1024;
    if (a == "GiB")
        return 1LL * 1024 * 1024 * 1024 * 8;
    if (a == "Tb")
        return 1LL * 1000 * 1000 * 1000 * 1000;
    if (a == "Tib")
        return 1LL * 1024 * 1024 * 1024 * 1024;
    if (a == "TB")
        return 1LL * 1000 * 1000 * 1000 * 1000 * 8;
    if (a == "TiB")
        return 1LL * 1024 * 1024 * 1024 * 1024 * 8;
    return 0;
}
int main()
#define int unsigned long long
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, b = 0;
    cin >> n;
    string a, c, x;
    long long q = 0, p = 0;
    while (n)
    {
        cin >> a >> c;
        vi y(30, 0), u(30, 0), v(30, 0);
        q = 0;
        p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (b == 0 && '0' <= a[i] && a[i] <= '9')
            {
                y.push_back(a[i] - '0');
            }
            if (b == 0 && ('0' > a[i] || '9' < a[i]))
                b = 1;
            if (b == 1 && a[i] == '+')
            {
                for (int i = 0; i < y.size()-1; i++)
                {
                    y[i] = y[i] * ex(x);
                    if (y[i-1] > 9&&i>=1)
                    {
                        y[i] += y[i-1] / 10;
                        y[i-1] %= 10;
                    }
                    u[i] += y[i];
                    y[i] = 0;
                }
                b = 0;
                q = 0;
                while (!x.empty())
                {
                    x.pop_back();
                }
            }
            if (b == 1)
                x.push_back(a[i]);
        }
        for (int i = 0; i < y.size()-1; i++)
        {
            y[i] = y[i] * ex(x);
            if (y[i-1] > 9&&i>=1)
            {
                y[i] += y[i-1] / 10;
                y[i-1] %= 10;
            }
            u[i] += y[i];
            y[i] = 0;
        }
        b = 0;
        q = 0;
        while (!x.empty())
        {
            x.pop_back();
        };
        for (int i = 0; i < c.size()-1; i++)
        {
            if (b == 0 && '0' <= c[i] && c[i] <= '9')
                y.push_back(c[i] - '0');
            if (b == 0 && ('0' > c[i] || '9' < c[i]))
                b = 1;
            if (b == 1 && c[i] == '+')
            {
                for (int i = 0; i < y.size()-1; i++)
                {
                    y[i] = y[i] * ex(x);
                    if (y[i-1] > 9&&i>=1)
                    {
                        y[i] += y[i-1] / 10;
                        y[i-1] %= 10;
                    }
                    v[i] += y[i];
                    y[i] = 0;
                }
                b = 0;
                q = 0;
                while (!x.empty())
                {
                    x.pop_back();
                };
            }
            if (b == 1)
                x.push_back(c[i]);
        }
        for (int i = 0; i < y.size()-1; i++)
        {
            y[i] = y[i] * ex(x);
            if (y[i] > 9&&i>=1)
            {
                y[i] += y[i-1] / 10;
                y[i-1] %= 10;
            }
            v[i] += y[i];
            y[i] = 0;
        };
        b = 0;
        q = 0;
        while (!x.empty())
        {
            x.pop_back();
        }
        for(int i=29;i>=0;i--){
        if (u[i] > v[i])
            {cout << "L" << endl;break;}
        if (u[i] < v[i]){
            cout << "T" << endl;break;} 
        if(i==0){
            cout << "=" << endl;break;
        }
        }
        n--;
    }
}