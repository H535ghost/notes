#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
using vvi=vector<vi>;
ll maxn=1e9+7;
ll factorial(ll n){
    if(n<0)  {cout<<"输入不合法";}
    if(n==0) return 1;
    return n*factorial(n-1);
}
int main(){
      ll n,x;
      double ans=0;
      cout<<"输入x与阶次n"<<endl;
      cin>>x>>n;
      ll dp=1;
      double q=1;
      for(int i=0;i<=n;i++){
          ans+=(q*dp)/factorial(i);
          dp*=x;
      }
      cout<<ans;
}