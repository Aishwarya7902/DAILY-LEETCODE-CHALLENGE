PROBLEM:https://leetcode.com/problems/summary-ranges/description/
VIDEO:https://www.youtube.com/watch?v=PyYZCJRAMmY

/*

*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int start=nums[i];
            while(i+1<n && nums[i]+1==nums[i+1]){
                i++;
            }
            if(start!=nums[i]){
            result.push_back(to_string(start)+"->"+to_string(nums[i]));
        }
        else{
            result.push_back(to_string(start));
        }
        }
        
        return result;
    }
};
