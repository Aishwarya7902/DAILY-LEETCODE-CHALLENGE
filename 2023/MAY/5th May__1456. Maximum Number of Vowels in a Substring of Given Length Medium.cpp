PROBLEM:https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

VIDEO:
BLOG:

/*
BRUTE FORCE
1.generate all substring
2.find max no of vowels in that particular substring
3.update ans at every substring
4.return ans

tc:o(n^2)
sc:o(1)
*/



/*
optimisation
using FIXED SIZE sliding window
TC:O(N)
SC:O(1)
*/

class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')return true;

        return false;
    }
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int n=s.size();
        int cnt=0;
        int ans=0;
        while(j<n){
            //calculations
            if(isVowel(s[j]))cnt++;
            //if window  size not hit
            if(j-i+1<k)j++;
            //if window size hits
            else if(j-i+1==k){
                //ans <--calc
                ans=max(ans,cnt);
                //slide the window

                //but but but ......before that....remove ur previous karmic accounts

                if(isVowel(s[i]))cnt--;
                //slide the window
                i++;
                j++;
            }
        }
        return ans;
        
    }
};
