#include <bits/stdc++.h>
using namespace std;
int main(){
    long long k,m,n;
    cin>>k>>m>>n;
    vector<long long > a(k,0);
    for(int i=0;i<k;i++){
          cin>>a[i];
    }
    if(k>=2)
    cout<<max(abs(a[k-1]-n),abs(a[k-1]-a[k-2]));
    else{
        cout<<abs(a[k-1]-n);
    }
}