#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dfs(int a, int b, int k, vector<vector<int>> &v,int n)
{
    vector<int> dp(n + 1, 0);
        
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        cin >> v[a - 1][b - 1];
    }
    int k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cout << dfs(a, b, k,v,n) << endl;
    }
}
