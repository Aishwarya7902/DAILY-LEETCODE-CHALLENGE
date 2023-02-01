PROBLEM:https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
VIDEO:

/*
TC:o(n+m)
SC: O(1)
*/
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
     if(str1+str2!=str2+str1)
      return "";
    return str1.substr(0,__gcd(size(str1),size(str2)))  ; 
    }
};
