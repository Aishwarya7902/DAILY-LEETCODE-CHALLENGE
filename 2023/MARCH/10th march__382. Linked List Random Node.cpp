PROBLEM:https://leetcode.com/problems/linked-list-random-node/description/
VIDEO:
class Solution {
int len=0;
ListNode* headNode;
public:
    Solution(ListNode* head) {
        headNode=head;
        ListNode* temp=headNode;
        while(temp){
            len++;
            temp=temp->next;
        }
    }
    
    int getRandom() {
       int indx=rand()%len;
       ListNode* temp=headNode;
       for(int i=0;i<indx;i++){
           temp=temp->next;
       }
       return temp->val;
    }
};
