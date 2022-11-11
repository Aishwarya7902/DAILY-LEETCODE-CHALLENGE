PROBLEM: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
VIDEO (STRIVER BHAIYA): https://www.youtube.com/watch?v=Fm_p9lJ4Z_8

/*
NAIVE APPROACH
🟦USING A SET
🟦 TC: O(nlogn) + O(n) // n for traversing in array and logn for inserting in set + n to take elements out of the set and place them in the array(in worst case 
all the elements of the array are unique)
🟦 SC: O(n) //(in worst case all the elements of the array are unique so u will have to store them in the set)
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



