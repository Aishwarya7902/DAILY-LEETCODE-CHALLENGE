PROBLEM:https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
VIDEO:https://www.youtube.com/watch?v=JpQaui_-a4c

/*
BRUTE FORCE
TC:O(N)+O(NlogN)
SC:
*/

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
       vector<int>require(n,0);
       //travel to get the required rocks to completely fill
       //i.e to reuired=capacity-currently present in bag
       for(int i=0;i<n;i++){
       require[i]=capacity[i]-rocks[i];
       } 
       //sort because we will try to maximize bags with full capacity by using additionalRocks
       sort(require.begin(),require.end());
       for(int i=0;i<n;i++){
           if(additionalRocks>=require[i]){
               additionalRocks-=require[i];
               require[i]=0;
           }
       }
       //see how many bags are completely filled
       int cnt=0;
       for(auto x:require){
           if(x==0)cnt++;
       }
       return cnt;
    }
};

/*little better code
*/

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
       vector<int>require(n,0);
       //travel to get the required rocks to completely fill
       //i.e to reuired=capacity-currently present in bag
       for(int i=0;i<n;i++){
       require[i]=capacity[i]-rocks[i];
       } 
       //sort because we will try to maximize bags with full capacity by using additionalRocks
       sort(require.begin(),require.end());
       int cnt=0;
       for(int i=0;i<n;i++){
           if(additionalRocks>=require[i]){
               additionalRocks-=require[i];
               cnt++;
           }
           else{
               break;
           }
       }
    
       return cnt;
    }
};
