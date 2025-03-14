#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
#include <math.h>
using namespace std;
long long sqr(long long x){
    return x*x;
}
int main(){
    long long n,k,t;
    cin>>n>>k>>t;
    vector<long long> a(n+1,0);
    for(int i=1;i<1+n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    vector<vector<long long>> dp(n+1,vector<long long>(2,0));
    dp[1][1]=0;dp[1][0]=a[1];
    vector<long long>::iterator p,q;
    p=a.begin()+2;q=a.end()-1;
    for(int i=2;i<n+1;i++){
        long long d=((i-1)*dp[i-1][0]+*p)/i;
        long long u=(i-1)*(dp[i-1][1]+sqr(dp[i-1][0]-d))+sqr(*p-d);
        d=((i-1)*dp[i-1][0]+*q)/i;
        long long v=(i-1)*(dp[i-1][1]+sqr(dp[i-1][0]-d))+sqr(*q-d);
        if(u<v){
           dp[i][0]=d;
           dp[i][1]=v;
            q--;
    }
    else{
        dp[i][0]=((i-1)*dp[i-1][0]+*p)/i;
        dp[i][1]=u;
        p++;
     }
     if(dp[i][1]/i<t){
         cout<<i;
         return 0;
     }
    }
    cout<<-1;
}