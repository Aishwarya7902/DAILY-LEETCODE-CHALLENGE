PROBLEM:https://leetcode.com/problems/daily-temperatures/description/
VIDEO:https://www.youtube.com/watch?v=ZhZEmGv-sOY

/*
brute force
tc:O(n^2)
sc:o(1)
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {      //initialize a vector to store the ans
        vector<int>ans;
   //run the loop
   int n=temperatures.size();
   for(int i=0;i<n;i++){
       bool check=false;
       for(int j=i+1;j<n;j++){
           if(temperatures[j]>temperatures[i]){
               ans.push_back(j-i);
               check=true;
               break;
           }
       }
     if(check==false)
      ans.push_back(0);
   }
     return ans;   
 }
};
/*
THIS QUESTION CAN BE SOLVED IN EXACTLY THE SAME WAY AS WE FIND NEXT GREATER ELEMENT IN ARRAY USING  A STACK
TC:O(n)
SC:O(1)
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {   
        
        stack<int>st;
        int n=temperatures.size();
        vector<int>ans(n,0);
        for(int j=n-1;j>=0;j--){
            if(st.empty()){
                ans[j]=0;
            }
           else if(temperatures[st.top()]<=temperatures[j]){
                while(!st.empty() && temperatures[st.top()]<=temperatures[j]){
                    st.pop();
                }
                if(st.empty()){
                    ans[j]=0;
                }
                else{
                    ans[j]=st.top()-j;
                }
            }
           else if(temperatures[st.top()]>temperatures[j]){
               ans[j]=st.top()-j;
           }
           st.push(j) ;
        }
     return ans;   
    }
};
