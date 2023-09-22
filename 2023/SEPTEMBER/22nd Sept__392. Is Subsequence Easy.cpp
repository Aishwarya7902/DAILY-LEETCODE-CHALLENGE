PROBLEM :https://leetcode.com/problems/is-subsequence/description/?envType=daily-question&envId=2023-09-22
VIDEO:(MIK BHAIYA) https://www.youtube.com/watch?v=r51_ZifUdvU

/*
  TC:O(M+N)
  SC:O(1)

  */

class Solution {
public:
    bool isSubsequence(string s, string t) {
       int m=s.size();
       int n=t.size();
       int i=0,j=0;
       while(i<m && j<n){
           if(s[i]==t[j])
            i++;
           j++;
       } 
       return i==m;
    }
};
