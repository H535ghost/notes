#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y,z,m,n;
    cin>>m>>n;
    vector<vector<pair<int,int>>> a;
    vector<pair<int,int>> b(1,{-1,-1});
    for(int i=0;i>n;i++){
           cin>>x>>y>>z;
           while(z>a.size()){a.push_back(b);}
           a[z].push_back({x,y});
    }
    
}