#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<long long > a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k=0;
    for(int i=1;i<n-1;i++){
        if((a[i+1]-a[i])*(a[i-1]-a[i])<0) k++;
    }
    cout<<k;
}