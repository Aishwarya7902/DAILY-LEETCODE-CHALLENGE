problem:https://leetcode.com/problems/house-robber/description/
best blog:https://leetcode.com/problems/house-robber/solutions/156523/from-good-to-great-how-to-approach-most-of-dp-problems/?orderBy=most_votes

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
                                 
                                 
                                
                                 
