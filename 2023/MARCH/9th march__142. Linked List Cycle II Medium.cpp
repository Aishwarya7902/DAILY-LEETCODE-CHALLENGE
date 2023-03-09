PROBLEM:https://leetcode.com/problems/linked-list-cycle-ii/description/
VIDEO:https://www.youtube.com/watch?v=vlrxs-LPni4

/*
BRUTE FORCE
pseudo code
1.take a set of node type
2.start traversing the node
3.if node is not visited earlier put in set
4.if already visited .......means cycle started from here ...return it
5.if nothing was returned above....return null
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        set<ListNode *> s;
        ListNode * temp=head;
        while(temp){
            if(s.find(temp)!=s.end())return temp;
            else{
                s.insert(temp);
            }
            temp=temp->next;
        }
        return NULL;   
    }
};

/*
method 2:
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)return NULL;
        //if head is null or LL has only one node...then cycle ka sawal hi ni uthta hai
                ListNode *slow=head,*fast=head;
        //now if slow and fast becomes same ...it means loop to hai
                while(fast!=NULL && fast->next!=NULL){
                    slow=slow->next;
                    fast=fast->next->next;
                    if(slow==fast)break;
                }
        
                //while loop breaks due to two conditions....i)slow=fast.....ii)fast/fast->next=null
                if(slow!=fast)return NULL;
                ListNode *entry=head;
        //ab loop kaha hai..ye kaise paaata lagayen
        /*
        FOR PROOF WATCH VIDEO😂
        slow ,fast ,covered distance 
        slow=l1+l2
        fast=l1+l2+nk
        2slow=fast
        2(l1+l2)=l1+l2+nk
        l1=nk-l2
        hence distance covered by entry and slow to reach start node will be same 
        
        */
                while(entry!=slow){
                    entry=entry->next;
                    slow=slow->next;
                    
                }
                return entry;
    }
};
