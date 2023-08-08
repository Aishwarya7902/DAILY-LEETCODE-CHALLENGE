PROBLEM:https://leetcode.com/problems/search-in-rotated-sorted-array/description/
VIDEO:https://www.youtube.com/watch?v=U1VsdRgVevY

/*
  BRUTE FORCE
  TC:O(N)
  SC:O(1)

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target)return i;
        }
        return -1;
        
    }
};

/*
optimisation USING binary search
TC:
*/

class Solution {
public:
    int n;
    //helper 1
    int binarySearch(int l,int r,vector<int>& nums,int target){
        int indx=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                indx=mid;
                break;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return indx;
    }
    //helper 2
    int findPivot(vector<int>& nums){
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return r;

    }
    int search(vector<int>& nums, int target) {
        n=nums.size();
        int pivot_index=findPivot(nums);
        int indx=binarySearch(0,pivot_index-1,nums,target);
        if(indx!=-1)
         return indx;
        indx=binarySearch(pivot_index,n-1,nums,target);
        return indx;
        
    }
};
