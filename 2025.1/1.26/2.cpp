#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    char a;
    for(int i=0;i<n;i++){
         cin>>a;
         if( a=='Y'){
             cout<<"Four";
             return 0;
         }
         else{
            if(i==n-1){
                cout<<"Three";
                return 0;
            }
         }
    }
    cout<<"Three";

    }