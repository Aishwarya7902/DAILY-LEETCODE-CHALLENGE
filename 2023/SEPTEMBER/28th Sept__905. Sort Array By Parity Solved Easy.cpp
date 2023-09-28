PROBLEM:https://leetcode.com/problems/sort-array-by-parity/description/?envType=daily-question&envId=2023-09-28
VIDEO:

//tc:o(n)
//sc:o(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n,0);
        int k=0;
        int i=0,j=n-1;
        while(i<=j){
            if(nums[k]%2==0){
                result[i]=nums[k];
                i++;
            }
            else{
                result[j]=nums[k];
                j--;
            }
            k++;

        }
        return result;
    }
};
