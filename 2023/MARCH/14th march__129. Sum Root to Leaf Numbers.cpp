PROBLEM:https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
VIDEO(MAZHAR BHAIYA):https://www.youtube.com/watch?v=KTwkq-MsJDw

/*
TC:
SC:
*/

class Solution {
int solve(TreeNode* root,int curr){
    if(!root)return 0;
    curr=(curr*10)+root->val;
    if(root->left==NULL && root->right==NULL)return curr;
    int l=solve(root->left,curr);
    int r=solve(root->right,curr);
    return l+r;
}
public:
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};
