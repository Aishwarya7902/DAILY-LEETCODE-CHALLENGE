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

/*METHOD 2

We pass the minimum and maximum values to the children,
At the leaf node, we return max - min through the path from the root to the leaf.
TC:O(N)
SC:O(N)
*/

class Solution {
private:
int helper(TreeNode* node,int currMax,int currMin){
  if(!node)
    return currMax-currMin;
 currMax=max(currMax,node->val);
 currMin=min(currMin,node->val);
 int left=helper(node->left,currMax,currMin);
 int right=helper(node->right,currMax,currMin);
 return max(left,right);
}

public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
         return 0;
         return helper(root,root->val,root->val);
    }
};
