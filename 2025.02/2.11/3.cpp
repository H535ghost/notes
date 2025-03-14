#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string s;
    cin>>s;
    int k=1,y=0;
    char d;
    for(int i=1;i<4;i++){
        if(s[i]==s[0] )  k++;
        if(s[i]!=s[0] )  d=s[i];
    }
    for(int i=0;i<4;i++){
        if(s[i]==d)  y++;
    }
    if(k==2&&y==2){cout<<"Yes";}
    else{
        cout<<"No";
    }
}