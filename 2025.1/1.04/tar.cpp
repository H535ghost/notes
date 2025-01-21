#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &target, vector<int> &arr)
    {
        int t = target.size(), a = arr.size();
        int m, k = 0;
        vector<int> dp(a, 0);
        for (int i = 0; i < a; i++)
        {
            m = arr[i];
            if ( k == 0)
            {
                for (int j = 0; j < t; j++)
                {
                    if(m==target[j]) dp[j]++;
                }
            }
        }
    }
};