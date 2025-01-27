#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string a;
    vector<int> b(5, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a[0] == 'M')
        {
            b[0]++;
        }
        if (a[0] == 'R')
        {
            b[1]++;
        }
        if (a[0] == 'C')
        {
            b[2]++;
        }
        if (a[0] == 'H')
        {
            b[3]++;
        }
        if (a[0] == 'A')
        {
            b[4]++;
        }
    }
    vector<long long> values;
    for(int i=0;i<5;i++){
        if(b[i]>0) {
        values.push_back(b[i]);
        }
    }
    long long result = 0;
    int size = values.size();
    if(size<3){
        cout<<0<<endl;
        return 0;
    }
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            for (int k = j + 1; k < size; k++) {
                result += values[i] * values[j] * values[k];
            }
        }
    }
    cout<<result<<endl;
}