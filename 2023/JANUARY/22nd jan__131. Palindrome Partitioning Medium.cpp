PROBLEM:https://leetcode.com/problems/palindrome-partitioning/description/
VIDEO(MAZHAR BHAIYA):

/*
METHOD 1
Intuition
we search from start till the end of the string. Once we reach a position i such that the sub-string from start to i (s.substr(start, i - start + 1)) 
is a palindrome, we add it to our path variable. Then we recursively call the same method to execute the remaining substring . 
Once we reach the end of the string, we add palindromes path into the result of all the possible partitioning .


Time complexity:
O(n*(2^n)) [n=length of the string]

Space complexity:
O(n) [beacause of recursion stack]
*/

class Solution {
private:
//checks if given string is a palindrome
bool isPalindrome(string &s,int l,int r){
    while(l<r){
        if(s[l++]!=s[r--])
         return false;
        
    }
    return true;
}
void help_Partition(int start,string&s,vector<string>&path,vector<vector<string>>&result){
    int n=s.length();
    if(start==n)
     result.push_back(path);
     else{
         for(int i=start;i<n;i++){
             if(isPalindrome(s,start,i)){
                 path.push_back(s.substr(start,i-start+1));
                 help_Partition(i+1,s,path,result);
                 path.pop_back();
             }
         }
     }
}
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string>path;
        help_Partition(0,s,path,result);
        return result;
    }
};
