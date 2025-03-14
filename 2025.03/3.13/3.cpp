#include <bits/stdc++.h>
using namespace std;
int main()
#define int long long
{
    long long n;
    cin>>n;
    vector<long long > a(n+1,0),b(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    b=a;
    int k=0;
    for(int i=n;i>0;i--){
        k=2*i;
        while(k<=n){
            b[i]+=a[k];
            k+=i;
        }
        if(b[i]<0){
            k=i;
            while(k<=n){
                a[k]=0;
                k+=i;
            }
        }
   }
   long long sum=0;
   for(int i=1;i<n+1;i++){
      sum+=a[i];
   }
   cout<<sum;
}