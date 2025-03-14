#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<long long>> a(m+1,vector<long long>(2,0));
    for(int i=0;i<m;i++){
        cin>>a[i][0]>>a[i][1];
    }
    vector<vector<long long>> dp (m+1,vector<long long>(n,0));
    for(int i=1;i<m+1;i++){
        for(int j=0;j<n-a[i][0];j++){
            cout<<dp[i][j+a[i][0]]<<endl;
            dp[i][j+a[i][0]]=max(dp[i-1][j+a[i][0]],dp[i-1][j]+a[i][1]);
            cout<<dp[i][j+a[i][0]]<<endl;
        }  
        cout<<'y'<<endl;
    }
    long long ma=0;
    for(int i=0;i<n;i++){
        ma=max(ma,dp[m][i]);
    }
    cout<<"y";
    cout<<ma;
}