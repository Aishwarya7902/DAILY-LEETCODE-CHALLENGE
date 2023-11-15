PROBLEM:https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/?envType=daily-question&envId=2023-11-15

VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=HGkK9n5CUaY

/*
  TC:O(nlogn)
  SC:
*/

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        sort(begin(arr),end(arr));
        int maxEl=-1;
        for(int i=0;i<n;i++){
            if(i==0)
             arr[0]=1;
            else if(abs(arr[i]-arr[i-1])>1)
             {
                 arr[i]=arr[i-1]+1;
                
             }
              maxEl=max(maxEl,arr[i]);
        }
        return maxEl;
    }
};
