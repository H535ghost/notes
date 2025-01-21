#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    a=(a+12)%14;
    b=(b+12)%14;
    if(a>b){
        cout<<"Alice";
    }
    else{if(a==b)
    cout<<"Draw";
    else{
        cout<<"Bob";
    }
    }

}