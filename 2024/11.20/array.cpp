#include <iostream>
using namespace std;
#include <vector>
#include<array>
int main(){
    array<int,3> a {1,2,3};
    array<int,0>::iterator q;
    vector<int> b {1,2,3};
    vector<int>::iterator p;
    p=b.begin();
    cout<<*q;
}