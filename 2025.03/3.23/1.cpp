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
    cin>>n;
    vi a(n,0),b(n-1,0),c(n-1,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i>=1){
            b[i-1]=a[i-1]+a[i];
            c[i-1]=abs(a[i-1]-a[i]);
        }
    }
    ll ans=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){          
                int u=upper_bound(a.begin()+j+1,a.end(),abs((a[i]-a[j])))-a.begin();   
                int v=lower_bound(a.begin()+j+1,a.end(),a[i]+a[j])-a.begin();
              
                if(v>u) ans+=v-u;
            
        }
    }
    cout<<ans;
}