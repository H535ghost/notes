#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int n = height.size();
        vector<int> left_max(n), right_max(n);
        int sum = 0;
        
        // 计算每个位置左侧的最大高度
        left_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        
        // 计算每个位置右侧的最大高度
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }
        
        // 计算水量
        for (int i = 1; i < n - 1; i++) {
            int water = min(left_max[i], right_max[i]) - height[i];
            if (water > 0) {
                sum += water;
            }
        }
        
        return sum;
    }
};
