#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    vector<int> a(m,0);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    vector<vector<vector<long long>>> dp(m+1,vector<vector<long long>> (m+1,vector<long long> (m*50+1,0)));
    dp[0][0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=m*50;k++){
                dp[i][j][k]=dp[i-1][j][k];
                if(j>=1&&k>=a[i-1]){
                    dp[i][j][k]+=dp[i-1][j-1][k-a[i-1]];
                }
            }
        }
    }
    long long ans=0;
    for(int i=1;i<m+1;i++){
          ans+=dp[m][i][i*n];
    }
    cout<<ans;
}