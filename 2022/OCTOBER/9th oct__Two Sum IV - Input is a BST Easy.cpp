PROBLEM: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
video: (striver bhaiya) https://www.youtube.com/watch?v=ssL3sHwPeb4

/*
brute force
tc:O(n)
sc:O(n)
pseudo code:
1.do inorder traversal and store in a vector
2.now inorder of a bst guarantees that it is in ascending order
3.now the problem boils to 2 sum problem
4.take lo on start of array and hi on end of array
5.if v[lo]+v[hi]==target return true;
6.v[lo]+v[hi]<target it means we need to add a larger value ,hence lo++;
7.else hi--;
*/

class Solution {
private:
  void Inorder(TreeNode* root,vector<int>&v){
    if(!root)return;
    Inorder(root->left,v);
    v.push_back(root->val);
    Inorder(root->right,v);
  }
public:
    bool findTarget(TreeNode* root, int k) {
     vector<int>v;
      Inorder(root,v);
      int lo=0,hi=v.size()-1;
      while(lo<hi){
        if((v[lo]+v[hi])==k)return true;
        else if(v[lo]+v[hi]<k)lo++;
        else
          hi--;
      }
      return false;
    }
};
