#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    int m,n;   
    for(int i=0;i<3;i++){
        if(a[i]==5) {
            m++;
        }
        else if(a[i]==7){
            n++;
        }
    }
    if(m==2 && n==1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }   
}