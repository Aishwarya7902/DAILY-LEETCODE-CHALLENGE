PROBLEM:https://leetcode.com/problems/maximum-width-of-binary-tree/description/
VIDEO:https://www.youtube.com/watch?v=hwjd0U36MUE

/*

TC:O(N)
SC:O(N)
*/


class Solution {
public:
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        ll maxWidth=0;
        while(!q.empty()){
            ll L=q.front().second;
            ll R=q.back().second;
            maxWidth=max(maxWidth,R-L+1);
            ll n=q.size();
            while(n--){
                TreeNode* node=q.front().first;
                ll indx=q.front().second;
                q.pop();
                if(node->left){
                    q.push({node->left,2*indx+1});
                }
                if(node->right){
                    q.push({node->right,2*indx+2});
                }
            }
        }
        return maxWidth;
        
    }
};
