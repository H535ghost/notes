#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;
int dfs(long long a){
    if(a%10==0){
        return 0;
    }
    int l=0;
    while(a>0){
        l++;
        int k=a%10;
        a=a/10;
        if((l % 2 == 1 && k % 2 == 0) || (l % 2 == 0 && k % 2 != 0)){
            return 0;
        }
    }
    return 1;
}
int main(){
    long long n;
    long long ans=0;
    cin>>n;
    for(long long i=1;i<n+1;i++){
        ans+=dfs(i);
    }
    cout<<ans;
}