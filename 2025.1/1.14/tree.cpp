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
public:
    vector<int> rightSideView(TreeNode* root) {
        TreeNode* a=root,*b=NULL;
        int num=1;
        vector<int> ans;
        ans.push_back(root->val); 
        while(root->right!=NULL) {
            a=root->right;
            ans.push_back(a->val);
            num++;  
             if(a->left!=NULL){
             b=a->left;    
        } 
        }
     
    }
};