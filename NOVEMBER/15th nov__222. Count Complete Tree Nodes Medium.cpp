PROBLEM:https://leetcode.com/problems/count-complete-tree-nodes/
 VIDEO: (striver bhaiya):https://www.youtube.com/watch?v=u-yWemKGWO0

/*
INITIAL APPROACH
PSEUDO CODE:
1.if root is null return 0
2.call left ,call right 
3.return 1+left+right
TC: o(n)
AUXIALIARY SPACE:  o(h) and in worst case the height of a complete binary tree is log(n)
*/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};


/*
METHOD 2 
USING THE PROPERTIES OF COMPLETE BINARY TREE
TC: O((logn)^2).....coz at max there will logn nodes in a cbt and for every node we will calculate height ...which in worst case will take logn..hence
 time complexity boils down to (logn*logn)
AUXILIARY SPACE: O(logn)...coz at max height of tree can go upto logn in   a CBT
*/

class Solution {
private:
  int findHeightLeft(TreeNode* node){
    int hgt=0;
    while(node){
      hgt++;
      node=node->left;
    }
    return hgt;
  }
  
  int findHeightRight(TreeNode* node){
    int hgt=0;
    while(node){
      hgt++;
      node=node->right;
    }
    return hgt;
  }
public:
    int countNodes(TreeNode* root) {
        if(!root)return NULL;
        int lh=findHeightLeft(root->left);
        int rh=findHeightRight(root->right);
      if(lh==rh)return (1<<lh+1)-1;
     return  1+countNodes(root->left)+countNodes(root->right);
    }
};
