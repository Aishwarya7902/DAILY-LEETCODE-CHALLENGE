PROBLEM :https://leetcode.com/problems/buy-two-chocolates/description/?envType=daily-question&envId=2023-12-20
VIDEO (MIK BHAIYA):

/*
  BRUTE FORCE
  TC:O(nlogn)
  SC:O(1)

*/

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(begin(prices),end(prices));
        int req_money=prices[0]+prices[1];

        if (req_money<=money)
         return money-req_money;

        return money;
    }
};
