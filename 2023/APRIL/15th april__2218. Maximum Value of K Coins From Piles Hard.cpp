PROBLEM:https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/
VIDEO: (MAZHAR BHAIYA) :https://youtu.be/sH276uTmZ80
(ARYAN MITTAL):

/*
RECURSION
TC:
SC:
*/

class Solution {
public:
    int n;
    
    int solve(int i,vector<vector<int>>& piles, int k){
        if(i>=n)return 0;
       
        int not_taken=solve(i+1,piles,k);
        int taken=0;
        int sum=0;
        for(int j=0;j< min((int)piles[i].size(),k);j++)
        {
            sum+=piles[i][j];
            taken=max(taken,sum+solve(i+1,piles,k-(j+1)));
        }
        return max(taken,not_taken);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        return solve(0,piles,k);
        
    }
};

/*
MEMOIZATION
TC:
SC:
*/
class Solution {
public:
    int n;
    int dp[1001][2001];
    int solve(int i,vector<vector<int>>& piles, int k){
        if(i>=n)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int not_taken=solve(i+1,piles,k);
        int taken=0;
        int sum=0;
        for(int j=0;j< min((int)piles[i].size(),k);j++)
        {
            sum+=piles[i][j];
            taken=max(taken,sum+solve(i+1,piles,k-(j+1)));
        }
        return dp[i][k]=max(taken,not_taken);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,piles,k);
        
    }
};
