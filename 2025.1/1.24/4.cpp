#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long ma=1;
    vector<long long> v(n);
    for(int i=0;i<n;i++){
     cin>>v[i];
     ma=ma/__gcd(ma,v[i])*v[i];
    }
    while(1){
        bool flag=true;
        for(int i=0;i<n;i++){
            if(ma%v[i]!=0){
                ma=ma/__gcd(ma,v[i]);
                flag=false;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    cout<<ma;
}