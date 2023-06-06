PROBLEM :https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/
VIDEO (MAZHAR BHAIYA) :https://www.youtube.com/watch?v=RgeDl_pjWog

/*
METHOD 1
SIMPLY CHECK ALL DIFFERENCE IS SAME OR NOT
TC:O(NLOGN)
SC:O(1)
*/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
       sort(arr.begin(),arr.end());
       int diff=arr[1]-arr[0];
       for(int i=2;i<arr.size();i++){
           if(arr[i]-arr[i-1]!=diff)return false;
       } 
       return true;
    }
};


/*
approach 2
tc:o(n)
sc:o(n)
*/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();
       unordered_set<int>s(begin(arr),end(arr));

       int min_el=*min_element(begin(arr),end(arr));//a
       int mx_el=*max_element(begin(arr),end(arr));//a+(n-1)d
       if((mx_el-min_el)%(n-1)!=0){
           return false;
       }
       int d=(mx_el-min_el)/(n-1);
       int i=0;
       while(i<n){
           int num=min_el+i*d;
           if(s.find(num)==s.end())return false;
           i++;
       }
      


       return true;
    }
};

