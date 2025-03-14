#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin>>s;
    int k=s.size();
    vector<long long> a(24);
    for(int i=0;i<k;i++){
        a[s[i]-'a']++;
    }
    for(int i=0;i<24;i++){
        if(a[i]%2)  {cout<<"No";return 0;}
    }
    cout<<"Yes";
}