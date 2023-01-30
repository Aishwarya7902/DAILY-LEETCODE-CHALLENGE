PROBLEM:https://leetcode.com/problems/n-th-tribonacci-number/description/
VIDEO:

/*
recursion
tle
tc:o(n^3)
sc:o(n^3)
*/

class Solution {
public:
    int tribonacci(int n) {
       if(n==0)return 0;
       if(n<=2)return 1;
       int ans=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
       return  ans;
    }
};
