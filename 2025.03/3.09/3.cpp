#include <bits/stdc++.h>
using namespace std;
int main()
{   
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);    
    long long n, m;
    cin >> n >> m;
    vector<long long> lo(n, 0);
    long long k=1, u=0;
    for (int i = 0; i < n; i++)
    {
        cin>>lo[i];
    }
    u = lo[1] + lo[0];
    for (int i = 2; i < n; i++)
    {
        if (u < lo[i] + lo[i - 1])
        {
            u = lo[i] + lo[i - 1];
            k = i;
        }
    }
    if (u < m)
    {
        cout << "Impossible";
    }
    else
    {
        cout << "Possible" << endl;
        for (int i = 1; i < k; i++)
        {
            cout << i << '\n';
        }
        for(int i=n-1;i>k;i--){
            cout<<i<<'\n';
        }
        cout << k << endl;
    }
}