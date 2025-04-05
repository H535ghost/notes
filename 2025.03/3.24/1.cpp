#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
using vvi=vector<vi>;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,x,m=0;
    cin>>n;
    vi a(n+1,0);
    for(int i=0;i<n;i++){
        scanf("%lld",&x);
        if(x>m) m=x;
        a[x]++;
    }
    sort(a.begin(),a.end());
    vi b(n+1,0);
    for(int i=1;i<=m;i++){
    for(int j=i;j<=n;j+=i){
        b[i]+=a[n-j+1];   
    }
    printf("%lld\n",b[i]);
    
  }
  for(int i=0;i<n-m;i++){
    cout<<0<<endl;
  }
}