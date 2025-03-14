#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;
long long dfs(int i){
    if(i==1) return 1;
    long long ans=1;
    for(int j=0;j<i-1;j++){
             ans*=5;
    }
    return ans;
}
int main() {
    long long n;
    vector<int>a;
    cin>>n;
    long long m=n,k=0;
    while(m>0){
        a.push_back(m%10);
        m=m/10;
        k++;
    }
    long long ans=0;
    ans+=(a[k-1]/2)*dfs(k);
    if(a[k-1]%2==0&&k%2==0) ans-=dfs(k);
    for(int i=1;i<k;i++){
        ans+=5*dfs(i);
        if(i%2==0)
        ans-=dfs(i);
    }
    for(int i=1;i<k;i++){
        if((a[k-i]%2)^((k-i+1)%2)==0){

        ans+=(a[k-i-1]/2)*dfs(k-i);
        if(a[k-i-1]%2==1&&(k-i)%2==0) ans+=dfs(k-i);
        }
        else{
            break;
        }
        if(i==k-1&&a[0]%2==1) ans++;
    }
    if(k==1&&n%2==1) ans++;
    cout<<ans;
}