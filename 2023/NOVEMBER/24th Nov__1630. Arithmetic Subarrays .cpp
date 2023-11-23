PROBLEM:https://leetcode.com/problems/arithmetic-subarrays/description/?envType=daily-question&envId=2023-11-23
VIDEO:https://www.youtube.com/watch?v=ErHay1GfIqw

/*
  TC:O(M*NlogN)
  SC:O(N)
*/class Solution {
public:
    bool check(vector<int>& arr){
        sort(begin(arr),end(arr));
        int d=arr[1]-arr[0];
        for(int i=2;i<arr.size();i++){
            if(arr[i]-arr[i-1]!=d)return false;
        }

        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int  m=l.size();
        vector<bool>result;
        for(int i=0;i<m;i++){
            int start=l[i];
            int end=r[i];
            vector<int>arr(begin(nums)+start,begin(nums)+end+1);
            bool isAp=check(arr);
            result.push_back(isAp);

        }
        return result;
    }
};
