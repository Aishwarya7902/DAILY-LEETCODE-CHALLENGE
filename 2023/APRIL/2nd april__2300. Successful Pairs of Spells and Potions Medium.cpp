PROBLEM:https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
VIDEO:
BLOG:

/*
METHOD 1
brute force
tc:o(n^2)
sc:o(1)
pseudo code
1.for every ith spell , check how many potions can
contribute towards its success.............push that cnt in ans
2.return ans

*/

class Solution {
public:
    //helper function
    int helpNumberOfSuccess(int val,vector<int>& potions, long long success)
    {
        int cnt=0;
        for(int &num:potions){
            long long strength=long(num)*long(val);
            if(strength>=success)cnt++;
        }
        return cnt;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

       int n=spells.size();
       vector<int>ans(n);
       for(int i=0;i<n;i++){
           ans[i]=helpNumberOfSuccess(spells[i],potions,success);
       }
       return ans; 
    }
};
