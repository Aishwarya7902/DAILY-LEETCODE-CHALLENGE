PROBLEM:https://leetcode.com/problems/find-the-difference/description/?envType=daily-question&envId=2023-09-25
VIDEO:

/*

  SELF TRY

  */

  //u just have to find that extra letter of t
//so idea is simple
//put all letters of s in map
//traverse in t ...if it is in map ..go to next .....if it is not...it means this is the extra letter of t....just return it

//tc:o(n)
//sc:o(n)

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        char ans='a';
        for(char &ch:s){
            mp[ch]++;
        }

        for(char &ch:t){
            if(mp.find(ch)==mp.end()){
                ans=ch;
                break;
            }
            else{
                mp[ch]--;
                if(mp[ch]==0)mp.erase(ch);
            }
        }
        return ans;
    }
};
