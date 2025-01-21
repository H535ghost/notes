#include <iostream>
#include<vector>
#include<array>
#include <algorithm>
using namespace std;
int main(){
    int n;cin>>n;vector<vector<int>> a(n,vector<int>(3,0));
    int max=99999999,d=0; 
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    for(int j=0;j<n;j++){
        max=-1;d=-1;
    for(int i=j;i<n;i++)
    {      if(a[i][1]==max){
             if(a[i][2]==a[d][2]){
              if(a[i][0]<a[d][0]){
                d=i;
              } 
            }
            else{
                if(a[i][2]<a[d][2]){d=i;}
            }
        }
        if(a[i][1]>max){max=a[i][1],d=i;}
    }
    cout<<a[d][0]<<" "<<a[d][1]<<" "<<a[d][2]<<endl;
    for(int i=0;i<3;i++){
        max=a[d][i];
    a[d][i]=a[j][i];
    a[j][i]=a[d][i];
    }
}
}