PROBLEM:https://leetcode.com/problems/maximize-score-after-n-operations/description/
VIDEO:https://www.youtube.com/watch?v=CTYIzzT9agE

/*
RECURSION + MEMO

TC: 2^n * n^2 * logm
SC:
*/

class Solution {
public:
    int n;
    int solve(vector<int>& nums,vector<bool>&vis,int opt,unordered_map<vector<bool>,int>&mp){
        if(mp.find(vis)!=mp.end())return mp[vis];
        int maxScore=0;
        for(int i=0;i<=n-2;i++){
            if(vis[i]==true)continue;
            for(int j=i+1;j<n;j++){
                if(vis[j]==true)continue;
                vis[i]=true;
                vis[j]=true;
                int currScore=opt*(__gcd(nums[i],nums[j]));
                int remainScore=solve(nums,vis,opt+1,mp);
                maxScore=max(maxScore,currScore+remainScore);
                vis[i]=false;
                vis[j]=false;
            }
        }
        return  mp[vis]=maxScore;
    }
    int maxScore(vector<int>& nums) {
        n=nums.size();
        vector<bool>vis(n,false);
        unordered_map<vector<bool>,int>mp;
        return solve(nums,vis,1,mp);
        
    }
};
