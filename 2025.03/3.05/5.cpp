#include <bits/stdc++.h>
using namespace std;
long long M=1e9+7;
int find(vector<long long> &g,long long a,long long k){
    long long ans=k;
    if(g[a]!=-1) ans=find(g,g[a],k+1);
    return ans;
}
long long com(long long a,long long b){
    long long ans=1;
    for(long long i=1;i<=b;i++){
        ans=ans*(a-i+1)/i;
        ans=ans%M;
    }
    return ans;
}
long long add(long long a){
    long long ans=0;
    long long i=1;
    while(i<=a){
        ans+=com(a,i);
        ans=ans%M;
        i=i+2;
    }
    return ans;
}
long long power(int i){
    long long ans=1;
    while(i){
        ans*=2;
        ans=ans%M;
        i--;
    }
    return ans;
}
int main(){
    long long n;
    cin>>n;
    vector< long long> a(n+1,-1);
    vector<int> b(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n;i++){
        b[find(a,i,0)]++;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        if(b[i]==0) break;
        ans+=power(n-b[i]+1)*add(b[i]);
        ans=ans%M;
    }
    cout<<ans;
}