PROBLEM:https://leetcode.com/problems/verifying-an-alien-dictionary/description/
VIDEO:
BLOG:

/*
SELF

TC:
SC:
*/

class Solution {
private:
bool rankIsRight(string s1,string s2,unordered_map<char,int>&rank){
    int i=0,j=0;
    while(i<s1.size() && j<s2.size()){
        if(rank[s1[i]]<rank[s2[j]])return true;
        else if(rank[s1[i]]>rank[s2[j]])return false;
        else{
            i++;
            j++;
        }
    }

    //if both i and j reaches end means they are in lexicographic oreder 

    //if only i reaches end means they are in lexicographic oreder  eg..According to lexicographical rules "app" < "apple", because '∅' < 'l', where '∅' is defined as the blank character which is less than any other character
    return (i==s1.size() && j==s2.size()) || i==s1.size();
}
public:
    bool isAlienSorted(vector<string>& words, string order) {
      unordered_map<char,int>rank;
      //finding out the rank
      for(int i=0;i<order.size();i++){
          rank[order[i]]=i;
      }  
      //checking every word for lexicographic order
      for(int i=0;i<words.size()-1;i++){
          if(rankIsRight(words[i],words[i+1],rank)==false)return false;
      }
      return true;
    }
};
