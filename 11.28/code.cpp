
#include <iostream>
using namespace std;
#include <vector>
/*class Solution {
public:
int m;
    int maximizeWin(vector<int>& prizePositions, int k) {
        vector <int> a;
        for(int i=0;i<sizeof(prizePositions);i++){
            m=0;
            for(int j=0;j<=k;j++)
            { m=m+prizePositions[i+j];}
            a.push_back(m);
        }
        int max=0;
        for(int i=0;i<sizeof(prizePositions)-k;i++){
            if(max<a[])
        }
    }
};*/
class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> dp(n + 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = lower_bound(prizePositions.begin(), prizePositions.end(), prizePositions[i] - k) - prizePositions.begin();
            ans = max(ans, i - x + 1 + dp[x]);
            dp[i + 1] = max(dp[i], i - x + 1);
            cout<<ans<<"  "<<dp[i+1]<<endl;
        }
        return ans;
    }
};
Solution a;
int main(){
    vector<int> x={1,1,2,2,3,5};
          int ans=a.maximizeWin(x,2);
          int k=x.end()-x.begin();
          cout<<ans<<"   "<<k;
}

