PROBLEM:https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/description/?envType=daily-question&envId=2023-10-07
VIDEO(MIK BHAIYA):https://youtu.be/YU9IGG5PB2Y?si=lfactYuyba5aQYoL

class Solution {
public:
    int t[51][51][101];
    int N,M,K;
    int MOD=1e9+7;
    //helper function
    int solve(int indx,int search_Cost,int maxSoFar){
        if(indx==N){
            if(search_Cost==K)return 1;
            return 0;
        }
        if(t[indx][search_Cost][maxSoFar]!=-1)
           return t[indx][search_Cost][maxSoFar];

        //try out at every index ....all the possibilities
        int result=0;

        for(int i=1;i<=M;i++){
            if(i>maxSoFar){
              result=(result+solve(indx+1,search_Cost+1,i))%MOD;
            }
            else{
             result=(result+solve(indx+1,search_Cost,maxSoFar))%MOD;
            }
        }
        return t[indx][search_Cost][maxSoFar]=result%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(t,-1,sizeof(t));
        return solve(0,0,0);
    }
};
