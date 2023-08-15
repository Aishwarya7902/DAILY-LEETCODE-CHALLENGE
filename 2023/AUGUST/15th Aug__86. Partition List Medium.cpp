PROBLEM:https://leetcode.com/problems/partition-list/description/
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=NYZKRUT_8MY


/*
  TC:O(N)
  SC:O(1)
  */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small= new ListNode(0);
        ListNode* large= new ListNode(0);

        ListNode* smallP=small;
        ListNode* largeP=large;

        while(head!=NULL){
            if(head->val<x){
                smallP->next=head;
                smallP=smallP->next;
                
            }
            else{
                largeP->next=head;
                largeP=largeP->next;
                
            }
            head=head->next;
        }
        smallP->next=large->next;
        largeP->next=NULL;
        return small->next;

    }
};

