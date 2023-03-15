problem:https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
video:

/*
method 1:
here intuition is simple ...
1.we will maintain a gotNullSoFar and initialise with false
2.if at any point of time node is null
make gotNullSoFar=true
3.if node is not null check if gotNullSoFar==true
if yes it simply means either any node above it or leftward it was null
->any node above it  was null....means ....incomplete level
->any node leftward it was null...means tree is not as left as possible

hence we  return false

4.otherwise push left ,right childs in queue

5.at last return true

TC ⏳
SC 🚀
*/

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
      bool gotNullSoFar=false;
      queue<TreeNode*>q;
      q.push(root);
      while(!q.empty()){
          TreeNode*node=q.front();
          q.pop();
          if(node==NULL)
           gotNullSoFar=true;
          else{
              if(gotNullSoFar==true)return false;
              q.push(node->left);
              q.push(node->right);
          }
      }
      return true; 
    }
};
