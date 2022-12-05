PROBLEM: https://leetcode.com/problems/middle-of-the-linked-list/
 VIDEO (STRIVER BHAIYA) : https://www.youtube.com/watch?v=sGdwSH8RK-o


/*
INITIAL APPROACH
conunt length
then do (count/2)+1
initialize dummy node named temp
while(count)
temp=temp->next
return temp

tc:o(n) +o(n/2)
sc:o(1)
*/

class Solution {
private:
  int sizeOfLinkedList(ListNode* head){
    int len=0;
    ListNode* temp=head;
    while(temp){
      len++;
      temp=temp->next;
      
    }
    return len;
  }
public:
    ListNode* middleNode(ListNode* head) {
        if(!head->next)
          return head;
      int len=sizeOfLinkedList(head);
      len=(len/2)+1;
      ListNode*temp=head;
      while(--len){
       
        temp=temp->next;
      }
      return temp;
    }
};

/*METHOD 2
USING THE CONCEPT OF SLOW AND FAST POINTER
*/

class Solution {
public:
  //since fast moves at 2x speed than slow ...hence when fast is at end of linked list then slow would be somewhere at the end
  
  //tc:O(n/2)
  //sc:O(1)
    ListNode* middleNode(ListNode* head) {
      ListNode slow=head,fast=head;
      while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
      }
      return slow;
    }
};
