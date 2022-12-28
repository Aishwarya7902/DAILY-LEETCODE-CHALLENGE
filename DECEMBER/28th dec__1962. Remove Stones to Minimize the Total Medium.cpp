PROBLEM:https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/
VIDEO:

/*
BRUTE FOCE :TLE
tc:O(k*nlogn)
sc:O(1)
*/

#include<math.h>
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
      sort(piles.begin(),piles.end(),greater<int>());
      while(k){
          piles[0]-=floor(piles[0]/2);
          k--;
          sort(piles.begin(),piles.end(),greater<int>());
      } 
      int stoneMinCount=0; 
      for(auto x:piles){
       stoneMinCount+=x; 
      }
      
      return stoneMinCount;
    }
};
