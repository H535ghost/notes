#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,n,x,y;
    cin>>m>>n;
    vector<vector<int>> p(m+1),q(m+1);
    for(int i=0;i<m-1;i++){
         cin>>x>>y;
         p[x].push_back(y);
         p[y].push_back(x);
    }
    q=p;
    vector<int> bo(m+1,0);
    vector<long long> ans(m+1,0);
    queue<int> a;
    a.emplace(1);
    bo[1]=1;
    while(!a.empty()){
        int t=a.front();
        a.pop();
        int k=p[t].size();
        for(int i=0;i<k;i++){
            if(bo[p[t][i]]==1) {q[t].erase(q[t].begin()+i);break;}
        }
        for(auto i:q[t]){
            
            a.emplace(i);
            bo[i]=1;
            
        }
    }
    for(int i=0;i<n;i++){
        cin>>x>>y;
        ans[x]+=y;
    }
    while(!a.empty()){
        a.pop();
    }
    a.emplace(1);
    while(!a.empty()){
        int i=a.front();
        a.pop();
      for(auto j :q[i]) {
        ans[j]+=ans[i];
        a.emplace(j);
      }
    }
    for(int i=0;i<m;i++){
        cout<<ans[i+1]<<" ";
    }
}