#include <iostream>
using namespace std;
#include <vector>
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
private:
    int findPaths(TreeNode* node, vector<long long>& pathSums, int targetSum) {
        if (!node) return 0;

        int count = 0;
        // 更新路径和
        for (long long& sum : pathSums) {
            sum += node->val;
            if (sum == targetSum) {
                count++;
            }
        }

        // 当前节点也可以作为路径的起点
        pathSums.push_back(static_cast<long long>(node->val));
        if (node->val == targetSum) count++;

        // 递归到左右子树
        count += findPaths(node->left, pathSums, targetSum);
        count += findPaths(node->right, pathSums, targetSum);

        // 回溯，恢复状态
        for (long long& sum : pathSums) {
            sum -= node->val;
        }
        pathSums.pop_back();

        return count;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> pathSums; // 用于存储当前路径的累加和，使用 long long 避免溢出
        return findPaths(root, pathSums, targetSum);
    }
};
