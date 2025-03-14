#include <iostream>
#include <vector>
#include <queue>
#include<math.h>
using namespace std;
long long u=1e9+7;
int main() {
    int m,n,x,y;
    cin>>m>>n;
    vector<vector<int>> a(m+1);
    for(int i=0;i<m-1;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<int> d(m+1,n);
    vector<int> b(m+1,0);
    d[1]=d[1]+2;
    for(int i:a[1]){
        d[i]++;
    }
    queue<int> q;
    q.emplace(1);
    b[1]=1;
    while(!q.empty()) {
         int k=q.front();
         d[k]-=2;
         q.pop();
         int count=0;
         for(int i:a[k]){
            if(b[i]==0){
                b[i]=1;
                q.emplace(i);
                d[i]-=count;
                count++;
            }
         }
    }
    long long ans=1;
    for(int i=1;i<m+1;i++){
         ans*=d[i];
         ans=ans%u;
    }
    cout<<ans%u;
}