#include <iostream>
#include <vector>
#include<math.h>
using namespace std;
int main (){
    long long n;
    cin>>n;
    long long a=sqrt(n)+1;
    long long k=n;
    for( int i=a;a>0;i--){
        if(n%i==0) { k=i ;break;} 
    }
 k=n/k;
    long ans=0;
    while(k>0){
        k=k/10;
        ans++;
    }
    cout<<ans;
}