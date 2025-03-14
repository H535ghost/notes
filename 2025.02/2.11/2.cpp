#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long sum(long long m,long long n){
    long long k=0;
    while(m>=n){
        k+=m%n;
        m=m/n;
    }
    k+=m;
    return k;
}
int main() 
{
    long long m,n;
    long long ans=-1;
    cin>>m>>n;
    if(n>m)  {cout<<ans; return 0;}
    if(n==m)  {cout<<n+1;return 0;} 
    for(long long i=2;i*i<=m;i++){
        if(sum(m,i)==n)  { cout<<i;return 0;}
    }
    long long a;
    for(long long i=sqrt(m);i>0;i--){
        if((m-n)%i==0){
             a=(m-n)/i+1;
            if(sum(m,a)==n&&a>1)  {cout<<a; return 0;}
        }
    }
    cout<<ans;
}