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

/*
DYNAMIC PROGRAMMING:
tc:o(n)
sc:o(n)

*/
class Solution {
public:
    int tribonacci(int n) {
        if(n==0)return 0;
        if(n==1 || n==2)return 1;
       vector<int>dp(n+1);
       dp[0]=0;
       dp[1]=1;
       dp[2]=1;
       for(int i=3;i<=n;i++){
           dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
       }
       return dp[n];
    }
};
