#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int h, w, d, k;
    cin >> h >> w >> d;
    vector<vector<int>> a(w * h, vector<int>(2));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {   
            cin >> k;
            a[k - 1][0] = i;                          
            a[k - 1][1] = j;                      
        }                                      
    } 
    long long q,l,r;
    cin >> q;
    vector<long long> x(h*w,0);
    for(int i=0;i<h*w;i++){
        if(i+d<h*w){
            x[i+d]=x[i]+abs(a[i+d][0]-a[i][0])+abs(a[i+d][1]-a[i][1]);
        
    }}
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        int ans = x[r-1]-x[l-1];
        cout<< ans << endl;
    }
}
