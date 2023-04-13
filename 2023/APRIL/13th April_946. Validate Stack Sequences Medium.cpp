problem:https://leetcode.com/problems/validate-stack-sequences/description/
video:
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
