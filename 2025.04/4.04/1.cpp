#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
using vvi=vector<vi>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        y=y*0.6+min(100,x+10)*0.4;
        if(y>=60)  cout<<"Pass\n";
        else{
            cout<<"Fail\n";
        }
        }
}