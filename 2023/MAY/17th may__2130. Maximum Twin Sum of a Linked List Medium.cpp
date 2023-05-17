PROBLEM:https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
VIDEO:https://www.youtube.com/watch?v=L0UnqdfFcV4

/*
METHOD 1
*/

class Solution {
public:
    int pairSum(ListNode* head) {
        /*
        intuition
        1.store the ll in a vectore
        2.do a simple two pointer
        3.find max twin sum
        TC:O(n)
        SC:O(n)
        */

        vector<int>res;
        ListNode* temp=head;
        while(temp){
            res.push_back(temp->val);
            temp=temp->next;
        }
        int i=0,j=res.size()-1;
        int ans=0;
        while(i<j){
            ans=max(ans,res[i]+res[j]);
            i++;
            j--;

        }
        return ans;

    }
};
