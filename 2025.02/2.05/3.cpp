#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long dfs(int a, int b, int m, int n, int x,int y)
{
 if (x >= m - a + 1 && y <= b) {
        return 0;
    }
    long long ans = 0;
    if (x == m && y == n)
    {
        return 1;
    }
    for(int i=x;i<m;i++){
       ans+= dfs(a,b,m,n,i,y+1);
    }
    return ans;
}
int main()
{
    long long a, b, m, n;
    cin >> m>>n>>a>>b;
    cout << dfs(a,b,m,n,1,1) << endl;
}       
