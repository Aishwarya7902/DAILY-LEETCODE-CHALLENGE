problem:https://leetcode.com/problems/validate-stack-sequences/description/
video:
(mazhar bhaiya) https://www.youtube.com/watch?v=HEh7EtNSXtg
(aryan mittal) :https://www.youtube.com/watch?v=lqP82OhRkAA
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

/*
MORE BETTER CODE:
TC:O(M)
SC:O(M)
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        stack<int>st;
        for(int x:pushed){
            st.push(x);
            while(!st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }

        }
        return st.empty();
    }
};


/*
SPACE OPTIMISATION (SEE ARYAN'S VIDEO)
TC:O(M)
SC:O(1)

though u should tell the interviewer that it is highly not advisable to change the in input in production

but u also know this technique to create a impact on the interviewer
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        
        for(int x:pushed){
            pushed[i++]=x;
            while(i>0 && pushed[i-1]==popped[j]){
                --i;
                ++j;
            }

        }
        return i==0;
    }
};
