PROBLEM:https://leetcode.com/problems/path-crossing/description/?envType=daily-question&envId=2023-12-23
VIDEO:https://www.youtube.com/watch?v=uJaWNFdm2IU

/*
  TC:O(N)
  SC:O(N)
*/

class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0;
        int y=0;
        unordered_set<string>st;
        string key=to_string(x) + "_" + to_string(y);
        st.insert(key);
        for(int i=0;i<path.size();i++){
            if(path[i]=='N')y++;
            else if(path[i]=='S')y--;
            else if(path[i]=='E')x++;
            else x--;
            key=to_string(x) + "_" + to_string(y);
            if(st.find(key)!=st.end())return  true;
            st.insert(key);
        }
        return false;
    }
};
