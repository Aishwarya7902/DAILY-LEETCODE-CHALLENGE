PROBLEM:https://leetcode.com/problems/longest-palindromic-substring/description/?envType=daily-question&envId=2023-10-27
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=n_kL8BkURVA


/*
  RECURSION
  */

class Solution {
public:
    //function to check palindrome
    bool solve(string &s,int i,int j){
        if(i>=j)return true;
        if(s[i]==s[j])return solve(s,i+1,j-1);
        return false;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=INT_MIN;
        int sp=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxLen);
    }
};


/*

memoization
tc:
sc:
*/

class Solution {
public:
    //function to check palindrome
    int t[1001][1001];
    bool solve(string &s,int i,int j){
        if(i>=j)return 1;
        if(t[i][j]!=-1)return t[i][j];
        if(s[i]==s[j])return t[i][j]=solve(s,i+1,j-1);
        return t[i][j]=0;
    }
    string longestPalindrome(string s) {
        memset(t,-1,sizeof(t));
        int n=s.size();
        int maxLen=INT_MIN;
        int sp=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxLen);
    }
};

