PROBLEM:https://leetcode.com/problems/single-element-in-a-sorted-array/description/
VIDEO:

/*
SELF
TC:O(N)
SC:O(N)
PSEUDO CODE
1.store frequency of each element in map
2.traverse in array ....if frequency in map is 1 ...return that element
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
    for(auto it:nums){
        mp[it]++;
    }
    for(auto x:nums){
        if(mp[x]==1)return x;
    }
    return 0;
    }
};

/*
method 2
Time complexity:
o(N)

Space complexity:
o(1)

Intuition
do a simple xor .....at last xor will contain single element

*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int xorr=0;
      for(auto x:nums){
          xorr=xorr^x;
      } 
      return xorr; 
    }
};
