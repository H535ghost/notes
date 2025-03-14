#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    long long ans=1e9,x,y=0;
    cin>>n;
    for(int i=0;i<n;i++){
        y=0;
        cin>>x;
        while(x%2==0){
            x=x/2;
            y++;
        }
        ans=min(ans,y);
    }
    cout<<ans;
}