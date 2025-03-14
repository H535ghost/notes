#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<string> a(m);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        if(a[i].find('#')==string::npos){
            a.erase(a.begin()+i); m--;i--;
        }
       
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[j][i]=='#'){break;}
            else{if(j==m-1){
                for(int k=0;k<m;k++){
                    a[k].erase(i,1);
                }
                i--;n--;
            }
        }
    }
}
    for(int i=0;i<m;i++){
        cout<<a[i]<<endl;
    }
}