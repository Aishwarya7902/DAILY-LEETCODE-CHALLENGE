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
