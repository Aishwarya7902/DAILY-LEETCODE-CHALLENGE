PROBLEM: https://leetcode.com/problems/minimum-average-difference/

/*
METHOD 1:
GAVE TLE
TC: O(N^2)
SC:O(1)
*/

#include<bits/stdc++.h>
class Solution {
private:
  int findAvg(vector<int>& nums,int st,int end){
    long long int sum=0;
    for(int i=st;i<=end;i++){
      sum+=nums[i];
    }
    int size=end-st+1;
    if(size==0)return 0;
    return sum/size;
  }
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
      //handling base case
      int min_val=INT_MAX,indx=-1;
        if(n==1)return 0;
      for(int i=0;i<n;i++){
        int avg1=findAvg(nums,0,i);
        int avg2=findAvg(nums,i+1,n-1);
        int avgDiff=abs(avg1-avg2);
        if(avgDiff<min_val){
          min_val=avgDiff;
          indx=i;
        }
      }
      return indx;
    }
};

/*
METHOD 2
Intuition: We just have to take average difference and return the index giving minimum average difference.
->Take out totalsum which will be sum of all n elements and currentsum which will be the sum till ith index
->Calculate the avg1 till ith index and avg2 till n-1-ith index.
->Now take absolute diff btw avg1 and avg2 and keep tracking the index giving minimum diff.
->return the index giving minimum diff..

Time Complexity => O(N)
Space Complexity => O(1)

*/#include<bits/stdc++.h>
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
      //handling base case
      int min_val=INT_MAX,indx=-1;
      long long int sum=0, currsum=0;
      for(auto x:nums){
        sum+=x;
      }
        
      for(int i=0;i<n;i++){
        currsum+=nums[i];
       long long  int sum1=currsum;
       long long int sum2=sum-currsum;
        int size1=i+1;
        int size2=n-i-1;
        int avg1=sum1/size1;
        int avg2;
        if(size2==0)
          avg2=0;
        else
          avg2=sum2/size2;
        int diff=abs(avg1-avg2);
        if(diff<min_val){
          min_val=diff;
          indx=i;
        }
      }
      return indx;
    }
};

