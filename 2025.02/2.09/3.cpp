#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int m,n;
    long long k;
    cin>>m>>n;
    vector<int> a(50,0);
    for(int i=0;i<m;i++){
        cin>>k;
        a[k]++;
    }
    long long ans=1;
    k=0;
    
}