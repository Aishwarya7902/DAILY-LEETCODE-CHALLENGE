PROBLEM:https://leetcode.com/problems/count-complete-tree-nodes/
 VIDEO: (striver bhaiya):https://www.youtube.com/watch?v=u-yWemKGWO0

/*
INITIAL APPROACH
PSEUDO CODE:
1.if root is null return 0
2.call left ,call right 
3.return 1+left+right
TC: o(n)
AUXIALIARY SPACE:  o(h) and in worst case the height of a complete binary tree is log(n)
*/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
