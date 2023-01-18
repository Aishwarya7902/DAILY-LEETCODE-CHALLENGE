PROBLEM:
VIDEO:
//tc:o(n)
//sc:o(1)

//see what we are going to here is :


        /*for maximum subarray sum in circular , what we have to do is ....the maxsum can come in two ways....
        1.either from normal subarray
        2.or from circular one
        step 1-> for  max sum in normal subarray , we can simply use kadane's algo to find maxSum in subarray
        step 2-> for  max sum in circular subarray 
        what we do here is ...lets say total sum of array is S and maxSum be S1
        and rest part be S2
        hence :
        S1+S2=S
       => S1=S-S2
       for S1 to be max we have to minimize S2, it means S2 is minSum
       step 3->
       for getting circular sum
       get Sum of nums
       get minSum
       circular_sum=Sum-minSum
       (as explained above)
       */
        
#include<bits/stdc++.h>
class Solution {
private:
//kadane for max sum
int kadaneMax(vector<int>& nums,int n){
  int sum=nums[0];
  int maxSum=nums[0];
  for(int i=1;i<n;i++){
      sum=max(sum+nums[i],nums[i]);//ya to past+now is better ,else ek nayi suruat karo
      maxSum=max(maxSum,sum);
  }
  return maxSum;
}
//kadane for min Sum
int kadaneMin(vector<int>& nums,int n){
  int sum=nums[0];
  int minSum=nums[0];
  for(int i=1;i<n;i++){
      sum=min(sum+nums[i],nums[i]);//ya to past+now is better ,else ek nayi suruat karo
      minSum=min(minSum,sum);
  }
  return minSum;
}
public:
    int maxSubarraySumCircular(vector<int>& nums) {
      int n=nums.size();
      //1
      int SUM=accumulate(begin(nums),end(nums),0);
      //2
      int minSum=kadaneMin(nums,n);
      //3
      int maxSum=kadaneMax(nums,n);
      //4
      int circular_sum=SUM-minSum;
      if(maxSum>0){
          return max(maxSum,circular_sum);
      }
     return maxSum;
        

    }
};
