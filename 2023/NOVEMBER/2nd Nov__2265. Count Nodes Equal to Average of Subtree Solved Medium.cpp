PROBLEM:https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/?envType=daily-question&envId=2023-11-02
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=Y4UGaLpSqCg

/*
  TC:O(N) //since we are visiting each node once
  */

class Solution {
public:
    int result;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL)
         return {0,0};
        auto p1=solve(root->left);
        auto p2=solve(root->right);
        int totalSum=p1.first+p2.first+root->val;
        int totalCount=p1.second+p2.second+1;
        int avg=totalSum/totalCount;
        if(avg==root->val)
         result++;
        return {totalSum,totalCount};
    }
    int averageOfSubtree(TreeNode* root) {
        result=0;
        solve(root);
        return result;
    }
};
  
