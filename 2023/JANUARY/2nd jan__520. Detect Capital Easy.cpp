PROBLEM:https://leetcode.com/problems/detect-capital/description/
VIDEO:

/*
TC : O(N)
SC:  O(1)
*/

class Solution {
private :
int NoOfCapital(string word){
    int cnt=0;
    for(char &ch:word){
        if(ch>='A' && ch<='Z')cnt++;
    }
    return  cnt;
}
public:
    bool detectCapitalUse(string word) {
        int countCapital=NoOfCapital(word);//function returns no of capital letters in word
        int n=word.size();
        if(countCapital==n)//means all letters are capital
         return true;
       else if(countCapital==0)//all letters are small
         return true;
        else if(countCapital==1 && word[0]>='A' && word[0]<='Z')// only one letter is capital and it is the first letter
        return true;
        else //in all other cases return false
         return false;
        


    }
};
