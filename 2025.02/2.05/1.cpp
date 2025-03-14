#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,k=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        while(v[i]%2==0){
            v[i]=v[i]/2;
            k=k+1;
        }
    }   
    cout<<k<<endl;
}