PROBLEM : https://leetcode.com/problems/permutations/description/

VIDEO(MAZHAR BHAIYA) : https://www.youtube.com/watch?v=T8hqjK94Fig

/*
  APPROACH 1

  TC: O(N*N!) //for clarity please watch video
  SC:
*/

class Solution {
public:
    vector<vector<int>> result;
    unordered_set<int>st;
    int n;

    void solve(vector<int>& temp,vector<int>& nums){
        if(temp.size()==n){
            result.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){

            if(st.find(nums[i])==st.end()){

                //khandani backtracking

                //do something
                temp.push_back(nums[i]);
                st.insert(nums[i]);

                //explore

                solve(temp,nums);

                //backtrack

                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<int>temp;
        solve(temp,nums);
        return result;
    }
};
