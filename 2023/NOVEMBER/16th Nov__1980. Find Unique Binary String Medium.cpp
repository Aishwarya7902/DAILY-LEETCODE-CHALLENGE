PROBLEM:https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2023-11-16
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=8Cay8q3BOx4

/*
  TC:O(n^2)
  SC:o(n)

  */

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int>st;
        for(string &num:nums){
            st.insert(stoi(num,0,2));
        }

        int n=nums.size();
        string res="";
        for(int i=0;i<=n;i++){
            if(st.find(i)==st.end()){
                res=bitset<16>(i).to_string();
                return res.substr(16-n,n);
            }
        }
        return "";
    }
};

