PROBLEM: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
VIDEO:
/*
TC:O(N)
SC:O(1)
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
