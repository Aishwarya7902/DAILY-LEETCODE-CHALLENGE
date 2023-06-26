PROBLEM : https://leetcode.com/problems/total-cost-to-hire-k-workers/description/

VIDEO: https://www.youtube.com/watch?v=ODuICq8exLo

/*
TC : O(K* log(candidates))
SC :O(log(candidates))

*/


class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
      int n=costs.size();
      priority_queue<int,vector<int>,greater<int>> pq1,pq2;
      long long ans=0;
      int hired=0;
      int i=0,j=n-1;
      while(hired<k){
          while(pq1.size() <candidates && i<=j){
              pq1.push(costs[i]);
              i++;
          }

          while(pq2.size() <candidates && j>=i){
              pq2.push(costs[j]);
              j--;
          }

          int min_pq1=pq1.size()>0 ? pq1.top() :INT_MAX;
          int min_pq2=pq2.size()>0 ? pq2.top() :INT_MAX;

          if(min_pq1<=min_pq2)
          {
              ans+=min_pq1;
              pq1.pop();
          }

          else{
              ans+=min_pq2;
              pq2.pop();
          }
          hired++;
      }
      return ans;
    }
};
