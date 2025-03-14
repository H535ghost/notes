#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<string> a(n);
    vector<int> ans(26,1e5),b(26,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i].size();j++){
            b[a[i][j]-'a']++;
        }
        for(int j=0;j<26;j++){
            ans[j]=min(ans[j],b[j]);
            b[j]=0;
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<ans[i];j++){
            cout<<char(i+'a');
        }
    }
    cout<<endl;
}