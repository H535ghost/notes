#include <iostream>
using namespace std;
#include <vector>
vector<vector<int>> q;
vector<string> a;
void find(int x,int y){
    if(a[x+1][y]!=a[x][y]&&q[x+1][y]==0){
        q[x+1][y]=1;
        find(x+1,y);
    }
       if(a[x][y-1]!=a[x][y-1]&&q[x][y-1]==0){
        q[x][y]=1;
        find(x,y);
    }
     if(a[x][y+1]!=a[x][y]&&q[x][y+1]==0){
        q[x][y+1]=1;
        find(x+1,y);
    } if(a[x-1][y]!=a[x][y]&&q[x-1][y]==0){
        q[x-1][y]=1;
        find(x-1,y);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    a.resize(n);
    q.resize(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> ans(m, 0);
    for(int i=0;i<m;i++){
        for(int j=0;j<1;j++)
        q[i].push_back(0);
    }
    int x, y, t, z;
    for (int k = 0; k < m; k++)
    {
        cin >> x >> y;
        find(x,y);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (q[i][j]==1) ans[k]++; 
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<endl;
    }
}
