#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;
int main(){
  string s;
  cin>>s;
  for(int i=s.size()-1;i>=0;i--){
    
  }
  for(int i=0;i<=s.size();i++)
  {
    if(s[i+1]=='.'){
        if(s[i+2]>='5')
        cout<<s[i]+1;
        else{
            cout<<s[i];
        }
        break;
    }
    cout<<s[i];
  }
}