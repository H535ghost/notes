#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(5, 0);
    for (int i = 0; i < n; i++)
    {
        int ans = 0, max = 0;
        for (int j = 0; j < 5; j++)
        {
            cin >> a[j];
            if (j == 1)
                j++;
        }
        for (int j = 0; j < 3; j++)
        {
            ans=0;
            if (j == 0)
            {
                a[2] = a[0] + a[1];
            }
            if (j == 1)
            {
                a[2] = a[3] - a[1];
            }
            if (j == 2)
            {
                a[2] = a[4] - a[3];
            }
            for (int j = 0; j < 3; j++)
            {
                if (a[j + 2] == a[j] + a[j + 1])
                {
                    ans++;
                }
            }
            if(ans>max) {max=ans;}
        }
        cout<<max<<endl;
    }
}