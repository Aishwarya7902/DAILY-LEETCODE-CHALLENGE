PROBLEM:https://leetcode.com/problems/maximum-ice-cream-bars/description/
VIDEO:https://www.youtube.com/watch?v=uY3mWwJvRkA

/*
DONE BY MYSELF
*/

class Solution {
public:
//tc:o(nlogn)+o(n)
//sc(1) we are not using any extra space
    int maxIceCream(vector<int>& costs, int coins) {
        //sort the cost array
        sort(costs.begin(),costs.end());//tc:o(nlogn)
        int maxIceBars=0;
        for(int i=0;i<costs.size();i++){//tc:o(n)
            if(costs[i]>coins)return maxIceBars;
            else{
                maxIceBars++;
                coins-=costs[i];
            }
        }
        return maxIceBars;
    }
};
