#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int k=max(m,n); 
    if(k<=8){
        cout<<"Yay!"<<endl; 
    }
    else{
        cout<<":("<<endl;
    }
}