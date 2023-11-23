PROBLEM:https://leetcode.com/problems/arithmetic-subarrays/description/?envType=daily-question&envId=2023-11-23
VIDEO:https://www.youtube.com/watch?v=ErHay1GfIqw

/*
  TC:O(M*NlogN)
  SC:O(N)
*/class Solution {
public:
    bool check(vector<int>& arr){
        sort(begin(arr),end(arr));
        int d=arr[1]-arr[0];
        for(int i=2;i<arr.size();i++){
            if(arr[i]-arr[i-1]!=d)return false;
        }

        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int  m=l.size();
        vector<bool>result;
        for(int i=0;i<m;i++){
            int start=l[i];
            int end=r[i];
            vector<int>arr(begin(nums)+start,begin(nums)+end+1);
            bool isAp=check(arr);
            result.push_back(isAp);

        }
        return result;
    }
};

/*  OPTIMISATION
    TC:O(M*N)
    SC:O(N)
*/

class Solution {
public:
    bool check(vector<int>& arr){
        int n=arr.size();
        int maxE=INT_MIN;
        int minE=INT_MAX;
        unordered_set<int>st;
        for(int &num:arr){
            minE=min(minE,num);
            maxE=max(maxE,num);
            st.insert(num);
        }

        if((maxE-minE)%(n-1)!=0)return false;
        int d=(maxE-minE)/(n-1); //tn=a+(n-1)d
        int curr=minE;
        while(curr<maxE){
            if(st.find(curr)==st.end())return false;
            curr+=d;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int  m=l.size();
        vector<bool>result;
        for(int i=0;i<m;i++){
            int start=l[i];
            int end=r[i];
            vector<int>arr(begin(nums)+start,begin(nums)+end+1);
            bool isAp=check(arr);
            result.push_back(isAp);

        }
        return result;
    }
};
