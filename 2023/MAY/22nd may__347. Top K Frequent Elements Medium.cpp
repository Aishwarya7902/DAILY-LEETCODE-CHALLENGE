PROBLEM:https://leetcode.com/problems/top-k-frequent-elements/description/
VIDEO:


/*
tc: o(nlogn +n)
sc:o(n)
*/

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //take a vector to store the result
        vector<int> result;
        //store in freq map
        unordered_map<int,int>mp;
        for(int num :nums){
            mp[num]++;
        }

        //put map in pair of vector for ease
        vector<pair<int,int>>v;
        for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    v.push_back(*itr);

        sort(v.begin(), v.end(), [](auto &left, auto &right) {
    return left.second > right.second;
});


        //travel in v and take k most frequent elements
        for(auto it:v){
            if(k){
                result.push_back(it.first);
                k--;

            }
            else{
                break;
            }
        }
        //return result
        return result;

    }
};
