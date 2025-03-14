#include <iostream>
#include <vector>
#include <queue>
#include<math.h>
using namespace std;
int main() {
    long long n;
    cin>>n;
    vector<long long> a(n,0);
    vector<long long> b(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(i%2==0)
       b[0]+=a[i];
      else{b[0]-=a[i];}
    }
    for(int i=1;i<n;i++){
        b[i]=(a[i-1]-b[i-1]/2)*2;
    }
     for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
     }
}