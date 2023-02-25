PROBLEM:
VIDEO:

/*
TC:O(N)
SC:O(1)
PSEUDO CODE:
1.every day try to sell and see if u get a better result.............for selling ...try to find the min buy from 0 to (i-1)th index
2.return  the maximum result

NOTE : WHY IT IS DP🤔.............COZ WE ARE TRYING TO REMEMEBR THE PAST NA........PAST KA MIN KO YAD RAKH RAHE

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int ans=0;
       int bestBuy=prices[0]; 
       for(int i=1;i<prices.size();i++){
           ans=max(ans,prices[i]-bestBuy);
           bestBuy=min(bestBuy,prices[i]);
       }
       return ans;
    }
};
