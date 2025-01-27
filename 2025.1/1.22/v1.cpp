#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
       int l,n,d=1;
       cin>>l>>n;
       vector<int> a(n,0);
       for(int i=0;i<n;i++){
              cin>>a[i];
       }
       int mi=0,ma=0;
      for(int i=0;i<n;i++){
            mi=max(mi,min(a[i],l-a[i]+1));
       }
       cout<<mi<<" ";
          vector<int> b(n,0);
          b[0]=1;
          for (int i = 1; i < n; i++)
          {
              b[i]=-b[i-1];
          }
          int t=0;
          vector<int> c(n,0);
       while(d){
              sort(a.begin(),a.end());
              for(int i=0;i<n;i++){
              if(a[i+b[i]]==a[i]+b[i]&&b[i]!=b[i+b[i]])
              {b[i]=-b[i];b[i+b[i]]=-b[i+b[i]];}
              else{
                     if(a[i]!=-1){
                  a[i]+=b[i];}
                  }
              }
              t++;
              for(int i=0;i<n;i++ ){
                     if(a[i]==0||a[i]==l+1){
                            c[i]=1;
                            a[i]=-1;
                     }
              }
              for(int i=0;i<n;i++){
                     if(c[i]==0){break;}
                     else{
                            if(i==n-1){
                                   cout<<t;d=0;
                            }
                     }
              }
       }
       
}