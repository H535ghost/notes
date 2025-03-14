#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int m,n,x,y,p,q;
    cin>>m>>n;
    vector<vector<int>> a(n+1,vector<int> (n,0));
    vector<vector<int>> b(n+1,vector<int> (n,0));
    for(int i=0;i<m-1;i++){
       cin>>x>>y>>p>>q;
       a[x][y]=p;
       b[x][y]=q;
       a[y][x]=p;
       b[y][x]=q;
    }
       
}