#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,x;
    cin>>n>>m;
    vector<long long> a(200001,0);
    for(int i=0;i<n;i++){
        cin>>x;
        a[x]++;
    }
    priority_queue <long long> ans;
    for(auto i:a){
        if(i>0)  ans.emplace(i);
    }
    for(int i=0;i<m;i++){
        if(!ans.empty())
        ans.pop();
    }
    x=0;
    while(!ans.empty()){
        x=x+ans.top();
        ans.pop();
    }
    cout<<x;
}