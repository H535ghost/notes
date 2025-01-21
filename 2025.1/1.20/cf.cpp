#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,k,e,o,ans;
    cin>>n;
    for(int i=0;i<n;i++){
          cin>>k;
          e=0;o=0;ans=0;
          vector<int> a(k,0);
          for(int j=0;j<k;j++){
            cin>>a[j];if((a[j]-1)/2==a[j]/2){o++;}
            else{e++;}
          }
        if(e){ans=1;}
        else{
            if(o) ans=-1;
        }
        ans=ans+o;
        cout<<ans<<endl;
    }
}