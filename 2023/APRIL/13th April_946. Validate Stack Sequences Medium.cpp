problem:https://leetcode.com/problems/validate-stack-sequences/description/
video:(mazhar bhaiya) https://www.youtube.com/watch?v=HEh7EtNSXtg
blog:
/*
self
tc:o(m+n)
sc:o(m)
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

       stack<int>st;
       int m=pushed.size();
       int n=popped.size();
       int i,j=0;
       for(i=0;i<m;i++){
           if(pushed[i]!=popped[j] ){
               while(!st.empty() && popped[j]==st.top())
                {
                    st.pop();
                    j++;
                }
                st.push(pushed[i]);
           }
           else
           j++;
       }
       while(j<n){
           if(popped[j]!=st.top())return false;
           else{
               st.pop();
               j++;
           }
       } 
       return true; 
    }
};

/*
BETTER CODE
TC:O(M)
SC:O(M)
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

       stack<int>st;
       int m=pushed.size();
       int i=0,j=0;

       while(i<m && j<m){
           st.push(pushed[i]);
           while(!st.empty() &&  j<m && st.top()==popped[j]){
               st.pop();
               j++;
           }
           i++;
       }
       return st.empty();
    }
};
