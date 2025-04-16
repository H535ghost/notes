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
    vi a(3,0);
    cin>>a[0]>>a[1]>>a[2];
    sort(a.begin(),a.end());
    for(int i=0;i<3;i++){
        if(a[i]%2==0) {cout<<0 ;return 0;}
    }
    cout<<a[0]*a[1];
}
