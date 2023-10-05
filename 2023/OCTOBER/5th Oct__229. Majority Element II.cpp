PROBLEM :https://leetcode.com/problems/majority-element-ii/description/?envType=daily-question&envId=2023-10-05
VIDEO(MIK BHAIYA):

/*
  BRUTE FORCE
  DONE BY SELF 💪
  *///tc:o(n)
//sc:o(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int n=nums.size();
        int target= int (floor(n/3));
        //take a map and  store the frequency
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;

        }
        //travel in map and if an element has freq greater than target...push in result
        for( auto it:mp){
            int val=it.first;
            int freq=it.second;
            if(freq>target)result.push_back(val);

        }
        return result;
    }
};
