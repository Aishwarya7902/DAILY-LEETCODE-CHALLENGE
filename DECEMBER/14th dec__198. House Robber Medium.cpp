problem:https://leetcode.com/problems/house-robber/description/
best blog:https://leetcode.com/problems/house-robber/solutions/156523/from-good-to-great-how-to-approach-most-of-dp-problems/?orderBy=most_votes
video (striver bhaiya):https://youtu.be/GrMBfJNk_NY

/*
RECURSIVE __tle
TC: O(2^n)
SC:O(2^n) //recursive stack space

*/

class Solution {
private:
int helper(int indx,vector<int>& nums){
    if(indx<0)return 0;
    if(indx==0)return nums[indx];
    int pick=nums[indx]+helper(indx-2,nums);
    int notPick=0+helper(indx-1,nums);
    return max(pick,notPick);
}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        return helper(n-1,nums);
    }
};
                                 
/*
MEMOIZATION
TC: O(N)
SC: O(N) //auxiliary stack space +O(N) //for dp vector
*/
class Solution {
private:
int helper(int indx,vector<int>& nums,vector<int>&dp){
    if(indx<0)return 0;
    if(indx==0)return nums[indx];
    //if already stored simply return it
    if(dp[indx]!=-1)return dp[indx];
    int pick=nums[indx]+helper(indx-2,nums,dp);
    int notPick=0+helper(indx-1,nums,dp);
    return dp[indx]=max(pick,notPick);
}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return helper(n-1,nums,dp);
    }
}; 

/*
TABULATION
TC: O(N)
SC:O(N) //no auxiliary stack space
*/

class Solution {

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1)
             take+=dp[i-2];
            int notTake=0+dp[i-1];
            dp[i]=max(take,notTake);
        }
        return dp[n-1];
    }
};
                                 
                                 
                                
                                 
