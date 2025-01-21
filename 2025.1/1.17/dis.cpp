#include <iostream>
#include <vector>
using namespace std;
int main (){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(2,0)),b(m,vector<int>(2,0));
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    for(int i=0;i<m;i++){
        cin>>b[i][0]>>b[i][1];
    }
    long long min;
    int d;
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
           min=9999999999999;
           d=-1;
           for(int j=0;j<m;j++){
            if((abs(b[j][0]-a[i][0])+abs(b[j][1]-a[i][1]))<min){
             min=abs(b[j][0]-a[i][0])+abs(b[j][1]-a[i][1]);
             d=j;
            }
           
           } cout<<d+1<<endl;
    }
}