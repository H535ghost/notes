#include <iostream>
#include <vector>
#include <queue>
#include<math.h>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    if(n-m>=2018){
        cout<<0;
        return 0;
    }
    m=m%2019;
    n=n%2019;
    long long ans=1e9+7;
    if(m>n){
        for(int i=m;i<n+2019;i++){
            for(int j=i+1;j<=2019+n;j++){
                if(ans>(i*j)%2019)  {ans=(i*j)%2019;}
            }
        }cout<<ans;return 0;
    }
    if(m<n){
        for(int i=m;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(ans>(i*j)%2019)  {ans=(i*j)%2019;}
        }
    }cout<<ans;return 0;
}
}