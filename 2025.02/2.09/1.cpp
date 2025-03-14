#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>b)  cout<<b*c+(a-b)*d;
    else{
        cout<<a*c;
    }
}