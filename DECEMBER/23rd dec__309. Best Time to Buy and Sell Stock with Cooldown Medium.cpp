PROBLEM:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
VIDEO(MAZHAR BHAIYA....BEST VIDEO): https://www.youtube.com/watch?v=iTvEXpOAyHY
/*
RECURSION
TC:2^n
sc:2^n
*/


class Solution {
private:
int solve(vector<int>& prices,int day,int n,bool buy){
    if(day>=n)return 0;
    int profit=0;
    if(buy){
        int take=solve(prices,day+1,n,false)-prices[day];
        int not_take=solve(prices,day+1,n,true);
        profit=max({profit,take,not_take});
    }
    else{
        int sell=prices[day]+solve(prices,day+2,n,true);
        int not_sell=solve(prices,day+1,n,false);
        profit=max({profit,sell,not_sell});
    }
  return profit;  
}
public:
    int maxProfit(vector<int>& prices) {
      int n=prices.size();
      bool buy=true;
      return solve(prices,0,n,buy);  
    }
};

/*
MEMOIZATION
TC: O(n^2)
SC: o(5000*2) which is nearly constant
*/

class Solution {
private:
int dp[5001][2];
int solve(vector<int>& prices,int day,int n,bool buy){
    if(day>=n)return 0;
    if(dp[day][buy]!=-1)return dp[day][buy];
    int profit=0;
    if(buy){
        int take=solve(prices,day+1,n,false)-prices[day];
        int not_take=solve(prices,day+1,n,true);
      profit=max({profit,take,not_take});
    }
    else{
        int sell=prices[day]+solve(prices,day+2,n,true);
        int not_sell=solve(prices,day+1,n,false);
        profit=max({profit,sell,not_sell});
    }
  return dp[day][buy]=profit;  
}
public:
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
      int n=prices.size();
      bool buy=true;
      return solve(prices,0,n,buy);  
    }
};


/*BOTTOM UP
TC:O(N^2)
SC:O(N)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1)return 0;
        vector<int>dp(n,0);
        dp[0]=0;
        dp[1]=max(prices[1]-prices[0],0);
        for(int i=2;i<n;i++){//sell
         dp[i]=dp[i-1];
         for(int j=0;j<=i-1;j++){//for every i find best possible buy
         int today_profit=prices[i]-prices[j];
         int prev_profit=j>2 ?dp[j-2] :0;
         dp[i]=max(dp[i],today_profit+prev_profit);

         }
        }
        return dp[n-1];
    }
};
