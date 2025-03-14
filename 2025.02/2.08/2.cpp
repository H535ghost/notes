#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int m;
    cin>>m;
    vector<int> a(m,0);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    int k=a.size();
    cout<<a[k/2+1];
}