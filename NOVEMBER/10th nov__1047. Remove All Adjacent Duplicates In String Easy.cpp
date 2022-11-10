PROBLEM: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
VIDEO:https://www.youtube.com/watch?v=52TwSRU5NJM
/*
ONE PASS
TC:O(N)
SC:O(N)
QUESTION IS QUITE SIMILAR TO YESTERDAY'S PROBLEM
*/

class Solution {
public:
  
    string removeDuplicates(string s) {
     string st;
      for(int i=0;i<s.size();i++){
        if(st.empty()){
          st.push_back(s[i]);
        }
        else if(!st.empty() && st.back()==s[i]){
          st.pop_back();
        }
        else{
          st.push_back(s[i]);
        }
      }
      
      return st;
    }
};

/*METHOD 2 (TWO PASS SOLUTION)
(USING STACK)
TC:O(N) 
SC:O(M+N)coz we are using two spaces one for stack and one for string
*/

class Solution {
public:
  //tc:o(n)
  //sc:o(n)
    string removeDuplicates(string s) {
     stack<char>st;
      for(int i=0;i<s.size();i++){
        
         if(!st.empty() && st.top()==s[i]){
          st.pop();
        }
        else{
          st.push(s[i]);
        }
      }
      string ans="";
      while(!st.empty()){
        ans=st.top()+ans;
        st.pop();
      }
      return ans;
    }
};
