PROBLEM :https://leetcode.com/problems/find-the-difference-of-two-arrays/description/
VIDEO:

/*

BRUTE FORCE

Time complexity: O(MlogM + NlogN)
Space complexity: O(M+N)

PSEUDO CODE
1.take a set1 and put distinct elements of nums1
2.take a set2 and put distinct elements of nums2
3.take a vector
4.traverse in set1.......if that element is not in set2..then push in a vector
finally after traversing the whole set1...........push it in ans

5.traverse in set12.......if that element is not in set1..then push in a vector
finally after traversing the whole set2...........push it in ans

6.return ans
*/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        unordered_set<int> s1;
        unordered_set<int> s2;
        
        //push in nums1 in set1

        for(int i:nums1)
         s1.insert(i);

         //push in nums2 in set2

        for(int j:nums2)
         s2.insert(j);

         //take a vector
         vector<int>v;

         ///traverse in set1
         for(auto it:s1){
             if(s2.find(it)==s2.end()){
                 v.push_back(it);
             }
         }

         //answer[0]
         ans.push_back(v);
         v.clear();


         ///traverse in set2
         for(auto it:s2){
             if(s1.find(it)==s1.end()){
                 v.push_back(it);
             }
         }

         //answer[1]
         ans.push_back(v);
         return ans;
    }
};
