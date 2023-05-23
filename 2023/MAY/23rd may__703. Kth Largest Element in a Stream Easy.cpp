PROBLEM :https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

VIDEO :

/*
BRUTE FORCE (TLE)
TC:
SC:
*/

class KthLargest {
public:
    int K;
    vector<int>data;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        data=nums;
        
    }
    
    int add(int val) {
        data.push_back(val);
        sort(data.begin(),data.end());
        int n=data.size();
        return data[n-K]; 
      // element at n-1 index will be 1st largest element
      // element at n-2 index will be 2nd largest element
      // element at n-3 index will be 3rd largest element
      .
      .
      .
      .
      // element at n-k index will be kth largest element
        
    }
};


/*
OPTIMISATION USING PRIORITY QUEUE
TC: O(nlogn)
SC: O(k)
*/

class KthLargest {
public:
    int K;
    //take min heap coz we will remove all the smaller elements till size of pq >k
   priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        //put all the elements of nums in priority queue
        for(int num:nums)
         pq.push(num);
        
    }
    
    int add(int val) {
        //push val in pq
        pq.push(val);
         // remove smaller elements untill size of pq is k
        while(pq.size()>K){
            pq.pop();
        }
        //now the top most element will be the kth largest element
        return pq.top();
        
    }
};

