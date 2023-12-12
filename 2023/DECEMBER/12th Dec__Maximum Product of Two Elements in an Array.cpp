PROBLEM :https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/?envType=daily-question&envId=2023-12-12
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=YtmAMnBjUkg

/*
  TC:O(N)
  SC:O(1)
  */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int curr_max=nums[0];
        int result=0;
        for(int i=1;i<n;i++){
            result=max(result,(nums[i]-1)*(curr_max-1));
            curr_max= max(curr_max,nums[i]);
        }
        return result;
    }
};

/*
method 2
  tc:o(n)
  sc:o(1)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest=0;
        int second_largest=0;

        for(int &num:nums){
            if(num>largest){
                second_largest=largest;
                largest=num;
            }
            else{
                second_largest=max(second_largest,num);
            }
        }
        return (largest-1)*(second_largest-1);
    }
};
