#include <bits/stdc++.h>
using namespace std;
int main()
#define int long long
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    vector<long long> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i=n-1;i>0;i--){
        a[i]=a[i]-a[i-1];
    }
    long long sum=0;
    long long k=0;
    for(int i=0;i<n;i++){
        sum+=a[i]-1;
    }
    k=sum+n;
    if(sum){

    }
}