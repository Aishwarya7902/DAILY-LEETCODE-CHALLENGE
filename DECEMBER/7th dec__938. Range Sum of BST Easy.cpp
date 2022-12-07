PROBLEM:https://leetcode.com/problems/range-sum-of-bst/
VIDEO(AYUSHI SHERMA):https://www.youtube.com/watch?v=wIloFJzSOfE

/*
METHOD 1
SIMPLE PREORDER TRAVERSAL
TC:O(N)
SC:O(h) //auxiliary space for recursion

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

/*
METHOD 2
making use of the fact that it is a BST
TC:O(N)
SC:O(h) 
*/

class Solution {
private:
void helpSum(TreeNode* root, int low, int high,int &sum){
    if(!root)
    return ;
    if(root->val>=low && root->val<=high){
        sum+=root->val;
    
    helpSum(root->left,low,high,sum);
    helpSum(root->right,low,high,sum);
    }
    else if (root->val<low){
       helpSum(root->right,low,high,sum); 
    }
    else{
        helpSum(root->left,low,high,sum);
    }

}
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        helpSum(root,low,high,sum);
        return sum;
    }
};
