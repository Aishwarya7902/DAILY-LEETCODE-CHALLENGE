PROBLEM :https://leetcode.com/problems/construct-string-from-binary-tree/description/?envType=daily-question&envId=2023-12-08
VIDEO:https://www.youtube.com/watch?v=KZLMac8vUVw

/*

  TC: O(N)
  SC: O(1)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root==NULL)
         return "";
        string result=to_string(root->val); // root (L) (R)
        string LEFT= tree2str(root->left);
        string RIGHT= tree2str(root->right);
        //edge cases

        //edge case 1.......if both left and right are null
        if(root->left==NULL && root->right==NULL){
             return result;
        }

        //edge case 2 ...if left is null
        if(root->left==NULL){
            return result + "()" + "("+RIGHT+")";
        }

        //edge case 3......if right is null
        if(root->right==NULL){
            return result + "("+ LEFT+")";

        }

        return result + "("+ LEFT+")" + "("+RIGHT+")";
    }
};
