#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    string d;
    int k;
    vector<string> v(m);
    for(int i=0;i<m;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<m;i++){
        cout<<v[i];
    }
}