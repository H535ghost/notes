#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;
int dfs(vector<vector<long long>> &p,vector<vector<long long>>& q,long long m,long long n,int ans,vector<long long> &a,vector<long long> &b,int r,int s){
    int k=ans;
      for(long long i:p[m]){
          for(long long j:q[n]){
              if(a[i]==b[j]&&i!=r&&j!=s){
                  ans=max(ans,dfs(p,q,i,j,k+1,a,b,m,n));
              }
          }
      }
    return ans;
}
int main() {
    long long n,m,x,y;
    cin>>m>>n;
    vector<long long> a(m+1,0),b(n+1,0);
    vector<vector<long long>> p(m+1),q(n+1);
    for(int i=1;i<m+1;i++){
        cin>>a[i];
    }
    for(int j=1;j<n+1;j++){
        cin>>b[j];
    }
    for(int i=0;i<m-1;i++){
        cin>>x>>y;
        p[x].push_back(y);
        p[y].push_back(x);
    }
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        q[x].push_back(y);
        q[y].push_back(x);
    }
    if(a[1]!=b[1]){
        cout<<0;
        return 0;
    }
    cout<<dfs(p,q,1,1,1,a,b,-1,-1);  
}