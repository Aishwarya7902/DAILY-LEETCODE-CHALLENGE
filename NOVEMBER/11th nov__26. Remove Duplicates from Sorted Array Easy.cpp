PROBLEM:
VIDEO (STRIVER BHAIYA):

/*
NAIVE APPROACH
🟦USING A SET
🟦 TC: O(n)
🟦 SC: O(n)
🟦MISTAKE: after u store in set ...now we know  set stores in ascending order....so we have to store the elements in nums rigth from starting index ..i.e zero
since question says TO : "Return k after placing the final result in the first k slots of nums"
🟦LEARNING: set stores elements in ascending order
*/

#include<set>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     set<int>s;
      for(auto it:nums){
        s.insert(it);
      }
      int i=0;
      for(auto it:s){
        nums[i]=it;
        i++;
      }
      return s.size();
    }
};



