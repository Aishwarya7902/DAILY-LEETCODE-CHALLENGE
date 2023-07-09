PROBLEM:https://leetcode.com/problems/substring-with-largest-variance/

VIDEO:

/*
  BRUTE FORCE(TLE)
  1.generate all subsequences
  2.for every subsequence find variance as defined in the question
  3.update ans with max(ans,above value)
  4.return ans

  */class Solution {
public:
    int maxVar(string s,int i,int j){
        unordered_map<char,int>mp;
        for(int k=i;k<=j;k++){
            mp[s[k]-'a']++;
        }
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(auto it:mp){
            mn=min(mn,it.second);
            mx=max(mx,it.second);
        }
        return mx-mn;
    }
    int largestVariance(string s) {
        int ans=INT_MIN;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans=max(ans,maxVar(s,i,j));
            }
        }
        return ans;
    }
};
