#include <bits/stdc++.h>
using namespace std;
long long pow2(long long n){
    long long ans=1,k=2;
    while(n){
        
        if(n%2)
        ans*=k;
        n-=n%2;
        n=n/2;
        k=k*k;
    }
    return ans;
}
int main(){
    long long n,m;
    cin>>m>>n;
    cout<<pow2(n)*((m-n)*100+n*1900);
}