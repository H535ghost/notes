#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std ;
long long M=1e9+7 ;
int main() {
    long long m,n;
    cin>>m>>n;
    vector<long long> a(n,0);
    vector<long long> dp(m+1,-1);
    for(long long i=0;i<n;i++){
        cin>>a[i];
        dp[a[i]]=0;
    }
    dp[0]=1;
    if(dp[1]==-1)
    dp[1]=1;
    for(long long i=2;i<m+1;i++){
        if(dp[i]==-1){
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]=dp[i]%M;}
        else{
            dp[i]=0;
        }
    } 
    cout<<dp[m];
}