PROBLEM: https://leetcode.com/problems/determine-if-string-halves-are-alike/

/*
NAIVE APPROACH
time complexity: O(n)
space complexity:O(1)
1.take the size of s ...(remember that it has even length)=n

2.now from index 0 to (n/2)-1 will denote substring a

3.from index n/2 to n-1 will denote substring b

4.we will pass both substrings a and b to some helper function...which will return us the count of vowels in it

5. return true if both the substrings have equal vowel count

*/

class Solution {
private:
  int helpCountVowels(string s,int start,int end){
    int count_vowels=0;
    for(int index=start;index<end ;index++){
      if(s[index]=='a' || s[index]=='e' || s[index]=='i' ||s[index]=='o' ||s[index]=='u' ||s[index]=='A' || s[index]=='E' || s[index]=='I' ||s[index]=='O' || s[index]=='U')
        count_vowels++;
    }
    return count_vowels++;
  }
public:
    bool halvesAreAlike(string s) {
        int total_size=s.size();
        int size_of_each=total_size/2;
        int count_vowels_a=helpCountVowels(s,0,size_of_each);
        int count_vowels_b=helpCountVowels(s,size_of_each,total_size);
      return count_vowels_a==count_vowels_b;
        
    }
};
