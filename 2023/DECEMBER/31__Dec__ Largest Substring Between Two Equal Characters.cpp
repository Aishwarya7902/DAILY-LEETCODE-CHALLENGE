PROBLEM :https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/?envType=daily-question&envId=2023-12-31
VIDEO(MIK BHAIYA):

  /*
  DID ON MY OWN 🥳
  TC:
  SC:
  */

  
class Solution {
public:
void FindLastIndex(string &s,char target, vector<int>&LastIndex){
       for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == target) {
           LastIndex[target-'a']=i;
           return; // Return the index of the first occurrence
        }
     }
}
    void FindFirstIndex(string &s,char target, vector<int>&FirstIndex){
       for (int i = 0; i < s.size(); ++i) {
        if (s[i] == target) {
           FirstIndex[target-'a']=i;
           return ; // Return the index of the first occurrence
        }
     }
}
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>LastIndex(26,-1);
        vector<int>FirstIndex(26,0);
    //STEP 1 : finding first and last index for every character
        for(char &ch:s){
            FindFirstIndex(s,ch,FirstIndex);
            FindLastIndex(s,ch,LastIndex);
        }

    //STEP 2: take result
    int result=-1;
    // STEP 3: update result

    for(int i=0;i<26;i++){
        result=max(result,LastIndex[i]-FirstIndex[i]-1);
    }


     return result;   
        
    }
};
