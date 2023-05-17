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


/*
METHOD 2
*/

class Solution {
public:
    int pairSum(ListNode* head) {
        /*
        intuition
        1.store the ll in a stack
        2.travel in LL ,half of stack size times
        3.find max twin sum by using curr->val+st.top()
        4.curr=curr->next
        5.st.pop();
        TC:O(n)
        SC:O(n)
        */

        stack<int>st;
        ListNode* temp=head;
        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }
        int n=st.size();
        n/=2;
        int ans=0;
        temp=head;
        while(n){
            ans=max(ans,temp->val+st.top());
            st.pop();
            temp=temp->next;
            n--;

        }
        return ans;

    }
};

/*
METHOD 3
TC:O(N)
SC:O(1)
*/


class Solution {
public:
    int pairSum(ListNode* head) {
        //1.finding mid of ll
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow;

        //2.reversing 2nd half of ll

        //reversal code
        ListNode* prev=NULL;
        ListNode* nextNode=NULL;
        while(mid!=NULL){
            nextNode=mid->next;
            mid->next=prev;
            prev=mid;
            mid=nextNode;
        }

        //reversal code

        //3.find max sum
        int result=0;
        ListNode* curr=head;
        while(prev!=NULL){
            result=max(result,curr->val+prev->val);
            curr=curr->next;
            prev=prev->next;
        }
        return result;
        
    }
};
