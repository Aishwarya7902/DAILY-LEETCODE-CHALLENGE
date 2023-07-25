PROBLEM:https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
VIDEO (MAZHAR BHAIYA):https://www.youtube.com/watch?v=Op07kT-LoH8

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

TC:O(log(n)) + O(n)
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


/*
USING BINARY SEARCH
TC:O(log(n))
SC:O(1)
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=l+ (r-l)/2;
            if(arr[mid]<arr[mid+1]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return r;
    }
};
