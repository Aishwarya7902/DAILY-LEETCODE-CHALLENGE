PROBLEM:https://leetcode.com/problems/merge-strings-alternately/description/
VIDEO:
BLOG:


/*

SELF
TC:O(M+N)
SC:O(1)
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int m=word1.size();
        int n=word2.size();
        //initialize i--->word1, j--->word2
        int i=0,j=0;
        while(i<m && j<n){
            ans.push_back(word1[i++]);
            ans.push_back(word2[j++]);

        }
         while(i<m ){
            ans.push_back(word1[i++]);

        }
         while(j<n){
            ans.push_back(word2[j++]);
        }
        return ans;

    }
};
