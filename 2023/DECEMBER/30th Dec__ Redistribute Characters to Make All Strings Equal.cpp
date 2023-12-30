PROBLEM:https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/?envType=daily-question&envId=2023-12-30
VIDEO: 

/*
  approach 1
  TC: o(m*n) // m is size of words and n is size of longest string
  SC: o(26) as  words[i] consists of lowercase English letters.

  */

class Solution {
public:
    bool makeEqual(vector<string>& words) {
       int n=words.size();
       unordered_map<char,int>mp;
       for(auto &str:words){
           for(char &ch:str){
               mp[ch]++;
           }
       } 

       for(auto it:mp){
         int freq=it.second;
         if(freq%n!=0)return false;
       }

       return true;
    }
};
