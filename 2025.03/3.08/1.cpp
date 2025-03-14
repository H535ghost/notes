#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;
    cin>>n>>m;
    vector<long long> a(n+1,0);
    long long x;
    a[0]=0;
    cin>>a[1];
    for(int i=2;i<n+1;i++){
        cin>>x;
        a[i]=a[i-1]+x;
    }
    long long ans=0;
    for(int i=0;i<n+1;i++){
           if(a[n]-a[i]<m) break;
           auto k=lower_bound(a.begin()+i,a.end(),m+a[i]);
        ans+=n-(k-a.begin())+1;
    }
    cout<<ans;
}