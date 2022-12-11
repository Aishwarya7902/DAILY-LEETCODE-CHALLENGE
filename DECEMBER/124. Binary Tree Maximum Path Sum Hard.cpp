PROBLEM: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
VIDEO(BEST EVER EXPLANATION........BHAI JAKE DEKHO EKBAR ...MAJA AA JAYEGA SERIOUSLY) :https://www.youtube.com/watch?v=Op6YFcs8R9M

/*
TC:O(N)
SC:O(N) //auxiliary stack space for recursion

*/
DISCLAIMER: VIDEO DEKHO FIR CODE SAMJH AAYEGA 😎

class Solution {
private:
int maxSum;
int solve(TreeNode* root){
    if(root==NULL)
     return 0;
    int left=solve(root->left);
    int right=solve(root->right);
    int sirf_root_acha=root->val; //1
    int koi_ek_acha=max(left,right)+root->val;//2
    int niche_hi_mil_gaya=left+right+root->val;//3
    //maxSum ko to update kar ke dekh hi lete hain ek bar...kya pata ho jaye
    maxSum=max({maxSum,sirf_root_acha,koi_ek_acha,niche_hi_mil_gaya});
    //tu upar jake aur explore kar le

    return max(sirf_root_acha,koi_ek_acha);

}
public:
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};
