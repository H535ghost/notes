#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
#define  int long long
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> q(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    sort(q.begin(), q.end(), greater<int>());
    vector<int> p;
    int k = 1;
    for (int i = a - 1; i > 0; i--)
    {
        if (q[i] == q[i - 1])
        {
            k++;
        }
        else
        {
            break;
        }
    }
    int m = k;
    for (int i = a - 1; i < n-1; i++)
    {
        if (q[i] == q[i + 1])
        {
            m++;
        }
        else
        {
            break;
        }
    }
    double ans = 0;
    int d = 1;
    for (int i = 0; i < a; i++)
    {
        ans = ans + q[i];
    }
    ans = ans / a;
    int x = ans;
    int y = (ans - x) * 1000000;
    if (ans == x)
    {
        cout << x << ".000000" << endl;
    }
    else
    {
        cout << x << '.' << y << endl;
    }

   
    /*long long ns = 1;
    int z = m;
    if (ans == q[a - 1])
    {
        long long as = 0;
        for (int i = a; i <= b; i++)
        {
            int n = i;
            int d = 1;
            ns = 1;
            m = z;
            while (n > 0)
            {
                ns = ns * m / d;
                m--;
                d++;
                n--;
            }
            
            as = ns + as;
            
        }cout << as ;
    }*/
    long long ns = 1;
    int z = m;
    if (ans == q[a - 1])
    {
        int as = 0;
        for (int i = a; i <= b; i++)
        {
           int n = i;
           int d = 1;
            m = z;
            ns=1;
            while (n > 0){
            ns = ns * m / d;
            m--;
            d++;
            n--;} 
        as = ns + as;
        }
      
        cout << as;
    }
    else{
    n = 1;
    while (k > 0)
    {
        ns = ns * m / n;
        m--;
        n++;
        k--;
    }
    cout << ns;
    }
}