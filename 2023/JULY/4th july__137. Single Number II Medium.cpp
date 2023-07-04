PROBLEM:https://leetcode.com/problems/single-number-ii/description/
VIDEO :(MAZHAR BHAIYA) 

 class Solution {
public:
    //tc: O(n)
    //sc:O(n)
    int singleNumber(vector<int>& nums) {
        //take a map
        unordered_map<int,int>mp;

        //store elements and its frequency
        for(auto i:nums){
            mp[i]++;
        }

        //travel in nums and check if any element has a freq of one

        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==1)return nums[i];
        }
        return -1;

    }
};
