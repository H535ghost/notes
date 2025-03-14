#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long n, m, ans = 0,d=0;
    cin >> n >> m;
    vector<vector<long long>> v(3, vector<long long>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> v[0][i] >> v[1][i] >> v[2][i];
    }
    vector<long long> s(n);
    for (long long sx : {1, -1})
    {
        for (long long sy : {1, -1})
        {
            for (long long sz : {1, -1})
            {   
                d=0;
                for(long long i=0;i<n;i++){
                    s[i]=sx*v[0][i]+sy*v[1][i]+sz*v[2][i];
                }
                sort(s.begin(), s.end());
                for(long long i=0;i<m;i++){
                    d+=s[n-1-i];
                }
                if(ans<d){
                    ans=d;
                }
            }
        }
    }
    cout<<ans;
}