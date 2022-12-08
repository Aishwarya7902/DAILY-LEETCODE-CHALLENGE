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

