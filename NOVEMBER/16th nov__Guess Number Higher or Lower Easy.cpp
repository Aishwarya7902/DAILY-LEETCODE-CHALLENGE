PROBLEM: https://leetcode.com/problems/guess-number-higher-or-lower/

/*
pseudo code:
1. our guess should lie between 1 to n 
2.simply assume there is an array from 1 to n
3.simply apply binary search

tc: o(logn)
sc:o(1)
*/

class Solution {
public:
    int guessNumber(int n) {
        int strt=1,end=n;
      while(strt<=end){
        int mid=strt+(end-strt)/2;
        int pos=guess(mid);
        if(pos==0)return mid;
        else if(pos==-1)end=mid-1;
        else
          strt=mid+1;
      }
      return -1;
    }
};
