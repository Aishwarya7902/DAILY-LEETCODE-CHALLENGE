PROBLEM: https://leetcode.com/problems/find-median-from-data-stream/
VIDEO: https://www.youtube.com/watch?v=fpDDEgx6OmA

/*
METHOD 1 (TLE)
TC: nlogn+ o(n) //sorting+ n times function call hoga
SC:
*/

#include<bits/stdc++.h>
class MedianFinder {
public:
    vector<double>data;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       data.push_back(num); 
    }
    
    double findMedian() {
      sort(data.begin(),data.end());
      int n=data.size();
      if(n%2!=0){
        return double(data[n/2]);
      }
     
        int first=n/2;
        int second=first-1;
       double sum=data[first]+data[second];
        double ans=sum/2;
        return ans;
      
    }
};

