#include <tuple>
#include <iostream>
# include <string>
using namespace std;
bool operator==(const std::tuple<int, double>& t1, const std::tuple<int, double>& t2) {
    return std::get<0>(t1) == std::get<0>(t2) && std::get<1>(t1) == std::get<1>(t2);
}
int main()
{
    auto a=make_tuple(1 ,3.14);
    auto b=make_tuple(1 ,3.14);
    int m;double n;
    if(a==b) cout<<"y"<<endl;
    tie(m,n)=a;
    m=2;
    if(a==b) cout<<"ok"<<get<0>(a);
    
}

