PROBLEM:https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/?envType=daily-question&envId=2023-12-01
VIDEO:


/*
  TC:O(M+N)
  SC:O(M+N)

  */
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1="";
        string w2="";
        
        for(string s1:word1)
         w1+=s1;
         for(string s2:word2)
         w2+=s2;

         return w1==w2;
    }
};
