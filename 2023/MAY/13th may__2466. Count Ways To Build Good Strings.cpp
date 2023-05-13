PROBLEM:https://leetcode.com/problems/count-ways-to-build-good-strings/description/
VIDEO:(MAZHAR BHAIYA) https://www.youtube.com/watch?v=G-i4CveBSYI

/*
RECURSION
TC
SC
*/

class Solution {
public:
    int l,h;
    int z,o;
    int solve(int len){
        if(len>h)return 0;
        bool addOne=false;
        if(len>=l && len<=h){
            addOne=true;
        }

        int append_zero=solve(len+z);
        int append_one=solve(len+o);
        return addOne+append_zero+append_one;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        l=low;
        h=high;
        o=one;
        z=zero;
        return solve(0);
        
    }
};

/*
MEMOIZATION
TC
SC
*/

class Solution {
public:
    int l,h;
    int z,o;
    const int MOD=1e9+7;
    int solve(int len, vector<int>&dp){
        if(len>h)return 0;
        if(dp[len]!=-1)return dp[len];
        bool addOne=false;
        if(len>=l && len<=h){
            addOne=true;
        }

        int append_zero=solve(len+z,dp);
        int append_one=solve(len+o,dp);
        return dp[len]=(addOne+append_zero+append_one)%MOD;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        l=low;
        h=high;
        o=one;
        z=zero;
        //since only one parameter is changing ....hence we need a 1d dp array
        vector<int>dp(high+1,-1);
        return solve(0,dp);
        
    }
};
