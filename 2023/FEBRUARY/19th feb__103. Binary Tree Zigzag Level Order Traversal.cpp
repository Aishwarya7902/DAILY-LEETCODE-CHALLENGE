PROBLEM:https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
VIDEO:https://www.youtube.com/watch?v=3OXWEdlIGl4

/*
pre-requisite : level order traversal
video: https://www.youtube.com/watch?v=EoAsWbO7sqg
*/

/*
tc:o(n)
sc:o(n)
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        bool leftToRight=true;
       if(root==NULL)return ans;
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
           int size=q.size();
           vector<int>level;
           for(int i=0;i<size;i++){
               TreeNode*node=q.front();
               q.pop();
               if(node->left!=NULL)q.push(node->left);
               if(node->right!=NULL)q.push(node->right);
               level.push_back(node->val);
           }
           if(!leftToRight){
                   reverse(level.begin(),level.end());
                   //level.push_back(node->val);
               }
           
           ans.push_back(level);
           leftToRight=!leftToRight;
       }
       return ans;
    }
};
