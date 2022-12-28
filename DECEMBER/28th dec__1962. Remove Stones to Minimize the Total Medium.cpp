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

/*
optimisation using a maxheap
tc:O(n+klogn)
sc:o(n)

intuition:
1.take a max heap
2.push all array elements to it
3.now we will be greedy ,since we have to find min no of stones left after all the operations, hence we will remove those piles first which have highest no of stones...........now since we have taken a max heap then our top will automatically store the maxValue
4.take top of pq i.e maxVal, and remove floor(maxVal) stones from it
5.push the resultant of the above stones in the heap again
6.repeat these operations k times

7. finally return no of stones after all operations are finished
*/

#include<queue>
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
      priority_queue<int>pq; //by default it is a maxheap
      //insert evrything in queue
      for(auto x:piles){ //tc:o(n)
          pq.push(x);
      }
      //perform operation k times
      while(k--){ 
          //tc:o(k*logn) coz insert/delete takes logn in a heap ,and we are performing this operation k times
          int maxVal=pq.top(); //top of will have max value
          pq.pop();
          maxVal-=floor(maxVal/2);
          pq.push(maxVal);
      } 
      //get no of stones after all operations
      int stone=0;
      while(!pq.empty())
      {
          stone+=pq.top();
          pq.pop();
      } 
      return stone;
    }
};


/*
JUST AN A BETTER CODE
*/
#include<queue>
class Solution {
public:

    int minStoneSum(vector<int>& piles, int k) {
      priority_queue<int>pq(piles.begin(),piles.end()); 
      
      while(k--){ 
          int maxVal=pq.top(); 
          pq.pop();
          maxVal-=floor(maxVal/2);
          pq.push(maxVal);
      } 
      int stone=0;
      while(!pq.empty())
      {
          stone+=pq.top();
          pq.pop();
      } 
     
      return stone;
    }
};
 
