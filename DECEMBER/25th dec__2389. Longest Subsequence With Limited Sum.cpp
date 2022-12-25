PROBLEM:
VIDEO:

/*
BRUTE FORCE
TC: exponential for generating all possible subsequences
SC:
*/

#include<bits/stdc++.h>
class Solution {
private:
//generate all possible subsequence
void subseq(vector<int>& nums,int indx,vector<int>&ds,vector<vector<int>>&possible){
    if(indx==nums.size()){
        possible.push_back(ds);
    }
    else{
        //take
        ds.push_back(nums[indx]);
        subseq(nums,indx+1,ds,possible);
        ds.pop_back();
        subseq(nums,indx+1,ds,possible);
    }
}
int getMaxSizeSumK(vector<int>& nums,int requiredSum){//this func will give u max size of subarray having sum equal to queries[i]
    int maxi=0;
    vector<vector<int>>possible;//this will hold all possible subsequences
    vector<int>ds; //store current subsequence

    subseq(nums,0,ds,possible); //call subsequence function

    for(auto it:possible){ //travel in all possible subseq and if its sum==required sum then update maxi with the it's size 
        int sum=0;
        for(int i=0;i<it.size();i++){
            sum+=it[i];
        }
        if(sum<=requiredSum){
            if(it.size()>maxi){
                maxi=it.size();
            }
        }
    }
return maxi; //return max size of subarrya having required sum
}
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    vector<int> ans(queries.size(),0);//take to store ans
    for(int i=0;i<queries.size();i++){
        int maxSubSeqSize=getMaxSizeSumK(nums,queries[i]); //this func will give u max size of subarray having sum equal to queries[i];

        ans[i]=maxSubSeqSize; //put max size in ans
    }
    return ans; //return ans
    }
};



/*
method 2
optimised
*/
class Solution {
public:
    //tc:o(nlogn+mlogn) see video for clarity
    //https://www.youtube.com/watch?v=KYBB-yFPgF8 (got this on youtube🙂)
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>ans;
        //we are sorting ,because if we take smaller elements first then we can maximize the size subsequence
        sort(nums.begin(),nums.end());
        //make a prefix vector
        vector<int>prefix(nums.size(),0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=0;i<queries.size();i++){
            int query=queries[i];
            ans.push_back(upper_bound(prefix.begin(),prefix.end(),query)-prefix.begin());
        }
        return ans;
    }
};
