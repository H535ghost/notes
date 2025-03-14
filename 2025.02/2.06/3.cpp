#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main(){
    int n,m;
    cin>>m>>n;
    vector<int> a(n);
    set<char> s;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert('0'+a[i]);
    }
    int d=0;
    string ans;
    while(1){
        d=0;
        ans=to_string(m);
        for(char i:ans){
            if(s.find(i)==s.end()){
                d++;
            }
        }
        if(d==ans.size()){
            cout<<ans;
            return 0;
        }
        m++;
    }
}