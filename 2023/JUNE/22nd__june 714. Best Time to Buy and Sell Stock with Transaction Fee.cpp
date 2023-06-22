PROBLEM:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
VIDEO(MAZHAR BHAIYA):https://www.youtube.com/watch?v=yN5K5T3aw8M


class Solution {
public:
    int t[500001][2];
    int solve(vector<int>& prices, int fee,int indx,int n,bool buy){
        if(indx>=n)return 0;
        if(t[indx][buy]!=-1)return t[indx][buy];
        int profit=0;
        if(buy){
            int taken=solve(prices,fee,indx+1,n,false)-prices[indx]-fee;
            int not_taken=solve(prices,fee,indx+1,n,true);
            profit=max({profit,taken,not_taken});
        }
        else{
            int sell=prices[indx]+solve(prices,fee,indx+1,n,true);
            int not_sell=solve(prices,fee,indx+1,n,false);
            profit=max({profit,sell,not_sell});
        }
        return t[indx][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        memset(t,-1,sizeof(t));
        bool buy=true;
        return solve(prices,fee,0,n,buy);
    }
};
