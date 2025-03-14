#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    long long n,sum=0,m=1e9;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<n+1;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1;i<n+1;i++){    
        a[i]=a[i]+a[i-1];
        if(abs(sum-2*a[i])<m)  m=abs(sum-2*a[i]);
    }
    cout<<m;
}