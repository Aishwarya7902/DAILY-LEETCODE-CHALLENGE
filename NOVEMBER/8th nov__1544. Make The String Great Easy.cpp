PROBLEM: https://leetcode.com/problems/make-the-string-great/
VIDEO:   https://www.youtube.com/watch?v=0Yfkz6ZBWE8
 /*
 METHOD 1__USING STACK
 TC:
 SC:
 */
 
#include<bits/stdc++.h>
class Solution {
public:
    string makeGood(string s) {
       stack<char>st;
       for(int i=0;i<s.size();i++){
         if(st.empty())
         {
           st.push(s[i]);
           continue;
         }
         if(abs(st.top()-s[i])==32){
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

/*method 2
tc:
sc:
*/

#include<bits/stdc++.h>
class Solution {
public:
    string makeGood(string s) {
       string ans;
       for(int i=0;i<s.size();i++){
         if(ans.empty())
         {
           ans.push_back(s[i]);
           continue;
         }
         if(abs(ans.back()-s[i])==32){
           ans.pop_back();
         }
         else{
           ans.push_back(s[i]);
         }
       }
      
      return ans;
    }
};
