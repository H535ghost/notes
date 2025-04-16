#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
using vvi=vector<vi>;
ll maxn=1e9+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vi a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll m;
    cin>>m;
    vvi b(m,vi(3,0));
  
    for(int i=0;i<m;i++){  
          
          for(int j=0;j<3;j++){
            cin>>b[i][j];
          }
          vi c(b[i][1]-b[i][0]+1,0);
          for(int j=b[i][0]-1;j<b[i][1];j++){
             c[j-b[i][0]+1]=a[j];
          }
          sort(c.begin(),c.end());
          cout<<c[b[i][1]-b[i][0]-b[i][2]+1]<<endl;
    }   

    
}