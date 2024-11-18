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
 int find(TreeNode*a,vector<int> x,int sum){
    int ans=0;
    x.push_back(0);
    for(vector<int>::iterator k=x.begin();k!=x.end();k++)
    {*k=*k+a->val;
    if(*k==sum){ans++;*k=-999;}}
    if(a->left!=NULL){
       ans=ans+find(a->left,x,sum);
        for(vector<int>::iterator k=x.begin();k!=x.end();k++)
    {*k=*k-a->val;
       x.pop_back();
    }}
     if(a->right!=NULL){
       ans=ans+find(a->right,x,sum);
        for(vector<int>::iterator k=x.begin();k!=x.end();k++)
    {*k=*k-a->val;
       x.pop_back();
    }}
    return ans;
 }
class Solution {
public:
vector<int> a;
    int pathSum(TreeNode* root, int targetSum) {
       return find(root,a,targetSum);
    }
};
