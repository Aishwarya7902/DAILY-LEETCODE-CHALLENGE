PROBLEM:https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
VIDEO:

/*
NAIVE SOLUTION (ON MY OWN)
TC:O(N^2)
SC:O(N^2)

*/

class Solution {
private:
void help(TreeNode* root,TreeNode* node,int & diff){
    if(!root || !node)return;
    diff=max(diff,abs(root->val-node->val));
    help(root,node->left,diff);
    help(root,node->right,diff);
}
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root)return 0;
     int curr1=maxAncestorDiff(root->left);
     int curr2=maxAncestorDiff(root->right);
     int diff1=INT_MIN;
     int diff2=INT_MIN;
     help(root,root->left,diff1);
     help(root,root->right,diff2);
     return max(diff1,max(diff2,max(curr1,curr2)));

    }
};
