PROBLEM:https://leetcode.com/problems/reducing-dishes/description/
blog:
video:

/*
recursion
This idea is such that, after sorting, you have two choices for a particular dish. Either make it or skip it. Sorting is so that, you don't have to search the entire array for making the next best choice.
Also, higher the satisfaction, the higher time we prefer.

tc:2^n
sc:
*/
class Solution {
public:
    int helper(vector<int>& satisfaction,int indx,int time,int n){
        if(indx>=n)return 0;
        int taken=satisfaction[indx]*time+helper(satisfaction,indx+1,time+1,n);
        int not_taken=helper(satisfaction,indx+1,time,n);
        return max(taken,not_taken);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        return helper(satisfaction,0,1,n);
    }
};
/*
memoization
tc:
sc:
*/

class Solution {
public:
    int helper(vector<int>& satisfaction,int indx,int time,int n,vector<vector<int>>&dp){
        if(indx>=n)return 0;
        if(dp[indx][time]!=-1)return dp[indx][time];
        int taken=satisfaction[indx]*time+helper(satisfaction,indx+1,time+1,n,dp);
        int not_taken=helper(satisfaction,indx+1,time,n,dp);
        return dp[indx][time]=max(taken,not_taken);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(satisfaction,0,1,n,dp);
    }
};
