PROBLEM:https://leetcode.com/problems/perfect-squares/
VIDEO:(LOVE BABBAR) https://www.youtube.com/watch?v=aJTCcyPrPOA

/*
RECURSION:
TC:
SC:
*/
class Solution {
private:
  int solveRec(int n){
    if(n==0)return 0;
      int ans=n;
      for(int i=1;i*i<=n;i++){
        ans=min(ans,1+solveRec(n-i*i));
      }
    return ans;
  }
public:
    int numSquares(int n) {
      return solveRec(n);
    }
};


/*
MEMOIZATION:
TC:
SC:
*/
class Solution {
private:
  int solveMem(int n,vector<int>&dp){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
      int ans=n;
      for(int i=1;i*i<=n;i++){
        ans=min(ans,1+solveMem(n-i*i,dp));
      }
    return dp[n]=ans;
  }
public:
    int numSquares(int n) {
      vector<int> dp(n+1,-1);
      return solveMem(n,dp);
    }
};

/*
TABULATION
TC:
SC:
*/

class Solution {
private:
  int solveTab(int n){
    vector<int>dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
      for(int j=1;j*j<=i;j++){
        dp[i]=min(dp[i],1+dp[i-j*j]);
      }
    }
   return dp[n];
  }
  
public:
    int numSquares(int n) {
      return solveTab(n);
    }
};
