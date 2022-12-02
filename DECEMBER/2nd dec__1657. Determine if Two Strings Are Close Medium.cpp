PROBLEM:https://leetcode.com/problems/determine-if-two-strings-are-close/
VIDEO:https://www.youtube.com/watch?v=rPR6DxPE2K4

//tc: O(n)....as we are traversing in word1 and word2 ....for sorting 26log26 which comes out to be less than o(n)

//sc: O(1) as vector of size 26 can be considered as constant
class Solution {
public:
    bool closeStrings(string word1, string word2) {
       vector<int>s1(26,0),s2(26,0),s3(26,0),s4(26,0);
      for(auto x:word1)
      {
        s1[x-'a']++;
        s3[x-'a']=1;
      }
      for(auto x:word2)
      {
        s2[x-'a']++;
        s4[x-'a']=1;
      }
      sort(s1.begin(),s1.end());
      sort(s2.begin(),s2.end());
      return s1==s2 && s3==s4;
      
    }
};
