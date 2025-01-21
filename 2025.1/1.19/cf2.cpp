#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int m, n, k, d,y;
    cin >> m;   
    for (int i = 0; i < m; i++)
    { 
        cin >> n >> k;
        d = 0;
        int p=max(k,n);
        vector<int> a(p+1,0);
        for (int j = 0; j < n; j++)
        {
            cin>>y;
            a[y]++;
        }
        for (int j = 1; j <k/2; j++)
        {
            d=d+min(a[j],a[k-j]);
        }
        if(k/2==(k-1)/2){
            d=d+min(a[(k-1)/2],a[(k+1)/2]);
        }
        else{
            d=d+a[k/2]/2;
        }
        cout<<d<<endl;
    }
}