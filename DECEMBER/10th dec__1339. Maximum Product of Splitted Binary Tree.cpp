PROBLEM: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

video (BEST VIDEO EVER) :https://www.youtube.com/watch?v=ITySQXe9Ybg

/*
METHOD 1:
TC:
SC:
*/

class Solution {
private:
long SUM=0;
long maxP=0;
int totalSum(TreeNode* root){
    if(root==NULL)
     return 0;

    int leftSubtreeSum=totalSum(root->left);
    int rightSubtreeSum=totalSum(root->right);
    int treeSum=root->val+leftSubtreeSum+rightSubtreeSum;
    return treeSum;
}
int find(TreeNode* root){
    if(root==NULL)
     return 0;
    int leftSum=find(root->left);
    int rightSum=find(root->right);
    long subtreeSum=root->val+leftSum+rightSum; //s1
    long remainingSum=SUM-subtreeSum;
    maxP=max(maxP,subtreeSum*remainingSum);
    return subtreeSum;


}
    
    /*METHOD 2
    TC:
    SC:
    */
    
class Solution {
private:
long SUM=0;
long maxP=0;
int totalSum(TreeNode* root){
    if(root==NULL)
     return 0;

    int leftSubtreeSum=totalSum(root->left);
    int rightSubtreeSum=totalSum(root->right);
    long treeSum=root->val+leftSubtreeSum+rightSubtreeSum;
    long remainingSum=SUM-treeSum;
    maxP=max(maxP,treeSum*remainingSum);
    return treeSum;
}
// int find(TreeNode* root){
//     if(root==NULL)
//      return 0;
//     int leftSum=find(root->left);
//     int rightSum=find(root->right);
//     long subtreeSum=root->val+leftSum+rightSum; //s1
//     long remainingSum=SUM-subtreeSum;
//     maxP=max(maxP,subtreeSum*remainingSum);
//     return subtreeSum;


// }
public:
    
    int maxProduct(TreeNode* root) {
       if(root==NULL)
        return 0;
       maxP=0;
       SUM=totalSum(root);
       totalSum(root);
       return maxP%(1000000007); 
    }
};
