PROBLEM:https://leetcode.com/problems/range-sum-of-bst/
VIDEO:

/*
METHOD 1
SIMPLE PREORDER TRAVERSAL
TC:O(N)
SC:O(N) //auxiliary space for recursion

*/

class Solution {
private:
void helpSum(TreeNode* root, int low, int high,int &sum){
    if(!root)
    return ;
    if(root->val>=low && root->val<=high){
        sum+=root->val;
    }
    helpSum(root->left,low,high,sum);
    helpSum(root->right,low,high,sum);

}
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        helpSum(root,low,high,sum);
        return sum;
    }
};
