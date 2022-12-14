problem:https://leetcode.com/problems/house-robber/description/
best blog:https://leetcode.com/problems/house-robber/solutions/156523/from-good-to-great-how-to-approach-most-of-dp-problems/?orderBy=most_votes

/*
RECURSIVE __tle
TC: O(2^n)
SC:O(2^n) //recursive stack space

*/

class Solution {
int helper(vector<int>& nums,int n){
    if(n<=0)
     return 0;
     
    int option1=nums[n-1]+helper(nums,n-2);
    int option2=helper(nums,n-1);
    return max(option1,option2);

}
public:
    int rob(vector<int>& nums) {
       int n=nums.size();
       
       return helper(nums,n,dp); 
    }
};
                                 
/*
MEMOIZATION
TC: O(N)
SC: O(N) //auxiliary stack space +O(N) //for dp vector
*/
class Solution {
int helper(vector<int>& nums,int n,vector<int>&dp){
    if(n<=0)
     return 0;
     if(dp[n]!=-1)return dp[n];
    int option1=nums[n-1]+helper(nums,n-2,dp);
    int option2=helper(nums,n-1,dp);
    return dp[n]=max(option1,option2);

}
public:
    int rob(vector<int>& nums) {
       int n=nums.size();
       vector<int>dp(n+1,-1);
       return helper(nums,n,dp); 
    }
};
                                 
                                 
                                 
                                
                                 
