PROBELEM:https://leetcode.com/problems/string-compression/description/
VIDEO(MAZHAR BHAIYA):https://www.youtube.com/watch?v=I7drewKcN1Y

/*
TC:
SC:
*/

class Solution {
public:
    int compress(vector<char>& chars) {
       int n=chars.size();
       int indx=0;
       int i=0;
       while(i<n){
           char curr_char=chars[i];
           int count=0;
           while(i<n && chars[i]==curr_char){
               count++;
               i++;
           }
           //do assign work
           chars[indx]=curr_char;
           indx++;
           if(count>1){
               string count_str=to_string(count);
               for(char &ch:count_str){
                   chars[indx]=ch;
                   indx++;
               }
           }

       }
       return indx; 
    }
};
