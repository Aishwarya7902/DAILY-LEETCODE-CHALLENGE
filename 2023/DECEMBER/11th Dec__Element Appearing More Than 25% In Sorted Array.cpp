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

/*
  METHOD 2:
  TC:O(N)
  SC:O(1)
  */

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int freq=n/4;
       
        for(int i=0;i<n-freq;i++){
            if(arr[i]==arr[i+freq])return arr[i];
        }
        return -1;

    }
};

/*
  METHOD 3
  TC: o(3*logn)
  SC:
  */

class Solution {
public:
      int findRightIndex(int cand,int l,int r,vector<int>&arr){
        int result_idx=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==cand){
                result_idx=mid;
                l=mid+1;
            }
            else if(arr[mid]<cand){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return result_idx;
    }
    int findLeftIndex(int cand,int l,int r,vector<int>&arr){
        int result_idx=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==cand){
                result_idx=mid;
                r=mid-1;
            }
            else if(arr[mid]<cand){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return result_idx;
    }
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int freq=n/4;
       
        vector<int>candidates{arr[n/4],arr[n/2],arr[3*n/4]};
        for(int &cand:candidates)
        {
            int left_idx=findLeftIndex(cand,0,n-1,arr);
            int right_idx=findRightIndex(cand,0,n-1,arr);
            if(right_idx-left_idx+1>freq)return cand;

        }

        return -1;

    }
};
