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


  /************************************************ C++ *******************************************************/
//OPTIMISATION-1 (Using Binary Search)
//T.C : O(nlogn)
//S.C : O(n) for prefixSum for effienctly calculating windowSum

class Solution {
public:
    int BinarySearch(vector<int>& nums,int target_indx,int k,vector<long>& prefixSum){
     int target=nums[target_indx];
     int l=0;
     int r=target_indx;
     int best_indx=target_indx;
     while(l<=r){
         int mid=l+(r-l)/2;
         long count=target_indx-mid+1;
         long windowSum=count*target;
         long currSum=prefixSum[target_indx]-prefixSum[mid]+nums[mid];
         int operation=windowSum-currSum;
         if(operation>k){
             l=mid+1;
         }

         else{
             best_indx=mid;
             r=mid-1;
         }
     }

     return target_indx-best_indx+1;
        
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));//TC:o(nlogn)
        vector<long> prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        
        int result=0; //to store our answer

        for(int target_indx=0;target_indx<n;target_indx++){ //o(n)
            int frequency=BinarySearch(nums,target_indx,k,prefixSum);//o(n)
            result=max(result,frequency);
        }

        return result;
        
    }
};

  //Approach-2 (Using sliding window)
//T.C : O(nlogn)
//S.C : O(1)

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int result=0;
        int l=0;
        long currSum=0;
        for(int r=0;r<n;r++){
            long target=nums[r];
            currSum+=nums[r];
            // long windowSum=(r-l+1)*target;
            // long opt=windowSum-currSum;
            while((r-l+1)*target-currSum>k){
                currSum-=nums[l];
                l++;
            }

            result=max(result,r-l+1);
        }
        return result;
    }
};

//Approach-3 (Improved sliding window)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        
        int n = nums.size();
        
        int result = 0;
        
        int i = 0;
        long currSum = 0;
        
        for(int j = 0; j<n; j++) {
            
            long target = nums[j];
            currSum   += nums[j];
            
            if((j-i+1)*target - currSum > k) {
                currSum -= nums[i];
                i++;
            }
            
            result = max(result, j-i+1);
            
        }
        return result;
    }
};

  
