PROBLEM : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/?envType=daily-question&envId=2023-12-26
VIDEO (MIK BHAIYA) :https://www.youtube.com/watch?v=nQw9gVaIjGo


/*
  RECURSION : GIVES TLE
  TC: since every dice has k possibilities and in total there are n dice
      hence k*k*k........(n times) = k^n
  SC:
  */

class Solution {
public:
    
    int solve(int n,int k,int target){
        if(target<0)return 0;
        if(n==0) return target==0;
        
        int ways=0;
        for(int face=1;face<=k;face++){
            ways=(ways+solve(n-1,k,target-face))%MOD;
        }
        return ways;
    }
    int numRollsToTarget(int n, int k, int target) {
       
       return solve(n,k,target); 

    }
};


/*
MEMOIZATION
TC:
SC:
*/
class Solution {
public:
    int MOD=1e9+7;
    int dp[31][1001];
    int solve(int n,int k,int target){
        if(target<0)return 0;
        if(n==0) return target==0;
        if(dp[n][target]!=-1)return dp[n][target];
        int ways=0;
        for(int face=1;face<=k;face++){
            ways=(ways+solve(n-1,k,target-face))%MOD;
        }
        return  dp[n][target]=ways;
    }
    int numRollsToTarget(int n, int k, int target) {
       memset(dp,-1,sizeof(dp));
       return solve(n,k,target); 

    }
};
  
