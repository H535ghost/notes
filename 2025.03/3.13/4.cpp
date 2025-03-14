#include <bits/stdc++.h>
using namespace std;
int main()
#define int long long
{
    long long n,m;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    int x,y;
    vector<vector<int>> b(m);
    for(int  i=0;i<m;i++){
        cin>>x>>y;
        b[x].push_back(y);
    }
    
}