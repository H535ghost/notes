#include <vector>
#include <string>
 
using namespace std;
 
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.empty()) return "";
        if (nums.size() == 1) return to_string(nums[0]);
        if (nums.size() == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        
        string ans = to_string(nums[0]) + "/(";
        for (int i = 1; i < nums.size(); ++i) {
            ans += to_string(nums[i]);
            if (i != nums.size() - 1) {
                ans += "/";
            } else {
                ans += ")";
            }
            if (i != nums.size() - 2) { // 除了倒数第二个元素外，每个元素后都加")"
                ans += ")";
            }
        }
        // 注意：上面的逻辑可以简化，因为我们已经知道当i是最后一个元素时，不需要再加"/"而是直接加")"
        // 下面的简化版本更为直观和高效
        
        // 简化版
        string result = to_string(nums[0]) + "/(";
        for (int i = 1; i < nums.size() - 1; ++i) {
            result += to_string(nums[i]) + "/";
        }
        result += to_string(nums.back()) + ")";
        
        return result;
    }
};