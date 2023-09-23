PROBLEM:https://leetcode.com/problems/longest-string-chain/description/?envType=daily-question&envId=2023-09-23
VIDEO (MIK BHAIYA):https://www.youtube.com/watch?v=HtTVSgs5ViE

/*
 tc:
 sc:
*/

class Solution {
public:
    int dp[1001][1001];
    int n;
    //comparator function
    static bool comp(string &word1,string &word2){
        return word1.length()<word2.length();

    }
    //predecessor function
    bool isPred(string &prev,string&curr){
        int M=prev.size();
        int N=curr.size();
        if(M>=N || N-M!=1)return false;
        int i=0,j=0;
        while(i<M && j<N){
            if(prev[i]==curr[j])i++;
            j++;
        }
        return i==M;
    }
    //LIS function

    int LIS(vector<string>& words,int prev_indx,int curr_indx){
        if(curr_indx==n)return 0;
        if( prev_indx!=-1 && dp[prev_indx][curr_indx]!=-1)return dp[prev_indx][curr_indx];
        int taken=0,not_taken=0;
        if(prev_indx==-1 || isPred(words[prev_indx],words[curr_indx])){
            taken=1+LIS(words,curr_indx,curr_indx+1);
        }
        not_taken=LIS(words,prev_indx,curr_indx+1);
        if(prev_indx!=-1){
            dp[prev_indx][curr_indx]=max(taken,not_taken);
        }

        return max(taken,not_taken);
    }
    int longestStrChain(vector<string>& words) {
        n=words.size();
        sort(begin(words),end(words),comp);
        memset(dp,-1,sizeof(dp));
        return LIS(words,-1,0);
    }
};
