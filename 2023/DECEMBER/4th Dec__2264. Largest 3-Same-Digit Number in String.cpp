PROBLEM:https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/?envType=daily-question&envId=2023-12-04
VIDEO:https://www.youtube.com/watch?v=euheCzFYWDs

/*
  TC:O(N)
  SC:O(1)

  */

class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        char maxChar=' ';
        for(int i=2;i<n;i++){
            if(num[i]==num[i-1] && num[i]==num[i-2]){
                maxChar=max(maxChar,num[i]);
            }
        }
        if(maxChar==' ')return "";
        return string(3,maxChar);
    }
};
