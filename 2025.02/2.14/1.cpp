#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
     queue<pair<int,int>> a;
     int m,n,x,y;
     cin>>m>>n;
     vector<vector<int>> d(m+1);
     for(int i=0;i<n;i++){
          cin>>x>>y;
         d[x].push_back(y);
     }
    cin>>x>>y;
    a.emplace(x,0);
    
    vector<vector<int>> dis(m+1,vector<int>(3,-1));dis[x][0]=0;
    while(!a.empty()){
         auto p=a.front();
         a.pop();
         int u=p.first,v=p.second;
         if(u==y&&v==0){
            cout<<dis[u][v]/3<<endl;
            return 0;
         }
         for(auto i:d[u]){
            int nr=(v+1)%3;
            if(dis[i][nr]==-1){
                dis[i][nr]=dis[u][v]+1;
                a.emplace(i,nr);
            }
         }
         
    }
    cout<<-1<<endl;
}