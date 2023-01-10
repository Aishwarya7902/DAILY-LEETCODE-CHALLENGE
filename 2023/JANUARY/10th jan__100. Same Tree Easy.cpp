PROBLEM:https://leetcode.com/problems/same-tree/description/
VIDEO (MAZHAR BHAIYA) : 

/*
tc:o(n)
sc:O(H)H=height of binary tree //auxiliary stack space
pseudo code:
1.if both roots are null just return 
2.if one of the roots is null and other one is not null it means structure is not similar hence we return false immediately from there
3.if if(p->val !=q->val)return false; //this means node value is not similar , return a false from there
4.call left....if it returns false....no need to check further ,just return false 
5.call right....if it returns false....no need to check further ,just return false
6.if none of the above returns a false , return true at the end.
*/

class Solution {
private:
bool solve(TreeNode* p, TreeNode* q) {
        if(!p && !q)return true;
        if((!p && q) || (p && !q))return false;
        if(p->val !=q->val)return false;
        if(!solve(p->left,q->left))return false;
        if(!solve(p->right,q->right))return false;
        return true;

    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};
