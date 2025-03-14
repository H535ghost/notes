#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;
    cin>>n>>m;
    vector<int> num(n+1,1),col(n+1,0);
    col[1]=1;
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
         num[y]++;
            num[x]--;
        if(col[x]==1){
            col[y]=1;
            if(num[x]==0)
            {
                col[x]=0;
            }
       
        }
    }
    long long ans=0;
    for(int i=1;i<n+1;i++){
           if(col[i]==1) ans++;
    }
    cout<<ans;
  }