PROBLEM:https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/?envType=daily-question&envId=2023-11-18

VIDEO(MIK BHAIYA):

/*
  BRUTE FORCE (GIVES TLE)__ done by self🙅‍♂️
 TC: O(nlogn) + O(n^2)
 SC: O(1)

*/

class Solution {
public:
    int solve(vector<int>& nums,int indx, int k){

        int count=0; ///to store how many numbers can be converted to number at index named indx

        for(int i=indx;i>=0;i--){
            if((nums[indx]-nums[i])<=k ){
                count++;
                k-=nums[indx]-nums[i];
            }
        }
        return count;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));//TC:o(nlogn)
        int result=1; //to store our answer

        for(int i=0;i<n;i++){ //o(n)
            int possibleConversions=solve(nums,i,k);//o(n)
            result=max(result,possibleConversions);
        }

        return result;
        
    }
};
