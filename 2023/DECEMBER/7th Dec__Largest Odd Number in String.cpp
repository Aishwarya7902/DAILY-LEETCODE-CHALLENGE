PROBLEM:https://leetcode.com/problems/largest-odd-number-in-string/description/?envType=daily-question&envId=2023-12-07
VIDEO:https://www.youtube.com/watch?v=vkxUVdGgnhU

/*
  TC:O(N)
  SC:O(1)
  */

class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        for(int i=n-1;i>=0;i--){
            if(int(num[i])%2!=0){
               return num.substr(0,i+1);
            }
        }
        return "";
    }
};
