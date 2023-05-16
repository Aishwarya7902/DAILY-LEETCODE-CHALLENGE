PROBLEM:https://leetcode.com/problems/swap-nodes-in-pairs/description/
VIDEO:https://www.youtube.com/watch?v=8yLiGS4ntHw

/*
RECURSION
TC
SC
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* temp=head->next;
        head->next=swapPairs(temp->next);
        temp->next=head;
        
        return temp;
        
    }
};
