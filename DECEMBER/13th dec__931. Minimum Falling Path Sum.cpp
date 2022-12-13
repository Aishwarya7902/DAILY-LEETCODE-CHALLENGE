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
MEMOIZATION
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


/*
METHOD 3
BOTTOM UP/TABULATION
TC:O(N*M) +O(M)
SC:O(N*M)
*/

class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int n=matrix.size();
      int m=matrix[0].size();
      int mini=1e8;
      vector<vector<int>>dp(n,vector<int>(m,0));
      for(int j=0;j<m;j++){
         dp[0][j]=matrix[0][j];
      } 
      for(int i=1;i<n;i++){
          for(int j=0;j<m;j++){
              int u=matrix[i][j]+dp[i-1][j];
              int ld=matrix[i][j];
              if(j-1>=0)
               ld+=dp[i-1][j-1];
             else
              ld+=1e8;
            int rd=matrix[i][j];
             if(j+1<m)
              rd+=dp[i-1][j+1];
            else
             rd+=1e8;
            dp[i][j]=min({u,ld,rd});
          }
      }
      for(int j=0;j<m;j++){
          mini=min(mini,dp[n-1][j]);
      }
      return mini; 
    }
};

/*
METHOD 4
SPACE OPTIMIZATION
TC:O(N*M) +O(M)
SC:O(M)
*/

class Solution {
private:

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int n=matrix.size();
      int m=matrix[0].size();
      int mini=1e8;
      vector<int> prev(m,0),curr(m,0);
      for(int j=0;j<m;j++){
         prev[j]=matrix[0][j];
      } 
      for(int i=1;i<n;i++){
          for(int j=0;j<m;j++){
              int u=matrix[i][j]+prev[j];
              int ld=matrix[i][j];
              if(j-1>=0)
               ld+=prev[j-1];
             else
              ld+=1e8;
            int rd=matrix[i][j];
             if(j+1<m)
              rd+=prev[j+1];
            else
             rd+=1e8;
            curr[j]=min({u,ld,rd});
          }
          prev=curr;
      }
      for(int j=0;j<m;j++){
          mini=min(mini,prev[j]);
      }
      return mini; 
    }
};


