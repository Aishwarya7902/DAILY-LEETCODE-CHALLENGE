PROBLEM:https://leetcode.com/problems/minimum-falling-path-sum/description/
VIDEO(STRIVER BHAIYA) : https://youtu.be/N_aJ5qQbYA0

/*
recursion (TLE)
tc: o(3^n)
sc: O(n) at max u r gonna travel n rows
*/

class Solution {
private:
int helper(int i,int j,vector<vector<int>>& matrix){
    if(j<0 || j>=matrix[0].size()) return 1e8;
    if(i==0)return matrix[0][j];//base case
    
    int u=matrix[i][j]+helper(i-1,j,matrix);
    int ld=matrix[i][j]+helper(i-1,j-1,matrix);
    int rd=matrix[i][j]+helper(i-1,j+1,matrix);
    return dp[i][j]=min({u,ld,rd});
}
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int n=matrix.size();
      int m=matrix[0].size();
      int mini=1e8;
      
      for(int j=0;j<m;j++){
          mini=min(mini,helper(n-1,j,matrix));
      } 
      return mini; 
    }
};

/*
METHOD 2:
overlapping sub__problems
TC: O(N*M)
SC: O(N*M)->for dp matrix + O(n)->for recursion stack space
*/

class Solution {
private:
int helper(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
    if(j<0 || j>=matrix[0].size()) return 1e8;
    if(i==0)return matrix[0][j];//base case
    if(dp[i][j]!=-1)return dp[i][j];
    int u=matrix[i][j]+helper(i-1,j,matrix,dp);
    int ld=matrix[i][j]+helper(i-1,j-1,matrix,dp);
    int rd=matrix[i][j]+helper(i-1,j+1,matrix,dp);
    return dp[i][j]=min({u,ld,rd});
}
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int n=matrix.size();
      int m=matrix[0].size();
      int mini=1e8;
      vector<vector<int>>dp(n,vector<int>(m,-1));
      for(int j=0;j<m;j++){
          mini=min(mini,helper(n-1,j,matrix,dp));
      } 
      return mini; 
    }
};

