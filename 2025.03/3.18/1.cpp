#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long h,w,n,x,y;
    cin>>n;
    vector<vector<long long>> a(n,vector<long long>(2,0));
    for(int i=0;i<n;i++){
          cin>>a[i][0];
          a[i][1]=i+1;
    }
    sort(a.begin(),a.end());
    long long ans=0;
    for(int i=0;i<n;i++){
        if((i+1)%2!=a[i][1]%2) ans++;
    }
    cout<<ans/2;
}