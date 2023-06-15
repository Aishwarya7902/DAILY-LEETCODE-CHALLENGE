PROBLEM:https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
VIDEO:(MAZHAR BHAIYA) https://www.youtube.com/watch?v=GWCVpTCSIFY

/*
TC:O(N)
SC:O(1)
*/

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int level=0;
        int ans;
       int  max_val=INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sum=0;
            int n=q.size();
            while(n--){
                TreeNode* node=q.front();
                q.pop();
                sum+=node->val;
                if(node->right)q.push(node->right);
                if(node->left)q.push(node->left);
            }
            level++;
            if(sum>max_val){
                ans=level;
                max_val=sum;
            }
        }
        return ans;
    }
};
