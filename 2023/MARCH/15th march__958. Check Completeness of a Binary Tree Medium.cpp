problem:https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
video:MAZHAR BHAIYA
I.DFS:https://www.youtube.com/watch?v=5zyG8Nw9V78
II.BFS:https://www.youtube.com/watch?v=08e5EBHoXxE

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

TC ⏳:O(N)
SC 🚀:O(N)
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

/*
USING DFS
LEARNING 
for cbt i.e complete binary tree
1. we can represent a binary tree in form of a array
parent=i
left child=2*i
right child=2*i+1

2.CBT ni hoga iff
(index >totalNode)

intuition:
if at any point of time ...indx>totalNodes
it means faltu ke nodes aaye hain beech me ....(null)
hence not a cbt
*/
class Solution {
public:
//helper to count nodes
    int countNode(TreeNode* root){
        if(root==NULL)return 0;
        return 1+countNode(root->left)+countNode(root->right);
    }
//helper for dfs
bool dfs(TreeNode* root,int indx,int totalNode){
    if(root==NULL)return true;
    if(indx>totalNode)return false;
    return dfs(root->left,2*indx,totalNode) && dfs(root->right,2*indx+1,totalNode);
}

    bool isCompleteTree(TreeNode* root) {
        int totalNodes=countNode(root);
        int i=1;
        return dfs(root,i,totalNodes);
    }
};
