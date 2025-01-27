#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x;
    x=min(b,d)-max(a,c);
    if(x>0){
        cout<<x;
    }
    else{
        cout<<0;
    }
}