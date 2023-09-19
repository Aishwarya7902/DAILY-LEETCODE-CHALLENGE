PROBLEM:https://leetcode.com/problems/find-the-duplicate-number/description/?envType=daily-question&envId=2023-09-19
VIDEO(MIK BHAIYA):

/*
  METHOD 1
  USING SET
  1.traverse in nums
  2.if that no is not present in set ,insert it
  3.if that no is already in set , return that no...(it means that no is repeated)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(int x:nums){
            if(s.find(x)==s.end()){
                s.insert(x);
            }
            else
             return x;
        }
        return-1;
    }
};
