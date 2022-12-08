PROBLEM:https://leetcode.com/problems/leaf-similar-trees/
VIDEO:

/*
METHOD 1 (SOLVED ON MY OWN)😎
INTUTION :
1.Let's find the leaf value sequence for both given trees
2.Afterwards, we can compare them to see if they are equal or not.
3.To find the leaf value sequence of a tree, we use a depth first search
4.writes the node's value if it is a leaf node.
5.and then recursively explores each child.
6.This is guaranteed to visit each leaf in left-to-right order, as left-children are fully explored before right-children.

Time Complexity: O(T1+T2) , where T1,T2
are the lengths of the given trees. 

Space Complexity: O(T1+T2) , where T1,T2
are the lengths of the given trees.

*/

class Solution {
private:
void GetLeafSeq(TreeNode* root,vector<int>&v){
    if(!root)
     return;
     if(!root->left && !root->right)
       v.push_back(root->val);
     GetLeafSeq(root->left,v);
     GetLeafSeq(root->right,v);
}
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafSeq1;
        vector<int> leafSeq2;
        GetLeafSeq(root1,leafSeq1);
        GetLeafSeq(root2,leafSeq2);
        return leafSeq1==leafSeq2;

    }
};

/*
METHOD 2 (LEARNT FROM Lee's blog)
blog link:https://leetcode.com/problems/leaf-similar-trees/solutions/152329/c-java-python-o-h-space/?orderBy=most_votes

Only O(H) space for stack, no extra space for comparation.
O(1) is also possible if we can modify the tree.
*/

class Solution {
private:
int dfs(stack<TreeNode*>&s)
{
    while(true){
      TreeNode* root=s.top();
      s.pop();
      if(root->right)s.push(root->right);
      if(root->left)s.push(root->left);
      if(!root->left && !root->right)return root->val;  
    }
}
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        s1.push(root1);
        s2.push(root2);
        while(!s1.empty() && !s2.empty())
         if(dfs(s1)!=dfs(s2))
           return false;
        return s1.empty()&& s2.empty();
     }
};

