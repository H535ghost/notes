#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;
int main() {
    long long m=0,n=0;
    long long min=0,x=0,y=0,sum=0;
    cin>>m>>n;
    vector<vector<long long>> a(m,vector<long long> (2,0));
    for(int i=0;i<m;i++){
        cin>>a[i][0]>>a[i][1];
     
        sum+=a[0][i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++){
        cout<<a[i][0]<<a[i][1]<<endl;
    }
}