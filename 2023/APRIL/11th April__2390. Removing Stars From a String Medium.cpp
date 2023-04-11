PROBLEM:https://leetcode.com/problems/removing-stars-from-a-string/description/
VIDEO:
BLOG:

/*
INITIAL APPROACH
GOT TLE

*///tc:o(n)
//sc:o(n)
//pseudo code
// take a stack....iterate on string if it is not star push in stack ....if its a star pop top of stack
//....coz it will be on the most recent left of current star ....at last push everything left in stack in reverse order...and return it
class Solution {
public:
    string removeStars(string s) {
      stack<char>st;
      for(int i=0;i<s.size();i++){
          if(s[i]!='*')
           st.push(s[i]);
          else if(s[i]=='*' && st.size()!=0)
           st.pop();
      }  
      string ans="";
      while(!st.empty()){
        ans=st.top()+ans;
          st.pop();
      }
      return ans;
    }
};




/*
METHOD 1
USING STACK
*/

//tc:o(n)
//sc:o(n)
//pseudo code
// take a stack....iterate on string if it is not star push in stack ....if its a star pop top of stack....coz it will be on the most recent left of current star ....at last push everything left in stack in reverse order...and return it
class Solution {
public:
    string removeStars(string s) {
      if(s.size()<=1)return s;
      stack<char>st;
      for(int i=0;i<s.size();i++){
          if(s[i]=='*')
           st.pop();
          else
            st.push(s[i]);
      }  
      string ans="";
      while(!st.empty()){
        ans.push_back(st.top());
          st.pop();
      }
      reverse(begin(ans),end(ans));
      return ans;
    }
};

/*
method
