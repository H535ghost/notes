 #include <iostream>
#include<vector>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
              int m=sizeof(ops);
              int n=sizeof(*root);
              vector<int> a(n,0);
              for(int i=0;i<m;i++){
                  for(int j=0;j<n;j++){
                   
                  }
              }
    }
};