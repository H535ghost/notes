#include <iostream>
using namespace std;
class Solution {
public:
    int smallestValue(int n) {int ans=n,k=0;
        while(ans>1){
         n=ans;
         k=ans;
         ans=0;
         if(ans!=k){
    for(int i=2;i<=n;i++){
            while(n%i==0){
                n=n/i;
                ans=ans+i;
                cout<<ans<<endl;
            }
    }
    }
    }return k;
    }
};
Solution a;
int main(){
    int n;
    cin>>n;
    cout<< a.smallestValue(n);
}