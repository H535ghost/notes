#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;
    cin>>m>>n;
    if(m*n<=0){
           cout<<"Zero";
    }
    else if(m>0&&n>0){
        cout<<"Positive";
    }
    else if((m-n)%2==0){
        cout<<"Negative";
    }
    else{
        cout<<"Positive";
    }
}