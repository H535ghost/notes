#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;
int main() {
    long long m=0,n=0;
    long long min=0,x=0,y=0,sum=0;
    cin>>m>>n;
    vector<vector<long long>> a(m,vector<long long> (2,0));
    for(int i=0;i<m;i++){
        cin>>a[i][1]>>a[i][0];
        sum+=a[i][1];
    }
    long long p=-1,ans=0;
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++){
        if(sum<n) {p=i;break;}
           sum-=a[i][1];
           
    }
    if(p==-1){
        cout<<n*a[m-1][0];
    }
    else{
        if(p!=0){
        ans=n*a[p-1][0];
        for(int i=p;i<m;i++){
            ans+=(a[i][0]-a[p-1][0])*a[i][1];
        }}
        else{
            for(int i=0;i<m;i++){
                ans+=a[i][0]*a[i][1];
            }
        }
        cout<<ans;
    }
}