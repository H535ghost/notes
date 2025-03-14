#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;
#define MOD 1000000007
int main() {
    int m,n;
    cin>>m>>n;
    vector<long long>a(m,0),b(n,0);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int j=0;j<n;j++){
        cin>>b[j];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    long long ans=0;
    long long p,q;
    if(m>2)
    p=(((m-1)*(a[m-1]-a[0]))%MOD+(m-2)*((a[m-2]-a[1]))%MOD)%MOD;
    else if(m==2)
    p=a[1]-a[0];
    p=p%MOD;
    if(n>2)
    q=(((n-1)*(b[n-1]-b[0]))%MOD+((n-2)*(b[n-2]-b[1]))%MOD)%MOD;
    else if(n==2)   
    q=b[1]-b[0];
    q=q%MOD;
    cout<<(p*q)%MOD<<endl;
}