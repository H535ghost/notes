#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    long long n;
    cin>>n;
    vector<long long> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    cout<<a[n/2]-a[n/2-1];
}