PROBLEM:https://leetcode.com/problems/coin-change-ii/description/
VIDEO(mik bhaiya):https://www.youtube.com/watch?v=HhSZQkdJZok

/*
  RECURSION 

  TC: at every point of time we have 2 options....take and not take....hence tc is o(2^n)
  SC:

*/

class Solution {
public:
    int n;
    //helper

    int solve(int indx,int amount, vector<int>& coins){
        //base case1
        if(amount==0){
            return 1;
        }
        //base case2

        if(indx>=n)
        {
             return 0;
        }
        //base case3

        if(coins[indx]>amount)
         {
             return solve(indx+1,amount,coins);
         }
        int taken=solve(indx,amount-coins[indx],coins);
        int not_taken=solve(indx+1,amount,coins);
        return (taken+not_taken);
    }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        return solve(0,amount,coins);
    }
};


/*
memoization
tc:o(indx*amount)
sc:
*/

class Solution {
public:
    int n;
    int t[301][5001];
    //helper

    int solve(int indx,int amount, vector<int>& coins){
        //base case1
        if(amount==0){
            return 1;
        }
        //base case2

        if(indx>=n)
        {
             return 0;
        }

        if(t[indx][amount]!=-1)
         return t[indx][amount];
        //base case3

        if(coins[indx]>amount)
         {
             return t[indx][amount]=solve(indx+1,amount,coins);
         }
        int taken=solve(indx,amount-coins[indx],coins);
        int not_taken=solve(indx+1,amount,coins);
        return t[indx][amount]=(taken+not_taken);
    }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        memset(t,-1,sizeof(t));
        return solve(0,amount,coins);
    }
};
