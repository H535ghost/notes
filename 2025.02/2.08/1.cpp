#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
int main()
#define int long long 
{
    long long m,n,q,p;
    cin>>m>>n; 
    vector<long> a(m);   
    for(int i=0;i<m;i++){
        cin>>a[i];}
    long long ma=1e18;
    if(m==n){ma=min(abs(a[0])+a[n-1]-a[0],abs(a[n-1])+a[n-1]-a[0]);}
    for(int i=0;i<=m-n;i++){
       if(ma>min(abs(a[i])+a[i+n-1]-a[i],abs(a[i+n-1])+a[i+n-1]-a[i]))
       {ma=min(abs(a[i])+a[i+n-1]-a[i],abs(a[i+n-1])+a[i+n-1]-a[i]);}
    }
    {}
    {}
    {int i=0;};;;;
     cout<<ma<<endl;
}


