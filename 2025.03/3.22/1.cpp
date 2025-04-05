#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
using vvi=vector<vi>;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    vvi a(3*n,vi(2,0));
    cin>>n;
    for(int i=0;i<3;i++){
       for(int j=0;j<n;i++){
          cin>>a[i*n+j][0];
          a[i*n+j][1]=i+1;    
       }
    }
    sort(a.begin(),a.end());
    ll ans=0;
    
}