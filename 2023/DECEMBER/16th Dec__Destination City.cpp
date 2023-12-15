PROBLEM:https://leetcode.com/problems/destination-city/description/?envType=daily-question&envId=2023-12-15
VIDEO(MIK BHAYIYA):https://www.youtube.com/watch?v=GyHzuQC7sd8

/*
  METHOD 1
  USING HASHMAP
  */

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
       //one which has outdegree==0 is the ans
       int V=paths.size();
       unordered_map<string,int>mp;
       for(auto &vec:paths){
           string source=vec[0];
           
           mp[source]=1;
       } 
       for(auto &vec:paths){
           string dest=vec[1];
           if(mp[dest]!=1)return dest;
           
       } 
       return "";
    }
};

/*
METHOD 2
USING HASHSET
  */

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
       //one which has outdegree==0 is the ans
       
       unordered_set<string>st;
       for(auto &vec:paths){
           string source=vec[0];
           
           st.insert(source);
       } 
       for(auto &vec:paths){
           string dest=vec[1];
           if(st.find(dest)==st.end())return dest;
           
       } 
       return "";
    }
};
