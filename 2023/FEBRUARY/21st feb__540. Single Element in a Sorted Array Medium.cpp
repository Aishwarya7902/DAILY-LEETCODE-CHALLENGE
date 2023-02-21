PROBLEM:https://leetcode.com/problems/single-element-in-a-sorted-array/description/
VIDEO: 1.(STRIVER BHAIYA) :https://www.youtube.com/watch?v=PzszoiY5XMQ
        2.(TECH DOSE) : https://www.youtube.com/watch?v=nMGL2vlyJk0

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



/*METHOD 3 (BEST ONE)
*/

/*
feel❤️
single element aane ke pahleka scenario kuch aisa hoga
even odd | even odd | even odd.....
but soon as hamare hero ki entry hoti hai ....(which is single element)...hamare even+odd wali ordering kharab ho jayegi ...
now the ordering will be something like
odd even |odd even |odd even
*/

/*
💕sara khel break point ka hai
1.check if u r on the lefthalf of the breakpoint or not...if yes
shrink the left half

2.otherwise shrink the right half

3.at last low will point to break point
*/


/*
❤️crux part
1.if mid index is odd then doing a xor with 1 will given even index right before it

2.if mid index is even then doing a xor with 1 will given odd index right after it

3.above two conditions will generate
1st instance->even
2nd instance->odd

it means we are in the left half of breakpoint ..hence shrink left
hence low=mid+1

4.else
high=mid-1

*/

//⌚time complexity :o(n)

//🚀space complexity: o(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()-2;
        while(low<=high){
            int mid=(low+high)>>1;
            if(nums[mid]==nums[mid^1])
             low=mid+1;
            else
             high=mid-1;
        }
        return nums[low];
    }
};
