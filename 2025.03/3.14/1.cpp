#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    string q;
    cin>>q;
    vector<int> s(q.size(),0);
    for(int i=0;i<s.size();i++){
        if(q[i]=='R') s[i]=1;
    }
    vector<int> a(s.size(),0);
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1])  a[i]=a[i-1]+1;
    }
    int p=-1,u=-1,v=-1;
    for(int i=1;i<s.size();i++){
        if(a[i]==0) {p++;u=v;v=i;}
        if(p==1) {
            k--;
            p=-1;
            a[u]=1;
            a[v]=1;
           
            if(k==0) break;
        }
    }
    if(k>0){
        if(a[1]==0){a[1]=1;k--;}
        
    }
    long long ans=0;
    for(int i=0;i<s.size();i++){
          if(a[i]>0) ans++;
    }
    
    if(p==0&&k>0)  ans++;
    cout<<ans;
}