PROBLEM:https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
video:https://www.youtube.com/watch?v=eD3tmO66aBA&t=400s
/*
TC:O(N)
SC:O(N) //auxiliary stack space
*/


class Solution {
public:
    int maxDepth(TreeNode* root) {
      if(!root)return 0;
      int left=maxDepth(root->left);
      int right=maxDepth(root->right);
      return 1+max(left,right); 
    }
};
