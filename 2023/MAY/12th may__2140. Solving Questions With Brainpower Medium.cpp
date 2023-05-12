PROBELEM :https://leetcode.com/problems/solving-questions-with-brainpower/description/

VIDEO:https://www.youtube.com/watch?v=NcC8lo7nLCE

/*
RECUSRION + MEMO
TC
SC
*/

class Solution {
public:
    int n;
    long long solve(int indx,vector<vector<int>>& questions,vector<long long>&dp){
        //base case
        if(indx>=n)return 0;
        if(dp[indx]!=-1)return dp[indx];
        long long take=questions[indx][0]+solve(indx+questions[indx][1]+1,questions,dp);
        long long  not_take=solve(indx+1,questions,dp);
        return dp[indx]=max(take,not_take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
       n=questions.size();
       vector<long long>dp(n+1,-1);
       return solve(0,questions,dp); 
    }
};
