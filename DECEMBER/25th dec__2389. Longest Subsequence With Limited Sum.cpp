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
