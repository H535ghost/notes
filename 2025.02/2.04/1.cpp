#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int m,n,k=0,d=0;
    cin>>m>>n;
    d=n;
    while(d/100>0){
        d=d/100;
        k=k+d;
    }
    n=n+k;
    for(int i=0;i<m;i++){
        n=n*100;
    }
    cout<<n<<endl;
}