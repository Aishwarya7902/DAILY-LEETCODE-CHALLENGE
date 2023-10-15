PROBLEM: bit.ly/3PT7DaB
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=Tk70PLqbYH4

/*
  RECURSION
  TC:O(3^N)
  */


/*
  MEMOIZATION
  TC:O(min(arrLen,steps)*steps)
  SC:O(min(arrLen,steps)*steps)
*/


class Solution {
public:
    int n;
    int t[501][501];
    int MOD=1e9+7;
    int solve(int indx,int steps){
        if(indx<0 || indx>=n)
         return 0;
        if(steps==0)
         return indx==0;
        if(t[indx][steps]!=-1)return t[indx][steps];
        int result=(solve(indx-1,steps-1))%MOD;//left
         result=(result+solve(indx+1,steps-1))%MOD;//right
        result=(result+solve(indx,steps-1))%MOD;//stat

        t[indx][steps]=result%MOD;
         return t[indx][steps];
    }
    int numWays(int steps, int arrLen) {
        arrLen=min(arrLen,steps);
        n=arrLen;
        memset(t,-1,sizeof(t));
         return solve(0,steps);
    }
};
