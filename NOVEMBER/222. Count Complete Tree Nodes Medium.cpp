PROBLEM:https://leetcode.com/problems/count-complete-tree-nodes/
 VIDEO:

/*
INITIAL APPROACH
PSEUDO CODE:
1.if root is null return 0
2.call left ,call right 
3.return 1+left+right
TC: o(n)
SC:
*/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
