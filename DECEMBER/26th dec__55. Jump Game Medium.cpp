PROBLEM:
VIDEO (MAZHAR BHAIYA) :

/*
RECURSION
TC:EXPONENTIAL
SC:
*/

class Solution {
private:
bool solve(vector<int>& nums,int n,int indx){
    if(indx==n-1)return true; //we reached last index...return true
    if(indx>n-1)return false; //if we go out of bound it means we never reached last index..return false!!!!!!!

    //at every index we can take steps from 1 to nums[i]....,(except nums[i]=0)....hence we try every possibility at this step...and if anyone of them returns  true ....we also return true...no need to check further.
    for(int i=1;i<=nums[indx];i++){
        if(solve(nums,n,indx+i))return true;
    }
    return false;//if none of the above returns true ..return false.
}
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        //call our solve function
        return solve(nums,n,0);
    }
};

/*
memoization:
tc: 
sc:
*/


class Solution {
private:
int dp[10001];
bool solve(vector<int>& nums,int n,int indx){
    if(indx==n-1)return true; 
    if(indx>n-1)return false; 
    if(dp[indx]!=-1)return dp[indx];
    for(int i=1;i<=nums[indx];i++){
        if(solve(nums,n,indx+i))return dp[indx]=true;
    }
    return dp[indx]=false;
}
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        //call our solve function
        memset(dp,-1,sizeof(dp));
        return solve(nums,n,0);
    }
};
