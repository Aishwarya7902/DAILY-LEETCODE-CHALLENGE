PROBLEM:https://leetcode.com/problems/kth-missing-positive-number/description/
VIDEO:

/*
METHOD 1
PSEUDO CODE
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
