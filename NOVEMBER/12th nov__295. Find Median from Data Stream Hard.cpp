PROBLEM: https://leetcode.com/problems/find-median-from-data-stream/
VIDEO: https://www.youtube.com/watch?v=fpDDEgx6OmA

/*
METHOD 1 (TLE)
TC: nlogn+ o(n) //sorting+ n times function call hoga
SC:

MISTAKE: ki mera wrong ans aa raha tha ....coz pahle sort karne ke bad mean ,mode and median nikala jata hai (class 10th yaad karo)
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

/*
method 2
tc: O(1) //coz top element nikal rahe + log(n) for insertion in priority queue 
sc:
*/

class MedianFinder {
public:
  priority_queue<int>mx_heap;
  priority_queue<int,vector<int>,greater<int>>min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
     if(mx_heap.size()>0 && num>mx_heap.top()){
       min_heap.push(num);
     } 
      else{
        mx_heap.push(num);
      }
      if(mx_heap.size()>min_heap.size()+1){
        min_heap.push(mx_heap.top());
        mx_heap.pop();
      }
      if(min_heap.size()>mx_heap.size()+1){
        mx_heap.push(min_heap.top());
        min_heap.pop();
      }
    }
    
    double findMedian() {
        if(min_heap.size()==mx_heap.size()){
          return (min_heap.top()+mx_heap.top())/2.0;
        }
      else if(mx_heap.size()>min_heap.size()){
        return mx_heap.top();
      }
      return min_heap.top();
    }
};
