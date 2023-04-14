PROBLEM:https://leetcode.com/problems/longest-palindromic-subsequence/description/
VIDEO:
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


