PROBLEM:https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
VIDEO:

/*
  BRUTE FORCE
  we just have to return  index of the element with max val
TC: O(N)
SC:O(1)
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans=0;
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxi){
                maxi=arr[i];
                ans=i;
            }
        }
        return ans;
        
    }
};


/*
optimisation

1.take a priority queue
2.put all elements along with its index
3.return index of top element ...........since it is max

TC:O(log(n))
SC:O(n)
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        priority_queue<pair<int,int>>pq;//val,indx
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        return pq.top().second;
        
    }
};
