PROBLEM :https://leetcode.com/problems/linked-list-cycle/submissions/?envType=daily-question&envId=2023-09-04
VIDEO(STRIVER BHAIYA):https://www.youtube.com/watch?v=354J83hX7RI

/*
  tc: o(n)
*/


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow,*fast;
        slow=fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return true;
        }

        return false;
        
    }
};
