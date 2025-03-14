#include <bits/stdc++.h>
using namespace std;

int main()
#define int long long
{
    int n=0;
    cin>>n;
    string s;
    map<string,int> k;
    vector<vector<int>> a(n,vector<int> (26,0)); 
    for(int i=0;i<n;i++){
         cin>>s;
         sort(s.begin(),s.end());
         k[s]++;
    }
    long long ans=0;
    for(auto i:k){
        ans=ans+(i.second*(i.second-1))/2;
    }
    cout<<ans;
}