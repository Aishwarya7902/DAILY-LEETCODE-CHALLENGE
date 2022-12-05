PROBLEM: https://leetcode.com/problems/middle-of-the-linked-list/

/*
INITIAL APPROACH
conunt length
then do count/2
initialize temp with head
while(count)
temp=temp->next
return temp

tc:o(n)
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
      len/=2;
      ListNode*temp=head;
      while(len){
        len--;
        temp=temp->next;
      }
      return temp;
    }
};
