#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
ll maxn = 1e9 + 7;
vi cl(vi a)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = 0;
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n)
    {
        int m;
        cin >> m;
        vector<string> a(m, "");
        vvi b(m - 1, vi(5, 0));
        vi c(m, -1);
        vi p(5, 0), q(5, 0);
        vi ans(m, 0);
        ll u = -1, mi = maxn, v = -1;
        vi out;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (a[i][j] == '@')
                {
                    if (i-1>=0&&a[i - 1][j] == '.')
                    {
                        p[j]++;
                    }
                    if (i+1<=m&&a[i + 1][j] == '.')
                    {
                        q[j]++;
                    }
                }
                else
                {
                    if (a[i][j] != a[i - 1][j])
                        b[i - 1][j]++;
                }
            }
            cout<< a[i] << endl;
            if (a[i][0] =='@')
            {
                c[i] = 0;
                for (int j = 0; j < 4; j++)
                {
                    if (p[j] == 1)
                    {
                        if (p[j + 1] == p[j] && a[i][j] != a[i][j + 1])
                            c[i]++;
                    }
                    if (q[j] == 1)
                    {
                        if (q[j + 1] == q[j] && a[i][j] != a[i][j + 1])
                            c[i]++;
                    }
                }
                p = cl(p);
                q = cl(q);
                i++;
            }
            else
            {
                for (int j = 0; j < 4; j++)
                {
                    if (b[i][j] == 1)
                    {
                        if (b[i - 1][j] == b[i][j + 1] && a[i][j] != a[i][j + 1])
                            ans[i]++;
                    }
                }
                ans[i] += ans[i - 1];
            }
        }
        cout<< ans[m - 1] << endl;
        if (c[m - 1] == -1)
            c[m - 1]++;
        vi more;
        for (int i = 0; i < m; i++)
        {
            if (c[i] != -1)
            {
                u = v;
                v = i;
                more.push_back(c[i]);
                out.push_back(ans[v] - ans[u]);
                if (out.size() > 3)
                {
                    out[out.size() - 1] += out[out.size() - 3];
                }
            }
        }
        out[0] = 0;
        vi dp(out.size() + 1, 0);
        dp[0] = out[out.size() - out.size() % 2 - 1];
        mi = dp[0];
        for (int i = 0; i < out.size(); i++)
        if (i + 2 - i % 2 < out.size()){
        {
            dp[i] = (out[out.size() + out.size() % 2 - 2] + out[i + 1 - i % 2] - out[i + 2 - i % 2]) * 10 + more[i];
            if (mi > dp[i])
                mi = dp[i];
        }}
        cout << ans[m - 1] + mi;
    }
}