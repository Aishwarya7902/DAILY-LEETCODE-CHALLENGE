PROBLEM:https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/
/*
TC
SC
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool>res(n,0);
        int maxi=INT_MIN;
        for(auto x:candies)
         maxi=max(maxi,x);
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxi)
             res[i]=1;
        }
        return res;
    }
};
