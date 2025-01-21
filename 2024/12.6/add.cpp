#include <iostream>
using namespace std;
int main(){
    int n=0;
    long a=0,b=0,k,x,z=1,m=1;
    cin>>n;
    for(int i=0;i<n;i++){
        z=1,m=1;
        cin>>a>>b;
        long long y=0;
        for(long j=0;j<a;j++){
            cin>>x;
            y=y+x;
        } 
        if(y==0){
            for(long j=0;j<b;j++){
                cin>>x;if(x==0){m=0;}
            }
              if(y==m) {cout<<"YES"<<endl;}    
             else{cout<<"NO"<<endl;}     
        }     
        else{ m=y;int z=0;
        for(long j=0;j<b;j++){    
            cin>>x;
            if(m%x){z=1;}
               m=m/x;
               } 
            if(z==0&&m==1) {cout<<"YES"<<endl;}    
            else{cout<<"NO"<<endl;}  
            }
        }
    }

