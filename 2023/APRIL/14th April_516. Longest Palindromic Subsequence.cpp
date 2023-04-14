PROBLEM:https://leetcode.com/problems/longest-palindromic-subsequence/description/
VIDEO:https://www.youtube.com/watch?v=M4pfB3G-YQc
BLOG:

/*
RECUSRION

*/
class Solution {
public:
    
    int lcs(string &s1,string &s2,int m,int n){
        
        if(m==0 || n==0)return 0;
        
        if(s1[m-1]==s2[n-1])
         return 1+lcs(s1,s2,m-1,n-1);
        return max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));
    }
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
       
        return lcs(s,s2,s.size(),s.size());
    }
};

/*
MEMOIZATION 
*/
class Solution {
public:
    int t[1001][1001];
    int lcs(string &s1,string &s2,int m,int n){
        
        if(m==0 || n==0)return t[m][n]=0;
        if(t[m][n]!=-1)return t[m][n];
        if(s1[m-1]==s2[n-1])
         return t[m][n]=1+lcs(s1,s2,m-1,n-1);
        return t[m][n]=max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));
    }
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        memset(t,-1,sizeof(t));
        return lcs(s,s2,s.size(),s.size());
    }
};

/*
BOTTOM UP
*/

class Solution {
public:
    
    int lcs(string &s1,string &s2){
      int m=s1.size();
      int n=s2.size();
      vector<vector<int>> dp(m+1,vector<int>(n+1));
      for(int i=0;i<m+1;i++){
          for(int j=0;j<n+1;j++){
              if(i==0 || j==0)
               dp[i][j]=0;
           else if(s1[i-1]==s2[j-1])
             dp[i][j]=1+dp[i-1][j-1];
             else
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
      }  
      return dp[m][n];
        
    }
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
       
        return lcs(s,s2);
    }
};

/*
method 4
*/
class Solution {
public:
    int t[1001][1001];
    int solve(string &s,int i,int j){
        if(i>j)return 0;
        if(i==j)return 1;
        if(t[i][j]!=-1)return t[i][j];
        if(s[i]==s[j]){
            return t[i][j]=2+solve(s,i+1,j-1);

        }
        return t[i][j]=max(solve(s,i+1,j),solve(s,i,j-1));


    }
   
    int longestPalindromeSubseq(string s) {
        memset(t,-1,sizeof(t));
        return solve(s,0,s.size()-1);
    }
};


