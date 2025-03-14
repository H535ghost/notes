#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
long long o=1e9+7;
vector<long long> getFactors(int N) {
    vector<long long> factors;
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            factors.push_back(i);
            if (i != N / i) factors.push_back(N / i);
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}
int main(){
    long long m,n;
    cin>>m>>n;
    auto k=getFactors(m);
    long long d=k.size();
    vector<vector<long long>> dp(n,vector<long long> (d,0));
    dp[0][0]=0;
    for(int i=1;i<d;i++){
        dp[0][i]=k[i]-k[i-1];
    }
    for(long long i=1;i<n;i++){
        for(int j:k){
            for(int q:k){
                if(j*q<=m){
                    dp[i][j]+=dp[i-1][q];
                    dp[i][j]=dp[i][j]%o;
                }
            }
        }
    }
    long long ans=0;
    for(int i=1;i<d;i++){
        cout<<dp[n-1][i]<<endl;
        ans+=dp[n-1][i];
        ans=ans%o;
    }
    cout<<ans;
}