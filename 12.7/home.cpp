#include <iostream>
#include<vector>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m,0));
    long long count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
             k=a[i][j];
            if(k<a[i][j-1]&&k<a[i][j+1]&&k<a[i+1][j-1]&&k<a[i+1][j]&&k<a[i+1][j+1]&&k<a[i-1][j-1]&&k<a[i-1][j]&&k<a[i-1][j+1]){count++;}
        }
    }
    cout<<count;
}
