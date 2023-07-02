PROBLEM:https://leetcode.com/problems/fair-distribution-of-cookies/description/

VIDEO:https://www.youtube.com/watch?v=vcaAC2fqFpk

/*
  TC:O(k^n) // since every child has n possibility and there are total of k children
  */

class Solution {
public:
    int n;
    int ans=INT_MAX;
    void solve(int indx,vector<int>& cookies,vector<int>&children,int k){
        if(indx>=n){
            int unfairness=*max_element(begin(children),end(children));
            ans=min(ans,unfairness);
            return;
        }
        int cookie=cookies[indx];
        for(int i=0;i<k;i++){
            children[i]+=cookie;
            solve(indx+1,cookies,children,k);
            //backtrack
            children[i]-=cookie;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
       n=cookies.size();
       vector<int>children(k,0);
       solve(0,cookies,children,k);
       return ans; 
    }
};
