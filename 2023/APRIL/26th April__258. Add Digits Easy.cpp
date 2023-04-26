PROBLEM:https://leetcode.com/problems/add-digits/description/
VIDEO:
BLOG:

/*
BRUTE FORCE :
TC:
SC:
*/

class Solution {
public:
    //helper function
    int findSum(int x){
        int sum=0;
        while(x){
            int rem=x%10;
            sum+=rem;
            x/=10;
        }
        return sum;
    }
    int addDigits(int n) {
        if(n<10)return n;
        int currSum=findSum(n);
        if(currSum<10)return currSum;
        return addDigits(currSum);
    }
};
