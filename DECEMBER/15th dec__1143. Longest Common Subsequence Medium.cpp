PROBLEM:https://leetcode.com/problems/longest-common-subsequence/description/
VIDEO (STRIVER BHAIYA) : https://www.youtube.com/watch?v=NPZn9jBrX8U

/*
RECURSION
TC:exponential
SC:exponential
*/

class Solution {
private:
int helpLcs(string text1,int indx1,string text2,int indx2){
    if(indx1<0 || indx2<0)return 0; //negative index implies end of string
    //if both indexes matches
    if(text1[indx1]==text2[indx2]){
        return 1+helpLcs(text1,indx1-1,text2,indx2-1);
    }
    //no match....then try out both possibilities
    return max(helpLcs(text1,indx1,text2,indx2-1),helpLcs(text1,indx1-1,  text2,indx2));

}
public:
    int longestCommonSubsequence(string text1, string text2) {
      int n=text1.size();//size of string1
      int m=text2.size();//size of string2
      return helpLcs(text1,n-1,text2,m-1);  
    }
};

/*
MEMOIZATION
TC:O(n*m)
SC:O(n*m)// for dp vector + O(n+m) //for auxiliary stack space
*/
class Solution {
private:
int helpLcs(string text1,int indx1,string text2,int indx2,vector<vector<int>>&dp){
    if(indx1<0 || indx2<0)return 0; //negative index implies end of string
    //if both indexes matches
    if(dp[indx1][indx2]!=-1)return dp[indx1][indx2];
    if(text1[indx1]==text2[indx2]){
        return dp[indx1][indx2]=1+helpLcs(text1,indx1-1,text2,indx2-1,dp);
    }
    //no match....then try out both possibilities
    return dp[indx1][indx2]=max(helpLcs(text1,indx1,text2,indx2-1,dp),helpLcs(text1,indx1-1,text2,indx2,dp));

}
public:
    int longestCommonSubsequence(string text1, string text2) {
      int n=text1.size();//size of string1
      int m=text2.size();//size of string2
      vector<vector<int>>dp(n,vector<int>(m,-1));
      return helpLcs(text1,n-1,text2,m-1,dp);  
    }
};

/*
METHOD 3 
INDEX SHIFTING (WATCH STRIVER BHAIYA'S VIDEO: https://youtu.be/NPZn9jBrX8U?t=2292
*/

class Solution {
private:
int helpLcs(string text1,int indx1,string text2,int indx2,vector<vector<int>>&dp){
    if(indx1==0 || indx2==0)return 0; //negative index implies end of string
    //if both indexes matches
    if(dp[indx1][indx2]!=-1)return dp[indx1][indx2];
    if(text1[indx1-1]==text2[indx2-1]){
        return dp[indx1][indx2]=1+helpLcs(text1,indx1-1,text2,indx2-1,dp);
    }
    //no match....then try out both possibilities
    return dp[indx1][indx2]=max(helpLcs(text1,indx1,text2,indx2-1,dp),helpLcs(text1,indx1-1,text2,indx2,dp));

}
public:
    int longestCommonSubsequence(string text1, string text2) {
      int n=text1.size();//size of string1
      int m=text2.size();//size of string2
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      return helpLcs(text1,n,text2,m,dp);  
    }
};

/*
TABULATION:
TC:O(n*m)
SC:O(n*m)// for dp vector
*/class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
      int n=text1.size();//size of string1
      int m=text2.size();//size of string2
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      for(int j=0;j<=m;j++)dp[0][j]=0;
      for(int i=0;i<=n;i++)dp[i][0]=0;


      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
              if(text1[i-1]==text2[j-1]){
        dp[i][j]=1+dp[i-1][j-1];
    }
    //no match....then try out both possibilities
   else
    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);

          }
      }
      return dp[n][m];
    }
};
