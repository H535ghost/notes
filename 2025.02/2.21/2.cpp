#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;
int main() {
    string a,b;
    cin>>a>>b;
    for(int i=0;i<b.size();i++){
        cout<<a[i]<<b[i];
    }
    if(a.size()>b.size()){
        cout<<a.back();
    }
}