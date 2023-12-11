PROBLEM:https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/?envType=daily-question&envId=2023-12-11
VIDEO(MIK BHAIYA):

/*
  SELF BUILD
  TC:O(N)
  SC:O(N)
*/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int reqFreq=int(floor(n/4));
        unordered_map<int,int>freq;
        for(int &num:arr){
            freq[num]++;
            if(freq[num]>reqFreq)return num;
        }
        return -1;

    }
};
