#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define inf -99999
int main()
{
       int n;
       cin>>n;
       vector<int> v(n);
       for(int i=0;i<n;i++){
                cin>>v[i];
       }
       vector<int> a(n,-1);
       int k,d; 
        vector<int> ans(n,0);
        ans=v;
       for(int i=0;i<n-1;i++){
                cin>>k>>d; 
                a[k-1]=d-1;
       }
       for(int i=0;i<n;i++){
                if(a[i]!=-1){
                        ans[i];
                }
       }
    sort(ans.begin(),ans.end());
    long long count=0;
    for(int i=0;i<n;i++)
    {
        if(ans[i]!=inf){
            count+=v[i];
            ans[i]=inf;
            for(int j=0;j<n;j++){
                if(a[j]==i){
                    ans[j]=inf;
                }
            }
        };
    }
    cout<<count;
}

