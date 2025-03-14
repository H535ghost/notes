#include <iostream>
#include <vector>
#include <queue>
#include<math.h>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<int>> a(m,vector<int> (n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    long long ans=0;
    double x;
    long long y,d;
    for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            x=0;y=0;d=0;
             for(int k=0;k<n;k++){
                d=d+abs((a[i][k]-a[j][k])*(a[i][k]-a[j][k]));
             }
          
             for(int k=0;k<150;k++){
                if(d==k*k)  {ans++;break;}
             }
        }
    }
    cout<<ans;
}