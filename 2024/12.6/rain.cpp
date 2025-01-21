#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    string a;
    for(int i=0;i<n;i++){
        cin>>a;
        if((a[0]=='y'||a[0]=='Y')&(a[1]=='c'||a[1]=='C')&(a[2]=='y'||a[2]=='Y')&a.size()==3){cout<<"ERROR"<<endl;}
        else{
            cout<<a<<"txdy"<<endl;
        }
    }
}