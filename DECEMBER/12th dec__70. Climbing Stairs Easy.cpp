PROBLEM:https://leetcode.com/problems/climbing-stairs/description/
VIDEO (BEST ):

/*
SELF  (USING DP) -BOTTOM UP
Time Complexity :
1) Recursion : O(2^n) - We have 2 possibilities for every stair.
2) Memoization : O(n) - We are not visiting already solved subproblems
3) Bottom UP : O(n) as we are iterating only once from i = 2 to i = n
SC:

*/

class Solution {
public:
    int climbStairs(int n) {
        
         vector<int>dp(n+1);
         dp[0]=1;
         dp[1]=1;
         for(int i=2;i<=n;i++){
             dp[i]=dp[i-1]+dp[i-2];
         }
         return dp[n];
    }
};
