PROBLEM:https://leetcode.com/problems/removing-stars-from-a-string/description/
VIDEO:(mazhar bhaiya) https://www.youtube.com/watch?v=s1pcdsRCVDg
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
method 2
using a vector 
vector behaves like a stack and there is no need to reverse the string at the end
for clarity see video(mazhar bhaiya)
*/


class Solution {
public:
    string removeStars(string s) {
      if(s.size()<=1)return s;
      string st="";

      for(int i=0;i<s.size();i++){
          if(s[i]=='*')
           st.pop_back();
          else
            st.push_back(s[i]);
      }  
      
      return st;
    }
};

/*
method 3
using two pointer
for clarity watch video
*/

class Solution {
public:
    string removeStars(string s) {
     int n=s.size() ;
     vector<char>temp(n);
     int j=0;
     for(int i=0;i<n;i++){
         if(s[i]=='*')
          j--;
        else{
            temp[j]=s[i];
            j++;

        }
     }
     string ans="";
     for(int k=0;k<=j-1;k++){
         ans.push_back(temp[k]);
     }
     return ans;

    }
};
