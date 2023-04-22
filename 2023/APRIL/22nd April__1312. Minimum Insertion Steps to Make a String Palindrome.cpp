PROBLEM:https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
VIDEO (ARYAN MITTAL): https://www.youtube.com/watch?v=kAqcefIK0hY
VIDEO (ARYAN MITTAL):LPS __https://www.youtube.com/watch?v=LOMoc56Yj4w


/*
BRUTE FORCE
INTUITION
Is dynamic programming suitable for this problem ?
If we know the longest palindromic sub-sequence is x and the length of the string is n then, 
what is the answer to this problem? 
It is n - x as we need n - x insertions to make the remaining characters also palindrome.

RECURSION :GIVES TLE
TC:
SC:
*/
class Solution {
public:
//SOLVE FUNCTION
    int solve(string&s,int start,int end){
        if(start==end)return 1;
        if(start>end)return 0;//not a valid string
        if(s[start]==s[end]){
            return (2+solve(s,start+1,end-1));
        }
        int leaveLeft=solve(s,start+1,end);
        int leaveRight=solve(s,start,end-1);
        return max(leaveLeft,leaveRight);
    }
// LPS FUNCTION
    int longestPalindromicSubsequence(string &s){
        int ans=solve(s,0,s.size()-1);
        return ans;
    }
    int minInsertions(string s) {
        int n=s.size();
        return n-longestPalindromicSubsequence(s);
        
    }
};


/*
MEMOIZATION
TC:O(N^2)
SC:O(N^2)
*/

class Solution {
public:
//SOLVE FUNCTION
    int solve(string&s, vector<vector<int>>&dp,int start,int end){
        if(start==end)return 1;
        if(start>end)return 0;//not a valid string
        if(dp[start][end]!=-1)return dp[start][end];
        if(s[start]==s[end]){
            return dp[start][end]=(2+solve(s,dp,start+1,end-1));
        }
        int leaveLeft=solve(s,dp,start+1,end);
        int leaveRight=solve(s,dp,start,end-1);
        return dp[start][end]=max(leaveLeft,leaveRight);
    }
// LPS FUNCTION
    int longestPalindromicSubsequence(string &s){
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solve(s,dp,0,s.size()-1);
        return ans;
    }
    int minInsertions(string s) {
        int n=s.size();
        return n-longestPalindromicSubsequence(s);
        
    }
};

/*
BOTTOM UP
TC:O(N^2)
SC:O(N^2)
*/

class Solution {
public:

// LPS FUNCTION
    int longestPalindromicSubsequence(string &s){
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int len=1;len<=n;len++){
            for(int start=0;start<=(n-len);start++){
                int end=len+start-1;
                //[start,end] string under consideration
                if(len==1){
                    dp[start][end]=1;
                    continue;

                }
                if(s[start]==s[end]){
                    dp[start][end]=2+dp[start+1][end-1];
                }
                else{
                   dp[start][end]=max(dp[start+1][end],dp[start][end-1]); 
                }

            }
        }
        return dp[0][n-1];
    }
    int minInsertions(string s) {
        int n=s.size();
        return n-longestPalindromicSubsequence(s);
        
    }
};


