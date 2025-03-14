#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
#include <math.h>
#include <string>
using namespace std;
int main()
#define int long long
{
std::ios::sync_with_stdio(false);
std::cin.tie(0);
std::cout.tie(0);
    string s,t;
    cin>>s>>t;
    vector<vector<int>> a(s.size()+1,vector<int>(2,0)),b(t.size()+1,vector<int>(2,0));
    for(int i=1;i<s.size()+1;i++){
        a[i][0]=(a[i-1][0]+(s[i-1]=='A'))%3;
        a[i][1]=(a[i-1][1]+(s[i-1]=='B'))%3;
    }
    for(int i=1;i<t.size()+1;i++){
        b[i][0]=(b[i-1][0]+(t[i-1]=='A'))%3;
        b[i][1]=(b[i-1][1]+(t[i-1]=='B'))%3;
    }
    int n;
    cin>>n;
    int x,y,u,v;
    for(int i=0;i<n;i++){
        cin>>x>>y>>u>>v;
        if(((a[y][0]-a[x-1][0])-(b[v][0]-b[u-1][0])+(a[y][1]-a[x-1][1])*2-(b[v][1]-b[u-1][1])*2)%3==0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}