#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define M 1000000007
#define MAXN 2001
long long c[MAXN][MAXN];
void precompute() {
    for (int i = 0; i < MAXN; ++i) {
        c[i][0] = 1;
        if (i > 0) {
            for (int j = 1; j <= i; ++j) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % M;
            }
        }
    }
}
int main()
#define int long long
{
    precompute();
    int m,n;
    cin>>m>>n;
    int k=0,ans=0;
    for(int i=1;i<n+1;i++){
      ans=1;
      ans=ans*c[m-n+1][i]*c[n-1][i-1];
      ans=ans%M;
      cout<<ans<<endl;
    }
}