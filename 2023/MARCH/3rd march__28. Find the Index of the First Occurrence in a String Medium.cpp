PROBLEM:https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
VIDEO:

/*
tc:
sc:

this can be simply done by making some changes in the stl is_substr , the only change we do is ...if string is not found then we return -1 at the end
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        for(int i=0;i<=m-n;i++){
            int j=0;
            for( ;j<n;j++){
                if(haystack[i+j]!=needle[j])break;
            }
            if(j==n)return i;
        }
    return -1;
    }
};

