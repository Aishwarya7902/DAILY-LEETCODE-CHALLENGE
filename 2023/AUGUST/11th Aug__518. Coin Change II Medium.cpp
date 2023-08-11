PROBLEM:https://leetcode.com/problems/coin-change-ii/description/
VIDEO(mik bhaiya):https://www.youtube.com/watch?v=HhSZQkdJZok

/*
  RECURSION 

  TC:
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
