PROBLEM:https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=QFjOkJt5hrI

/*
  TC: O(N)
  SC:
*/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        vector<vector<int>> result;
        //key-val
        //key= size of grp
        //val= people in that grp

        vector<vector<int>>mp(n+1);// size of grp can be 1 to n

        for(int i=0;i<n;i++){
            int L=groupSizes[i];
            mp[L].push_back(i);
            if(mp[L].size()==L){
                result.push_back(mp[L]);
                mp[L]={};
            }
        }
        return result;
    }
};
