PROBLEM:https://leetcode.com/problems/kth-missing-positive-number/description/
VIDEO:

/*
METHOD 1
PSEUDO CODE
tc:o(n)
sc:o(1)
1.if all elements of array are greater than k ..it means k elements are already missing..hence return k
2.if not ....k++
3.return k
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       for(auto a:arr){
           if(a<=k)k++;
       } 
       return k;
    }
};

/*
method 2
tc:o(logn)
sc:o(1)
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int lo=0,hi=arr.size();
       while(lo<hi){
           int mid=lo+(hi-lo)/2;
           if(arr[mid]-mid>k)
            hi=mid;
           else
            lo=mid+1;
       }
       return hi+k;
    }
};
