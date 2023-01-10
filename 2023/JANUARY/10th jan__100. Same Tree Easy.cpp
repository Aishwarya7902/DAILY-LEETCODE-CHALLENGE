PROBLEM:https://leetcode.com/problems/same-tree/description/
VIDEO (MAZHAR BHAIYA) : https://www.youtube.com/watch?v=YtoibyDlzk0

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


/*METHOD 2
ITERATIVE :USING BFS
*/

class Solution {
private:
bool solve(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        if(p==NULL || q==NULL )return false;
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode* node1=q1.front();
            q1.pop();
            TreeNode* node2=q2.front();
            q2.pop();
            if(node1->val != node2->val)return false;
            if(node1->left!=NULL && node2->left!=NULL){
                q1.push(node1->left);
                q2.push(node2->left);

            }
            else if(node1->left!=NULL || node2->left!=NULL)
             return false;
             if(node1->right!=NULL && node2->right!=NULL){
                q1.push(node1->right);
                q2.push(node2->right);

            }
            else if(node1->right!=NULL || node2->right!=NULL)
             return false;
        }
        
        return true;

    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};
