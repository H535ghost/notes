#include <iostream>
#include<vector>
#include<array>
#include <algorithm>
using namespace std;
#define A "Accepted"
#define R "Rejected"
#define G "Running"
#define N 2000000000
int main(){
    int n;
    cin>>n;
    while(n--){
        int a,time,num;
        cin>>a>>time>>num;
        vector<array<int,3>> n(num,{0,0,0});
        for(int i=0;i<num;i++)
        {
            int x,t;
            string s;
            cin>>t>>x>>s;
            n[i][0]=x-1;n[i][1]=t;
            if(s==R) {n[i][2]=-1;}
            else if(s==A){n[i][2]=0;}
            else if(s==G){n[i][2]=1;}
        }
         vector<array<int ,2>> ans(a,{N,N});
        for(int i=0;i<num;i++){
        if(n[i][2]>-1){
            if(ans[n[i][0]][n[i][2]]>n[i][1]){ long long re=n[i][1];
                                            for (int j=0;j<num;j++)
        {
            if(n[j][0]==n[i][0]&&n[j][2]==-1&&n[j][1]<n[i][1]){re=re+20;}
        }
        if(ans[n[i][0]][n[i][2]]>re){ans[n[i][0]][n[i][2]]=re;}
                                           }
                      } 
        }
        vector<int> k(a,-1),l(a,N);long long max=0,min=N;int count=0,d=0;
        for(int i=0;i<a;i++){
            if(ans[i][0]!=N)  {count++;if(ans[i][0]>ans[i][1]){k[i]=ans[i][1];}else{k[i]=ans[i][0];}}
            if(ans[i][0]==N&&ans[i][1]!=N){l[i]=ans[i][1];}
        }
        for(int i=0;i<a;i++){if(ans[i][0]!=N){if(ans[i][0]>ans[i][1]){max=max+ans[i][1];}else{max=max+ans[i][0];}}}
        sort(l.begin(),l.end());
        for(int i=1;i<=a;i++){
            if(i<count)  { cout<<"-1"<<" ";}
            else {if(i==count){ cout<<max<<" ";}
            else {
                if(l[i-1]==N){cout<<"-1"<<" ";}
                else {max=max+l[i-1];cout<<max<<" ";}
                }
      }
    }
    cout<<endl;
  }
}