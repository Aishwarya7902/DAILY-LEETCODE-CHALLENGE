PROBLEM:https://leetcode.com/problems/gas-station/description/
VIDEO(BEST VIDEO : MAZHAR BHAIYA):https://www.youtube.com/watch?v=tcOcmNHFTTM

/*
NAIVE APPROACH
TC:O(N^2)
SC:O(1)
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int  n=gas.size();
        for(int i=0;i<n;i++){
            if(gas[i]<cost[i])continue;
            int j=(i+1)%n;
            int costForMovingFromThisStation=cost[i];
            int gasEarnInNextStation=gas[j];
            int currGas=gas[i]-costForMovingFromThisStation+gasEarnInNextStation;
            while(j!=i){
                if(currGas<cost[j])break;
                int costForMovingFromThisJ=cost[j];
                j=(j+1)%n;
                int gasEarnInNextJ=gas[j];
                currGas=currGas-costForMovingFromThisJ+gasEarnInNextJ;
            }
            if(i==j)return i;
             
        }
        return -1;
    }
};
