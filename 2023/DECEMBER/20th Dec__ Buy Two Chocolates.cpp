PROBLEM :https://leetcode.com/problems/buy-two-chocolates/description/?envType=daily-question&envId=2023-12-20
VIDEO (MIK BHAIYA):https://www.youtube.com/watch?v=MihxAUNFac0

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

/*
  OPTIMISATION
  TC:O(N)
  SC:O(1)
  */

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int minPrice=INT_MAX;
        int secMinPrice=INT_MAX;
        for(int price:prices){
            if(price<minPrice){
                secMinPrice=minPrice;
                minPrice=price;
            }
            else{
                secMinPrice=min(secMinPrice,price);
            }
        }
        if(minPrice+secMinPrice>money)return money;
        return money-(minPrice+secMinPrice);

    }
};
