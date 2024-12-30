#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans; int k=nums[1];
        for(int i=2;i<nums.size();i++){
            k=k/nums[i];
        }
        ans=to_string(nums[0]/k);
        return ans;
    }
};