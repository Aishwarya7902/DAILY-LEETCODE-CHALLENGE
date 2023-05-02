PROBLEM:https://leetcode.com/problems/sign-of-the-product-of-an-array/description/
blog:https://leetcode.com/problems/sign-of-the-product-of-an-array/description/


/*
Approach
---->The problem asks us to determine the sign of the product of all the numbers in the given array. To solve this problem, we need to consider the following cases:
---->If the product of all the numbers is positive, the sign is 1.
---->If the product of all the numbers is negative, the sign is -1.
---->If the product of all the numbers is zero, the sign is 0.

1.To compute the product of all the numbers in the array, we can iterate over the array and count the total negative numbers. 
2.We can initialize the cnt as 0 and then update it at each step of the iteration.
3.At any index, if number is 0, simply return 0.
4.Once we have computed the product, we can determine the sign of the product using an if-else statement. 
5.If the cnt is odd, the sign is -1. If the cnt is even, the sign is 1.
6.Therefore, we can write a function that takes an array as input, computes the count of negative numbers in the array, and returns the sign of the product.
Complexity

Time complexity:O(N)
Space complexity:O(1)

*/
class Solution {
public:
   
    int arraySign(vector<int>& nums) {
        int cnt=0;
        for(int i:nums){
           if(i==0)return 0;
           if(i<0)cnt++;
        }
        return cnt%2!=0 ? -1 : 1;
        
    }
};
