PROBLEM:https://leetcode.com/problems/invert-binary-tree/description/
VIDEO:
BLOG:

/*
SELF
TC:O(N)
SC:O(N)  //auxiliary stack space

*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //base case
       if(!root || (!root->left && !root->right)) return root;
       //hypothesis
       invertTree(root->left);
       invertTree(root->right);
       //induction step.....simply swap the childs
       TreeNode* temp=root->left;
       root->left=root->right;
       root->right=temp;
       //final step....return root
       return root;


    }
};
