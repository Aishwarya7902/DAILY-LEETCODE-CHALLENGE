PROBLEM:https://leetcode.com/problems/valid-anagram/description/?envType=daily-question&envId=2023-12-16
VIDEO:

/*
  METHOD 1
  SELF

  INTUITION: if all the count of all characters in s and t are same then  t is an anagram if s
  TC: O(m+n)
  SC: O(m+n)

  */

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(char &ch:s){
            mp1[ch]++;
        }
        for(char &ch:t){
            mp2[ch]++;
        }

        return mp1==mp2;
    }
};


/*
OPTIMISATION
Intuition : sort both strings , now check characterwise , if any corresponding char does not match , return false
  else return true

TC : O(mlogm + nlogn)
SC: O(1)
*/


   class Solution {
    public:
    bool isAnagram(string s, string t) {
        sort(begin(s),end(s));
        sort(begin(t),end(t));
        return s==t;
    }
};
