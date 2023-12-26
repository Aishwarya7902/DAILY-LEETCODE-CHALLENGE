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
TC: O(n*target*k)
SC: O(31*1001) ~= O(1)
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


/*
 BOTTOM UP 
 lets define the states
 t[i][j] means no of ways to obtain 
                                  sum=j
                                  if we have i no of dices

  //T.C : O(n*target*k)
//S.C : O(n*target)

*/

class Solution {
public:
    int MOD=1e9+7;
    
    
    int numRollsToTarget(int n, int k, int target) {
       vector<vector<int>> t(n+1,vector<int>(target+1));
        t[0][0]=1; //n==0 && target==0
       for(int i=1;i<n+1;i++){
           for(int j=1;j<target+1;j++){
               //i=no of dice
               //j=target value

               int ways=0;
               //each dice will have k face value
               for(int face=1;face<=k;face++){
                   if(j>=face)
                   ways= (ways+t[i-1][j-face])%MOD;
               }
               t[i][j]=ways;
           }
       }
       return t[n][target];

    }
};
  
