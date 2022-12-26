PROBLEM:
VIDEO (MAZHAR BHAIYA) :

/*
RECURSION
TC:EXPONENTIAL
lets say max value in nums is k 
hence k k k k k ...n times= k^n
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

/*
BOTTOM UP
TC:O(N^2)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
       int n=nums.size();
       vector<bool>dp(n,false);
       //You are initially positioned at the array's first index ...so  definately it is reachable
       dp[0]=1;
       for(int i=1;i<n;i++){
           //for every i ,I go back if somene is already reachable and it can take me to my index then it put it as true
           for(int j=i-1;j>=0;j--){
               if(dp[j]==true && j+nums[j]>=i){
                dp[i]=true;
                break;
               } 
           }
       }
    return dp[n-1];
    }
};

