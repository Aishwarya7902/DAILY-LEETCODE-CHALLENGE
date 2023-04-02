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

/*
method 2
for finding how many potions can contribute toward success
use binary search for that
sort potions array
for eg if jth potion contributes towards success...then starting from j till last index all will
contribute
*/

class Solution {
public:

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

       int n=spells.size();
       int m=potions.size();
       sort(potions.begin(),potions.end());
       vector<int>ans(n);
       for(int i=0;i<n;i++){
           int val=spells[i];
           int lo=0,hi=m-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            long long prod=long(val)*long(potions[mid]);
            if(prod>=success)
             hi=mid-1;
            else
             lo=mid+1;
        }
        ans[i]=m-lo;
       }
       return ans; 
    }
};

