PROBLEM:https://leetcode.com/problems/find-the-duplicate-number/description/?envType=daily-question&envId=2023-09-19
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=49HrEGt6D2s

/*
  NOTE [NOT RIGHT]
  COZ WE HAVE BEEN ASKED TO USE only constant extra space
  
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


/*
  NOTE [NOT RIGHT]
  COZ WE HAVE BEEN ASKED TO USE only constant extra space
  method 2
  using map
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int &n:nums){
            mp[n]++;
        }

        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]>1)return nums[i];
        }
        return -1;
    }
};

/*
  USING SLOW AND FAST POINTER
  RIGHT
  TC:O(N)
  SC:O(1)
  */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        slow=nums[slow];
        fast=nums[nums[fast]];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];

        }
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];

        }
        return slow;

    }
};



